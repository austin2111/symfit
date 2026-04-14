#include "qemu/osdep.h"
#include "cpu.h"
#include "exec/exec-all.h"
#include "exec/helper-proto.h"
#include "exec/cpu_ldst.h"
#include "qemu/qemu-print.h"
#include "tcg.h"
#include "qemu/cutils.h"
#include "dfsan_interface.h"
#include "symfit-telemetry/symfit_telemetry.h"

static bool demo_set = 0;

static target_ulong get_pc(CPUArchState *env)
{
    target_ulong pc, cs_base;
    uint32_t flags;

    cpu_get_tb_cpu_state(env, &pc, &cs_base, &flags);

    return pc;
}

// For LLM stack monitoring functions:

static inline target_ulong get_stack_pointer(CPUArchState *env);

// Track stack boundaries per-thread
typedef struct {
    target_ulong stack_top;     // Highest address (start of stack)
    target_ulong stack_bottom;  // Lowest address (current SP)
    target_ulong frame_base;    // Current frame pointer (if available)
    bool has_frame_pointer;
} stack_info_t;

static stack_info_t g_stack_info = {0};

#ifdef TARGET_ARM
// Declaration of exception raising function for ARM CPUs
void raise_exception_ra(CPUARMState *env, uint32_t excp, uint32_t syndrome,
                        uint32_t target_el, uintptr_t ra);
#endif

#ifdef CONFIG_2nd_CCACHE
#ifndef CONFIG_USER_ONLY
// System-mode definitions (user-mode has them in linux-user/i386/cpu_loop.c)
int noSymbolicData = 1;
//int second_ccache_flag = 0;
#endif
#endif
#define CONST_LABEL 0

static const uint64_t kShadowMask = ~0x700000000000;
static inline void *shadow_for(uint64_t ptr) {
  return (void *) (((ptr) & kShadowMask) << 2);
}

#define UNIMPLEMENTED_HELPER(opcode)                \
        char op[] = opcode;                         \
        dfsan_unimplemented(op);                    \
        return 0;

#define BINARY_HELPER_ENSURE_EXPRESSIONS                                            \
    if (arg1_label == 0 && arg2_label == 0) {                                       \
        return 0;                                                                   \
    }

#define DECL_HELPER_BINARY(name, bit)                                                 \
    uint64_t HELPER(symsan_##name##_i##bit)(uint##bit##_t arg1, uint64_t arg1_label,  \
                                            uint##bit##_t arg2, uint64_t arg2_label)

#define DEF_HELPER_BINARY(qemu_name, symsan_name, bit)                              \
    DECL_HELPER_BINARY(qemu_name, bit) {                                            \
        BINARY_HELPER_ENSURE_EXPRESSIONS;                                           \
        CPUArchState *env = current_cpu->env_ptr;                                   \
        return dfsan_union(arg1_label, arg2_label, symsan_name, bit, arg1, arg2, get_pc(env) );   \
    }

/* The binary helpers */
DEF_HELPER_BINARY(add, Add, 32)
DEF_HELPER_BINARY(sub, Sub, 32)
DEF_HELPER_BINARY(mul, Mul, 32)
DEF_HELPER_BINARY(div, SDiv, 32)
DEF_HELPER_BINARY(divu, UDiv, 32)
DEF_HELPER_BINARY(rem, SRem, 32)
DEF_HELPER_BINARY(remu, URem, 32)
DEF_HELPER_BINARY(and, And, 32)
DEF_HELPER_BINARY(or, Or, 32)
DEF_HELPER_BINARY(xor, Xor, 32)
DEF_HELPER_BINARY(shift_right, LShr, 32)
DEF_HELPER_BINARY(arithmetic_shift_right, AShr, 32)
DEF_HELPER_BINARY(shift_left, Shl, 32)

DEF_HELPER_BINARY(add, Add, 64)
DEF_HELPER_BINARY(sub, Sub, 64)
DEF_HELPER_BINARY(mul, Mul, 64)
DEF_HELPER_BINARY(div, SDiv, 64)
DEF_HELPER_BINARY(divu, UDiv, 64)
DEF_HELPER_BINARY(rem, SRem, 64)
DEF_HELPER_BINARY(remu, URem, 64)
DEF_HELPER_BINARY(and, And, 64)
DEF_HELPER_BINARY(or, Or, 64)
DEF_HELPER_BINARY(xor, Xor, 64)
DEF_HELPER_BINARY(shift_right, LShr, 64)
DEF_HELPER_BINARY(arithmetic_shift_right, AShr, 64)
DEF_HELPER_BINARY(shift_left, Shl, 64)

DECL_HELPER_BINARY(rotate_left, 32)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    // UNIMPLEMENTED_HELPER("rotate_left32")
    // arg1 << arg2 | arg1 >> (32 - arg2)
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t shl = dfsan_union(arg1_label, arg2_label, Shl, 32, arg1, arg2, get_pc(env));
    uint32_t tmp = dfsan_union(CONST_LABEL, arg2_label, Sub, 32, 32, arg2, get_pc(env));
    uint32_t lshr = dfsan_union(arg1_label, tmp, LShr, 32, arg1, 32-arg2, get_pc(env));
    return dfsan_union(shl, lshr, Or, 32, arg1 << arg2, arg1 >> (32 - arg2), get_pc(env));
}
DECL_HELPER_BINARY(rotate_left, 64)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    // UNIMPLEMENTED_HELPER("rotate_left64")
    // arg1 << arg2 | arg1 >> (64 - arg2)
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t shl = dfsan_union(arg1_label, arg2_label, Shl, 64, arg1, arg2, get_pc(env));
    uint32_t tmp = dfsan_union(CONST_LABEL, arg2_label, Sub, 64, 64, arg2, get_pc(env));
    uint32_t lshr = dfsan_union(arg1_label, tmp, LShr, 64, arg1, 64-arg2, get_pc(env));
    return dfsan_union(shl, lshr, Or, 64, arg1 << arg2, arg1 >> (64 - arg2), get_pc(env));
}
DECL_HELPER_BINARY(rotate_right, 32)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    // UNIMPLEMENTED_HELPER("rotate_right32")
    // arg1 >> arg2 | arg1 << (32 - arg2)
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t lshr = dfsan_union(arg1_label, arg2_label, LShr, 32, arg1, arg2, get_pc(env));
    uint32_t tmp = dfsan_union(CONST_LABEL, arg2_label, Sub, 32, 32, arg2, get_pc(env));
    uint32_t shl = dfsan_union(arg1_label, tmp, Shl, 32, arg1, 32-arg2, get_pc(env));
    return dfsan_union(lshr, shl, Or, 32, arg1 >> arg2, arg1 << (32 - arg2), get_pc(env));
}
DECL_HELPER_BINARY(rotate_right, 64)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    // UNIMPLEMENTED_HELPER("rotate_right64")
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t lshr = dfsan_union(arg1_label, arg2_label, LShr, 64, arg1, arg2, get_pc(env));
    uint32_t tmp = dfsan_union(CONST_LABEL, arg2_label, Sub, 64, 64, arg2, get_pc(env));
    uint32_t shl = dfsan_union(arg1_label, tmp, Shl, 64, arg1, 64-arg2, get_pc(env));
    return dfsan_union(lshr, shl, Or, 64, arg1 >> arg2, arg1 << (64 - arg2), get_pc(env));
}

DECL_HELPER_BINARY(nand, 32)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(CONST_LABEL,
                        dfsan_union(arg1_label, arg2_label, And, 32, arg1, arg2, get_pc(env)),
                        Not,
                        32,
                        0, 0, get_pc(env));
}
DECL_HELPER_BINARY(nand, 64)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(CONST_LABEL,
                        dfsan_union(arg1_label, arg2_label, And, 64, arg1, arg2, get_pc(env)),
                        Not,
                        64,
                        0, 0, get_pc(env));
}

DECL_HELPER_BINARY(nor, 32)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(CONST_LABEL,
                        dfsan_union(arg1_label, arg2_label, Or, 32, arg1, arg2, get_pc(env)),
                        Not,
                        32,
                        0, 0, get_pc(env));
}
DECL_HELPER_BINARY(nor, 64)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(CONST_LABEL,
                        dfsan_union(arg1_label, arg2_label, Or, 64, arg1, arg2, get_pc(env)),
                        Not,
                        64,
                        0, 0, get_pc(env));
}

DECL_HELPER_BINARY(orc, 32)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(arg1_label,
                       dfsan_union(arg2_label, CONST_LABEL, Not, 32, arg2, 0, get_pc(env)),
                       Or,
                       32,
                       arg1, arg2, get_pc(env));
}
DECL_HELPER_BINARY(orc, 64)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(arg1_label,
                       dfsan_union(arg2_label, CONST_LABEL, Not, 64, arg2, 0, get_pc(env)),
                       Or,
                       64,
                       arg1, arg2, get_pc(env));
}

/* andc support */
DECL_HELPER_BINARY(andc, 32)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(arg1_label,
                       dfsan_union(arg2_label, CONST_LABEL, Not, 32, arg2, 0, get_pc(env)),
                       And,
                       32,
                       arg1, arg2, get_pc(env));
}
DECL_HELPER_BINARY(andc, 64)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(arg1_label,
                       dfsan_union(arg2_label, CONST_LABEL, Not, 64, arg2, 0, get_pc(env)),
                       And,
                       64,
                       arg1, arg2, get_pc(env));
}
/* eqv support */
DECL_HELPER_BINARY(eqv, 32)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(dfsan_union(arg1_label, arg2_label, Xor, 32, arg1, arg2, get_pc(env)),
                       CONST_LABEL,
                       Not,
                       32,
                       0, 0, get_pc(env));
}

DECL_HELPER_BINARY(eqv, 64)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(dfsan_union(arg1_label, arg2_label, Xor, 64, arg1, arg2, get_pc(env)),
                       CONST_LABEL,
                       Not,
                       64,
                       0, 0, get_pc(env));
}

uint64_t HELPER(symsan_neg_i32)(uint32_t op1, uint64_t label)
{
    if (label == 0)
        return 0;
    CPUArchState *env = current_cpu->env_ptr;
    /* for unary operator Neg/Not, leave the first op as 0 */
    return dfsan_union(CONST_LABEL, label, Neg, 32, 0, op1, get_pc(env));
}
uint64_t HELPER(symsan_neg_i64)(uint64_t op1, uint64_t label)
{
    if (label == 0)
        return 0;
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(CONST_LABEL, label, Neg, 64, 0, op1, get_pc(env));
}

uint64_t HELPER(symsan_not_i32)(uint32_t op1, uint64_t label)
{
    if (label == 0)
        return 0;
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(CONST_LABEL, label, Not, 32, 0, op1, get_pc(env));
}
uint64_t HELPER(symsan_not_i64)(uint64_t op1, uint64_t label)
{
    if (label == 0)
        return 0;
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(CONST_LABEL, label, Not, 64, 0, op1, get_pc(env));
}

uint64_t HELPER(symsan_muluh_i64)(uint64_t arg1, uint64_t arg1_label,
                                  uint64_t arg2, uint64_t arg2_label)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t arg1_new = dfsan_union(arg1_label, CONST_LABEL, ZExt, 64, arg1, 64, get_pc(env));
    uint64_t arg2_new = dfsan_union(arg2_label, CONST_LABEL, ZExt, 64, arg2, 64, get_pc(env));
    uint64_t res = dfsan_union(arg1_new, arg2_new, Mul, 64, arg1, arg2, get_pc(env));
    return dfsan_union(res,
                       CONST_LABEL,
                       Extract,
                       64,
                       127,
                       64, get_pc(env));
}

/* z/sext_i32/64 is not real ext operation. */
uint64_t HELPER(symsan_sext_i32)(uint32_t op1, uint64_t op1_label, uint64_t ext_bit)
{
    if (op1_label == 0) return 0; /* op2 label is alway zero */
    size_t bits_to_keep = 32 - ext_bit;
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t tmp = dfsan_union(op1_label, CONST_LABEL, Shl, 32, op1, bits_to_keep, get_pc(env));
    return dfsan_union(tmp, CONST_LABEL, AShr, 32, op1 << bits_to_keep, bits_to_keep, get_pc(env));
}
uint64_t HELPER(symsan_sext_i64)(uint64_t op1, uint64_t op1_label, uint64_t ext_bit)
{
    if (op1_label == 0) return 0; /* op2 label is alway zero */
    size_t bits_to_keep = 64 - ext_bit;
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t tmp = dfsan_union(op1_label, CONST_LABEL, Shl, 64, op1, bits_to_keep, get_pc(env));
    return dfsan_union(tmp, CONST_LABEL, AShr, 64, op1 << bits_to_keep, bits_to_keep, get_pc(env));
}

uint64_t HELPER(symsan_zext_i32)(uint32_t op1, uint64_t op1_label, uint64_t ext_bit)
{
    if (op1_label == 0) return 0; /* op2 label is alway zero */
    CPUArchState *env = current_cpu->env_ptr;
    // bitwise and
    return dfsan_union(op1_label, CONST_LABEL, And, 32, op1, (1ull << ext_bit) - 1, get_pc(env));
}
uint64_t HELPER(symsan_zext_i64)(uint64_t op1, uint64_t op1_label, uint64_t ext_bit)
{
    if (op1_label == 0) return 0; /* op2 label is alway zero */
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(op1_label, CONST_LABEL, And, 64, op1, (1ull << ext_bit) - 1, get_pc(env));
}

/* *ext_i32_i64 equals to the ext operation in z3 */
uint64_t HELPER(symsan_zext_i32_i64)(uint32_t op1, uint64_t op1_label)
{
    if (op1_label == 0) return 0; /* op2 label is alway zero */
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(op1_label, CONST_LABEL, ZExt, 64, op1, 32, get_pc(env)); // extend by 32 bits.
}
uint64_t HELPER(symsan_sext_i32_i64)(uint32_t op1, uint64_t op1_label)
{
    if (op1_label == 0) return 0; /* op2 label is alway zero */
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(op1_label, CONST_LABEL, SExt, 64, op1, 32, get_pc(env)); // extend by 32 bits.
}

/* Truncate a 64-bit value to 32-bit */
uint64_t HELPER(symsan_trunc_i64_i32)(uint64_t op1, uint64_t op1_label)
{
    if (op1_label == 0) return 0;
    // Result is 32-bit.
    CPUArchState *env = current_cpu->env_ptr;
    return dfsan_union(op1_label, CONST_LABEL, Trunc, 32, op1, 32, get_pc(env));
}
// https://github.com/chenju2k6/symsan/commit/3392e5b1d33b8ac6e350eeefb37ae861848ba9b2
// bswap support
uint64_t HELPER(symsan_bswap_i32)(uint32_t op1, uint64_t op1_label, uint64_t length)
{
    if (op1_label == 0) return 0;
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t arg1, arg2, tmp, tmp1, tmp2, first_block, second_block;
    switch (length) {
        case 2:
            arg1 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, ZExt, 64, op1, 1, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                8,
                get_pc(env));
            arg2 = dfsan_union(
                op1_label,
                CONST_LABEL,
                LShr,
                64,
                op1,
                8,
                get_pc(env));
            return dfsan_union(arg1, arg2, Or, 64, 0, 0, get_pc(env));
        case 4:
            tmp = dfsan_union(op1_label, CONST_LABEL, LShr, 64, op1, 8, get_pc(env));
            arg1 = dfsan_union(
                tmp,
                CONST_LABEL,
                And,
                64,
                op1,
                0x00ff00ff,
                get_pc(env)
            );
            arg2 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, And, 64, op1, 0x00ff00ff, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                8,
                get_pc(env)
            );
            first_block = dfsan_union(arg1, arg2, Or, 64, 0, 0, get_pc(env));
            tmp1 = dfsan_union(first_block, CONST_LABEL, LShr, 64, op1, 16, get_pc(env));
            tmp2 = dfsan_union(first_block, CONST_LABEL, Shl, 64, op1, 16, get_pc(env));
            return dfsan_union(tmp1, tmp2, Or, 64, 0, 0, get_pc(env));
        case 8:
            tmp1 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, LShr, 64, op1, 8, get_pc(env)),
                CONST_LABEL,
                And,
                64,
                op1,
                0x00ff00ff00ff00ffull,
                get_pc(env)
            );
            tmp2 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, And, 64, op1, 0x00ff00ff00ff00ffull, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                8,
                get_pc(env)
            );
            first_block = dfsan_union(tmp1, tmp2, Or, 64, 0, 0, get_pc(env));
            tmp1 = dfsan_union(
                dfsan_union(first_block, CONST_LABEL, LShr, 64, op1, 16, get_pc(env)),
                CONST_LABEL,
                And,
                64,
                op1,
                0x0000ffff0000ffffull,
                get_pc(env)
            );
            tmp2 = dfsan_union(
                dfsan_union(first_block, CONST_LABEL, And, 64, op1, 0x0000ffff0000ffffull, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                16,
                get_pc(env)
            );
            second_block = dfsan_union(tmp1, tmp2, Or, 64, 0, 0, get_pc(env));
            return dfsan_union(
                dfsan_union(
                    second_block,
                    CONST_LABEL,
                    LShr,
                    64,
                    op1,
                    32,
                    get_pc(env)
                ),
                dfsan_union(
                    second_block,
                    CONST_LABEL,
                    Shl,
                    64,
                    op1,
                    32,
                    get_pc(env)
                ),
                Or,
                64,
                0,
                0,
                get_pc(env)
            );
        default:
            g_assert_not_reached();
    }
}

uint64_t HELPER(symsan_bswap_i64)(uint64_t op1, uint64_t op1_label, uint64_t length)
{
    if (op1_label == 0) return 0;
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t arg1, arg2, tmp, tmp1, tmp2, first_block, second_block;
    switch (length) {
        case 2:
            arg1 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, ZExt, 64, op1, 1, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                8,
                get_pc(env));
            arg2 = dfsan_union(
                op1_label,
                CONST_LABEL,
                LShr,
                64,
                op1,
                8,
                get_pc(env));
            return dfsan_union(arg1, arg2, Or, 64, 0, 0, get_pc(env));
        case 4:
            tmp = dfsan_union(op1_label, CONST_LABEL, LShr, 64, op1, 8, get_pc(env));
            arg1 = dfsan_union(
                tmp,
                CONST_LABEL,
                And,
                64,
                op1,
                0x00ff00ff,
                get_pc(env)
            );
            arg2 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, And, 64, op1, 0x00ff00ff, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                8,
                get_pc(env)
            );
            first_block = dfsan_union(arg1, arg2, Or, 64, 0, 0, get_pc(env));
            tmp1 = dfsan_union(first_block, CONST_LABEL, LShr, 64, op1, 16, get_pc(env));
            tmp2 = dfsan_union(
                dfsan_union(first_block, CONST_LABEL, Shl, 64, op1, 48, get_pc(env)),
                CONST_LABEL,
                LShr,
                64,
                op1,
                32,
                get_pc(env)
            );
            return dfsan_union(tmp1, tmp2, Or, 64, 0, 0, get_pc(env));
        case 8:
            tmp1 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, LShr, 64, op1, 8, get_pc(env)),
                CONST_LABEL,
                And,
                64,
                op1,
                0x00ff00ff00ff00ffull,
                get_pc(env)
            );
            tmp2 = dfsan_union(
                dfsan_union(op1_label, CONST_LABEL, And, 64, op1, 0x00ff00ff00ff00ffull, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                8,
                get_pc(env)
            );
            first_block = dfsan_union(tmp1, tmp2, Or, 64, 0, 0, get_pc(env));
            tmp1 = dfsan_union(
                dfsan_union(first_block, CONST_LABEL, LShr, 64, op1, 16, get_pc(env)),
                CONST_LABEL,
                And,
                64,
                op1,
                0x0000ffff0000ffffull,
                get_pc(env)
            );
            tmp2 = dfsan_union(
                dfsan_union(first_block, CONST_LABEL, And, 64, op1, 0x0000ffff0000ffffull, get_pc(env)),
                CONST_LABEL,
                Shl,
                64,
                op1,
                16,
                get_pc(env)
            );
            second_block = dfsan_union(tmp1, tmp2, Or, 64, 0, 0, get_pc(env));
            return dfsan_union(
                dfsan_union(
                    second_block,
                    CONST_LABEL,
                    LShr,
                    64,
                    op1,
                    32,
                    get_pc(env)
                ),
                dfsan_union(
                    second_block,
                    CONST_LABEL,
                    Shl,
                    64,
                    op1,
                    32,
                    get_pc(env)
                ),
                Or,
                64,
                0,
                0,
                get_pc(env)
            );
        default:
            g_assert_not_reached();
    }
}

/* Extract syntax
    dfsan_union(label, CONST_LABEL, Extract, 8, 0, i * 8);
    size = 8
    op2 = offset (bit-wise)
    Extract one byte (8-bit) from a 8-byte value
    extract2_i32/i64 can be handled by extract_i32/i64, the len is fixed (32 or 64).
    sextract_i32/i64 is also handled by extract_i32/i64 now. Maybe need a FIXME.
 */
uint64_t HELPER(symsan_extract_i32)(uint32_t arg, uint64_t arg_label, uint32_t ofs, uint32_t len)
{
    if (arg_label == 0) return 0;
    /* len is the extract length.
       ofs is the offset to start extract.
     */
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t out = dfsan_union(arg_label, CONST_LABEL, Extract, 32, ofs + len - 1, ofs, get_pc(env));
    return dfsan_union(out, CONST_LABEL, ZExt, 32, 0, 32 - len, get_pc(env));
}
uint64_t HELPER(symsan_extract_i64)(uint64_t arg, uint64_t arg_label, uint64_t ofs, uint64_t len)
{
    if (arg_label == 0) return 0;
    /* len is the extract length.
       ofs is the offset to start extract.
     */
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t out = dfsan_union(arg_label, CONST_LABEL, Extract, 64, ofs + len - 1, ofs, get_pc(env));
    return dfsan_union(out, CONST_LABEL, ZExt, 64, 0, 64 - len, get_pc(env));
}

uint64_t HELPER(symsan_sextract_i32)(uint32_t arg, uint64_t arg_label, uint32_t ofs, uint32_t len)
{
    if (arg_label == 0) return 0;
    /* len is the extract length.
       ofs is the offset to start extract.
     */
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t out = dfsan_union(arg_label, CONST_LABEL, Extract, 32, ofs + len - 1, ofs, get_pc(env));
    return dfsan_union(out, CONST_LABEL, SExt, 32, 0, 32 - len, get_pc(env));
}
uint64_t HELPER(symsan_sextract_i64)(uint64_t arg, uint64_t arg_label, uint64_t ofs, uint64_t len)
{
    if (arg_label == 0) return 0;
    /* len is the extract length.
       ofs is the offset to start extract.
     */
    CPUArchState *env = current_cpu->env_ptr;
    uint32_t out = dfsan_union(arg_label, CONST_LABEL, Extract, 64, ofs + len - 1, ofs, get_pc(env));
    return dfsan_union(out, CONST_LABEL, SExt, 64, 0, 64 - len, get_pc(env));
}

uint64_t HELPER(symsan_deposit_i32)(uint32_t arg1, uint64_t arg1_label,
                              uint32_t arg2, uint64_t arg2_label,
                              uint32_t ofs, uint32_t len)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    /* The symbolic implementation follows the alternative concrete
     * implementation of tcg_gen_deposit_i64 in tcg-op.c (which handles
     * architectures that don't support deposit directly). */
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t mask = (1ull << len) - 1;
    uint64_t arg1_new_label = dfsan_union(arg1_label, CONST_LABEL, And, 32, arg1, ~(mask << ofs), get_pc(env));
    uint64_t arg2_new_label = dfsan_union(arg2_label, CONST_LABEL, And, 32, arg2, mask, get_pc(env));
    arg2_new_label = dfsan_union(arg2_new_label, CONST_LABEL, Shl, 32, arg2 & mask, ofs, get_pc(env));
    return dfsan_union(arg1_new_label, arg2_new_label, Or, 32, arg1 & ~(mask << ofs), (arg2 & mask) << ofs, get_pc(env));
}

uint64_t HELPER(symsan_deposit_i64)(uint64_t arg1, uint64_t arg1_label,
                              uint64_t arg2, uint64_t arg2_label,
                              uint64_t ofs, uint64_t len)
{
    BINARY_HELPER_ENSURE_EXPRESSIONS
    /* The symbolic implementation follows the alternative concrete
     * implementation of tcg_gen_deposit_i64 in tcg-op.c (which handles
     * architectures that don't support deposit directly). */
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t mask = (1ull << len) - 1;
    uint64_t arg1_new_label = dfsan_union(arg1_label, CONST_LABEL, And, 64, arg1, ~(mask << ofs), get_pc(env));
    uint64_t arg2_new_label = dfsan_union(arg2_label, CONST_LABEL, And, 64, arg2, mask, get_pc(env));
    arg2_new_label = dfsan_union(arg2_new_label, CONST_LABEL, Shl, 64, arg2 & mask, ofs, get_pc(env));
    return dfsan_union(arg1_new_label, arg2_new_label, Or, 64, arg1 & ~(mask << ofs), (arg2 & mask) << ofs, get_pc(env));
}

uint64_t HELPER(symsan_extract2_i32)(uint32_t ah, uint64_t ah_label,
                                     uint32_t al, uint64_t al_label,
                                     uint64_t ofs)
{
    if (ah_label == 0 && al_label == 0)
        return 0;

    /* The implementation follows the alternative implementation of
     * tcg_gen_extract2_i32 in tcg-op.c (which handles architectures that don't
     * support extract2 directly). */

    if (ofs == 0)
        return al_label;
    if (ofs == 32)
        return ah_label;
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t al_new = dfsan_union(al_label, CONST_LABEL, LShr, 32, al, ofs, get_pc(env));
    return HELPER(symsan_deposit_i32)(al >> ofs, al_new, ah, ah_label, 32-ofs, ofs);
}

uint64_t HELPER(symsan_extract2_i64)(uint64_t ah, uint64_t ah_label,
                                     uint64_t al, uint64_t al_label,
                                     uint64_t ofs)
{
    if (ah_label == 0 && al_label == 0)
        return 0;

    /* The implementation follows the alternative implementation of
     * tcg_gen_extract2_i64 in tcg-op.c (which handles architectures that don't
     * support extract2 directly). */

    if (ofs == 0)
        return al_label;
    if (ofs == 64)
        return ah_label;
    CPUArchState *env = current_cpu->env_ptr;
    uint64_t al_new = dfsan_union(al_label, CONST_LABEL, LShr, 64, al, ofs, get_pc(env));
    return HELPER(symsan_deposit_i64)(al >> ofs, al_new, ah, ah_label, 64-ofs, ofs);
}

static uint64_t symsan_setcond_internal(CPUArchState *env, uint64_t arg1, uint64_t arg1_label,
                                  uint64_t arg2, uint64_t arg2_label,
                                  int32_t cond, uint64_t result, uint8_t result_bits)
{
    // if (!noSymbolicData)
    // fprintf(stderr, "setcond_i%d push constraint eip: 0x%lx %s arg1: 0x%ld arg2: 0x%ld\n",
    //          result_bits, env->eip, (arg1_label == 0 && arg2_label == 0) ? "Concrete" : "Symbolic",
    //          arg1, arg2);

    BINARY_HELPER_ENSURE_EXPRESSIONS;

    uint32_t predicate = 0;
    switch (cond) {
    case TCG_COND_EQ:
        predicate = bveq;
        break;
    case TCG_COND_NE:
        predicate = bvneq;
        break;
    case TCG_COND_LT:
        predicate = bvslt;
        break;
    case TCG_COND_GE:
        predicate = bvsge;
        break;
    case TCG_COND_LE:
        predicate = bvsle;
        break;
    case TCG_COND_GT:
        predicate = bvsgt;
        break;
    case TCG_COND_LTU:
        predicate = bvult;
        break;
    case TCG_COND_GEU:
        predicate = bvuge;
        break;
    case TCG_COND_LEU:
        predicate = bvule;
        break;
    case TCG_COND_GTU:
        predicate = bvugt;
        break;
    default:
        g_assert_not_reached();
    }

    //return __taint_trace_cmp(arg1_label, arg2_label, result_bits, result, predicate, arg1, arg2, env->eip);
    // Changed to architecture-independent program counter
    return __taint_trace_cmp(arg1_label, arg2_label, result_bits, result, predicate, arg1, arg2, get_pc(env));
}

uint64_t HELPER(symsan_setcond_i32)(CPUArchState *env, uint32_t arg1, uint64_t arg1_label,
                              uint32_t arg2, uint64_t arg2_label,
                              int32_t cond, uint32_t result)
{
    return symsan_setcond_internal(env, arg1, arg1_label, arg2, arg2_label, cond, result, 32);
}

uint64_t HELPER(symsan_setcond_i64)(CPUArchState *env, uint64_t arg1, uint64_t arg1_label,
                              uint64_t arg2, uint64_t arg2_label,
                              int32_t cond, uint64_t result)
{
    return symsan_setcond_internal(env, arg1, arg1_label, arg2, arg2_label, cond, result, 64);
}


static inline bool is_stack_addr(target_ulong addr, CPUArchState *env) {
    target_ulong sp = get_stack_pointer(env);
    
    if (sp == 0) return false;  // Invalid SP
    
    // Stack typically occupies ~1-2MB max per thread
    // Check if addr is within reasonable distance of CURRENT SP
    const target_ulong MAX_STACK_SIZE = 0x200000;  // 2MB max
    
    // For x86-64 kernel, stack grows DOWN from high to low addresses
    // So valid stack addresses are: (SP - MAX_STACK_SIZE) to (SP + small_offset)
    return (addr >= sp - MAX_STACK_SIZE && addr <= sp + 0x10000);
}

/* For any stack analysis we might happen to do in symbolic execution.  *
 * A number of architectures are covered here to encourage all analysis *
 * techniques to be architecture-agnostic.                              */

static inline target_ulong get_stack_pointer(CPUArchState *env) {
#if defined(TARGET_X86_64)
    return env->regs[R_ESP];  // RSP
#elif defined(TARGET_I386)
    return env->regs[R_ESP];  // ESP
#elif defined(TARGET_ARM)
    return env->regs[13];     // R13 (SP)
#elif defined(TARGET_AARCH64)
    return env->xregs[31];    // SP (X31)
#elif defined(TARGET_PPC) || defined(TARGET_PPC64)
    return env->gpr[1];       // R1 (SP)
#elif defined(TARGET_MIPS) || defined(TARGET_MIPS64)
    return env->active_tc.gpr[29];  // $sp ($29)
#elif defined(TARGET_SPARC) || defined(TARGET_SPARC64)
    return env->regwptr[14];  // %sp (%o6/%i6)
#else
    // Insert your architecture here
    #warning "Stack pointer not defined for this architecture"
    return 0;
#endif
}

static inline target_ulong get_frame_pointer(CPUArchState *env) {
#if defined(TARGET_X86_64) || defined(TARGET_I386)
    return env->regs[R_EBP];  // RBP/EBP
#elif defined(TARGET_ARM)
    return env->regs[11];     // R11 (FP) - by convention, not guaranteed
#elif defined(TARGET_AARCH64)
    return env->xregs[29];    // X29 (FP)
#elif defined(TARGET_PPC) || defined(TARGET_PPC64)
    return env->gpr[1];       // R1 also used as frame base (same as SP)
#elif defined(TARGET_MIPS) || defined(TARGET_MIPS64)
    return env->active_tc.gpr[30];  // $fp ($30) - if used
#elif defined(TARGET_SPARC) || defined(TARGET_SPARC64)
    return env->regwptr[30];  // %fp (%i6)
#else
    return 0;
#endif
}

void check_guest_taint(target_ulong guest_addr, uint64_t load_length) {

/*    
CPUState *cpu = current_cpu;
    if (!cpu) {
        printf("[TAINT_CHECK] No CPU context\n");
        return;
    }
    
    CPUArchState *env = cpu->env_ptr;
*/

    CPUState *cpu = current_cpu;
    if (!cpu) {
        cpu = qemu_get_cpu(0);  // Fallback for GDB context
    }
    if (!cpu) {
        printf("ERROR: Couldn't get valid CPU struct!\n");
        return;
    }

    CPUArchState *env = cpu->env_ptr;    
    // Translate guest virtual to host
    void *host_addr = tlb_vaddr_to_host(env, guest_addr, MMU_DATA_LOAD, 0); // TO DO: Do we need to be using another MMU index for kernel addresses?
    if (!host_addr) {
        printf("[TAINT_CHECK] addr=0x%lx: Translation failed (not mapped)\n", guest_addr);
        return;
    }
    
    //printf("DEBUG: tlb_vaddr_to_host returned host address %p!\n", host_addr);
    
    // Check shadow memory
    dfsan_label label = dfsan_read_label((uint8_t*)host_addr, load_length);
    
    // Get FP offset for context
    target_ulong fp = get_frame_pointer(env);
    target_ulong sp = get_stack_pointer(env);
    int64_t fp_offset = (int64_t)guest_addr - (int64_t)fp;
    int64_t sp_offset = (int64_t)guest_addr - (int64_t)sp;
    
    printf("[TAINT_CHECK] addr=0x%lx\n", guest_addr);
    printf("  host_addr=%p\n", host_addr);
    printf("  FP%s0x%llx SP%s0x%llx\n",
           (fp_offset >= 0) ? "+" : "-", (unsigned long long)abs(fp_offset),
           (sp_offset >= 0) ? "+" : "-", (unsigned long long)abs(sp_offset));
    printf("  label=%u\n", label);
    printf("  tainted=%s\n", (label != 0) ? "YES" : "NO");
    
    if (label != 0) {
        printf("  [Use print_constraint(%u) to see expression]\n", label);
    }
}

/* Guest memory opreation */
// TO DO: Replace CPUArchState in the calling convention with CPUState?
static uint64_t symsan_load_guest_internal(CPUArchState *env, target_ulong addr, uint64_t addr_label,
                                     uint64_t load_length, uint8_t result_length, uint64_t mmu_idx)
{
    void *host_addr = tlb_vaddr_to_host(env, addr, MMU_DATA_LOAD, mmu_idx);
    /*
    if ((uintptr_t)host_addr < 0x700000040000) {
        printf("WARNING: symsan_load_guest_internal() returned address above 0x700000040000! PC: 0x%lx, Host address: %p, Guest Address: 0x%lx, MMU index: %ld\n", get_pc(env), host_addr, addr, mmu_idx);
    }
    */
    //void *host_addr = tlb_vaddr_to_host(env, addr, MMU_DATA_LOAD, mmu_idx);
    //void *host_addr = g2h(addr);
    if (host_addr == NULL) return 0; // No dfsan label associated with a null address
    if (addr_label) {
        fprintf(stderr, "DEBUG: sym load addr 0x%lx eip 0x%lx\n", addr, get_pc(env));
        dfsan_label addr_label_new = \
            // Changed addr to host_addr in dfsan_union
            dfsan_union(addr_label, CONST_LABEL, Equal, 64, (target_ulong) host_addr, 0, get_pc(env));
        __taint_trace_cmp(addr_label_new, CONST_LABEL, 64, true, Equal, 0, 0, get_pc(env));
    }
    //uint64_t res_label = dfsan_read_label((uint8_t*)host_addr, load_length);
    uint64_t res_label = (uint32_t)dfsan_read_label((uint8_t*)host_addr, load_length); // Bugfix test for type confusion
    if (qemu_loglevel_mask(CPU_LOG_SYM_LDST_GUEST) && !noSymbolicData) {
        fprintf(stderr, "[memtrace:symbolic]op: load_guest_i%d addr: 0x%lx host_addr: %p size: %ld memory_expr: %ld\n",
                     result_length*8, addr, host_addr, load_length, res_label);
    }
    if (res_label != 0) {
        // This is a symbolic load
    
        if (is_stack_addr(addr, env)) {
            target_ulong sp = get_stack_pointer(env);
            target_ulong fp = get_frame_pointer(env);
            int64_t sp_offset = (int64_t)addr - (int64_t)sp;
            int64_t fp_offset = (int64_t)addr - (int64_t)fp;
            if (telemetry_enabled) {
                char jsonbuffer[512];
                snprintf(jsonbuffer, sizeof(jsonbuffer) - 1,
                    "{"
                    "\"source\": \"qemu\","
                    "\"trigger\": \"symbolic_load\","
                    "\"addr\": \"0x%lx\","
                    "\"sp\": \"%s0x%llx\","
                    "\"fp\": \"%s0x%llx\","
                    "\"label\": %lu,"
                    "\"size\": %ld,"
                    "\"pc\": \"0x%llx\""
                    "}",
                addr,
                (sp_offset >= 0) ? "+" : "-", (unsigned long long)abs(sp_offset),
                (fp_offset >= 0) ? "+" : "-", (unsigned long long)abs(fp_offset),
                res_label, load_length, get_pc(env));
                telemetry_send(jsonbuffer);
            }
            // Disable the check first for sanity
            //if (abs(fp_offset) < 0x10000 || abs(sp_offset) < 0x10000) {
                fprintf(stderr, "[SYMBOLIC_LOAD] addr=0x%lx SP%s0x%llx FP%s0x%llx label=%lu size=%ld PC=0x%llx\n",
                        addr, (sp_offset >= 0) ? "+" : "-", (unsigned long long) abs(sp_offset), (fp_offset >=0) ? "+" : "-", (unsigned long long) abs(fp_offset), res_label, load_length, get_pc(env));
            //}
        }
    }
    return res_label;
}

uint64_t HELPER(symsan_load_guest_i32)(CPUArchState *env, target_ulong addr, uint64_t addr_label,
                                 uint64_t length, uint64_t mmu_idx)
{
    return symsan_load_guest_internal(env, addr, addr_label, length, 4, mmu_idx);
}

uint64_t HELPER(symsan_load_guest_i64)(CPUArchState *env, target_ulong addr, uint64_t addr_label,
                                 uint64_t length, uint64_t mmu_idx)
{
    return symsan_load_guest_internal(env, addr, addr_label, length, 8, mmu_idx);
}


static uint64_t symsan_load_host_internal(void *addr, uint64_t offset,
                                    uint64_t load_length, uint64_t result_length)
{
    //assert((uintptr_t)addr+offset >= 0x700000040000); // Changed to warning for Android experiment
    if ((uintptr_t)addr+offset < 0x700000040000) {
        printf("WARNING: symsan_load_host_internal() address is less than 0x700000040000! (0x%lx) Called by: %p\n", (uintptr_t)addr+offset, __builtin_return_address(0));
    }
    //uint64_t res_label = dfsan_read_label((uint8_t*)addr + offset, load_length);
    uint64_t raw_res = (uint64_t)dfsan_read_label((uint8_t*)addr + offset, load_length);
    
    // 2. FORCE clear the top 32 bits. 
    // If the "radioactive" pointer disappears, we found the mismatch.
    uint64_t res_label = raw_res & 0xFFFFFFFFULL; 

    // This will now show '9' or '18' instead of '93824997963111'
    //fprintf(stderr, "DEBUG: Final symsan_load_host_internal label: %lu\n", res_label);

    if (qemu_loglevel_mask(CPU_LOG_SYM_LDST_HOST) && !noSymbolicData) {
        fprintf(stderr, "[memtrace:symbolic]op: load_host_i%ld addr: %p size: %ld memory_expr: %ld\n",
                     result_length*8, addr+offset, load_length, res_label);
    }
    return res_label;
}

uint64_t HELPER(symsan_load_host_i32)(void *addr, uint64_t offset, uint64_t length)
{
    return symsan_load_host_internal(addr, offset, length, 4);
}

uint64_t HELPER(symsan_load_host_i64)(void *addr, uint64_t offset, uint64_t length)
{
    return symsan_load_host_internal(addr, offset, length, 8);
}

static void symsan_store_guest_internal(CPUArchState *env, uint64_t value_label,
                                     target_ulong addr, uint64_t addr_label, uint64_t length, uint64_t mmu_idx)
{
    if (qemu_loglevel_mask(CPU_LOG_SYM_LDST_GUEST) && !noSymbolicData) {
        fprintf(stderr, "[memtrace:symbolic]op: store_guest_i%ld addr: 0x%lx size: %ld value_expr: %ld\n",
                     length*8, addr, length, value_label);
    }
    // TO DO: Is storing based on host_addr here valid? If not, move tlb_vaddr_to_host() back down below the if (addr_label) statement and replace host_addr in dfsan_union() with addr
    void *host_addr = tlb_vaddr_to_host(env, addr, MMU_DATA_STORE, mmu_idx);
    if ((uintptr_t)host_addr < 0x700000040000) {
        printf("WARNING: symsan_store_guest_internal() returned address above 0x700000040000! PC: 0x%lx, Host address: %p, Guest Address: 0x%lx, MMU index: %ld\n", get_pc(env), host_addr, addr, mmu_idx);
        return;
    }
    if ((uintptr_t)host_addr == 0x7fffb4e4c420) {
        printf("XLA: 0x7fffb4e4c420 store from guest address 0x%lx, guest program counter 0x%lx\n", addr, get_pc(env));
    }
    //void *host_addr = tlb_vaddr_to_host(env, addr, MMU_DATA_STORE, mmu_idx);
    //void *host_addr = g2h(addr);
    if (host_addr == NULL) return; // Don't store labels for a null address
    if (value_label != 0 && is_stack_addr(addr, env)) {
        // TO DO: Should this only work within a limited range of the stack?
        target_ulong fp = get_frame_pointer(env);
        target_ulong sp = get_stack_pointer(env);
        int64_t fp_offset = (int64_t)addr - (int64_t)fp;
        int64_t sp_offset = (int64_t)addr - (int64_t)sp;
        if (telemetry_enabled) {
            char jsonbuffer[512];
            snprintf(jsonbuffer, sizeof(jsonbuffer) - 1,
                "{"
                "\"source\": \"qemu\","
                "\"trigger\": \"symbolic_store\","
                "\"addr\": \"0x%lx\","
                "\"sp\": \"%s0x%llx\","
                "\"fp\": \"%s0x%llx\","
                "\"label\": %lu,"
                "\"size\": %ld,"
                "\"pc\": \"0x%llx\""
                "}",
                addr,
                (sp_offset >= 0) ? "+" : "-", (unsigned long long)abs(sp_offset),
                (fp_offset >= 0) ? "+" : "-", (unsigned long long)abs(fp_offset),
                value_label, length, get_pc(env));
            telemetry_send(jsonbuffer);
        }
        //if (abs(fp_offset) < 0x10000 || abs(sp_offset) < 0x10000) { // Basic sanity check; the stack isn't like, a megabyte
            fprintf(stderr, "[SYMBOLIC_STORE] FP%s0x%llx SP%s0x%llx label=%lu len=%ld PC=0x%llx\n",
                    (fp_offset >=0) ? "+" : "-", (unsigned long long) abs(fp_offset), (sp_offset >= 0) ? "+" : "-", (unsigned long long) abs(sp_offset),  value_label, length, get_pc(env));
        //}
    }
    if (addr_label) {
        // fprintf(stderr, "sym store addr 0x%lx eip 0x%lx\n", addr, env->eip);
        // Replaced addr with host_addr in dfsan_union()
        dfsan_label addr_label_new = \
            dfsan_union(addr_label, CONST_LABEL, Equal, 64, (target_ulong) host_addr, 0, get_pc(env));
        __taint_trace_cmp(addr_label_new, CONST_LABEL, 64, true, Equal, 0, 0, get_pc(env));
    }

    //printf("DEBUG: Storing label via symsan_store_guest_internal(), host addr: %p, guest addr: 0x%lx, guest PC: 0x%lx, length %ld\n", host_addr, addr, get_pc(env), length);
    //assert((uintptr_t)host_addr >= 0x700000040000); // Changed to warning for Android experiment
    dfsan_store_label(value_label, (uint8_t*)host_addr, length, get_pc(env));
    // g_assert_not_reached();

}

void HELPER(symsan_store_guest_i32)(CPUArchState *env, uint64_t value_label,
                                 target_ulong addr, uint64_t addr_label, uint64_t length, uint64_t mmu_idx)
{
    symsan_store_guest_internal(env, value_label, addr, addr_label, length, mmu_idx);
}

void HELPER(symsan_store_guest_i64)(CPUArchState *env, uint64_t value_label,
                                 target_ulong addr, uint64_t addr_label, uint64_t length, uint64_t mmu_idx)
{
    symsan_store_guest_internal(env, value_label, addr, addr_label, length, mmu_idx);
}

void HELPER(symsan_store_host_i32)(uint64_t value_label,
                                void *addr,
                                uint64_t offset, uint64_t length)
{
    if ((uintptr_t)addr+offset < 0x700000040000) {
        printf("WARNING: addr+offset in symsan_store_host_i32() < 0x700000040000! (0x%lx)\n", (uintptr_t)addr+offset);
        return;
    }
    CPUArchState *env = current_cpu->env_ptr;
    if (qemu_loglevel_mask(CPU_LOG_SYM_LDST_HOST) && !noSymbolicData) {
        fprintf(stderr, "[memtrace:symbolic] op: store_host_i32 addr: %p value_label: %ld length %ld\n",
                        addr+offset, value_label, length);
    }
    //printf("DEBUG: dfsan_store_label in symsan_store_host_i32(), value_label 0x%lx, addr+offset %p, length %ld\n", value_label, addr+offset, length);
    dfsan_store_label(value_label, (uint8_t*)addr + offset, length, get_pc(env));
}

void HELPER(symsan_store_host_i64)(uint64_t value_label,
                                void *addr,
                                uint64_t offset, uint64_t length)
{
// Use the global current_cpu to get the actual env pointer for this thread
    CPUArchState *env = current_cpu->env_ptr;
    intptr_t diff = (intptr_t)addr - (intptr_t)env;
    if (qemu_loglevel_mask(CPU_LOG_SYM_LDST_HOST) && !noSymbolicData) {
        fprintf(stderr, "[memtrace:symbolic] op: store_host_i64 addr: %p value_label: %ld length %ld\n",
                        addr+offset, value_label, length);
    }
    //assert((uintptr_t)addr+offset >= 0x700000040000);
    if ((uintptr_t)addr+offset < 0x700000040000) {
        printf("[RT-DEBUG] addr: %p | env: %p | diff: %ld | offset: %lu | RA: %p\n",
               addr, (void *)env, diff, (unsigned long)offset, __builtin_return_address(0));
        printf("WARNING: addr+offset < 0x700000040000 in symsan_store_host_i64()! (0x%lx) Returning without storing label. This came from RA %p\n", (uintptr_t)addr+offset, __builtin_return_address(0)); // For Android, don't enforce this constraint
        return;
    }
    //printf("DEBUG: dfsan_store_label in symsan_store_host_i64(), value label 0x%lx, addr+offset %p, length %ld\n", value_label, addr+offset, length);
    dfsan_store_label(value_label, (uint8_t*)addr + offset, length, get_pc(env));
}


// concrete mode
/* Monitor load in concrete mode, if load symbolic data, switch to symbolic mode
 * currently, we do this in the translation backend.
 */
void HELPER(symsan_check_load_guest)(CPUArchState *env, target_ulong addr, uint64_t length, uint64_t mmu_idx) {
    //void *host_addr = g2h(addr);
    //void *host_addr = tlb_vaddr_to_host(env, addr, MMU_DATA_LOAD, mmu_idx);
    CPUState *cs = env_cpu(env);
    if (cs->in_symsan_helper) return; // For testing, please remove
    void *host_addr = tlb_vaddr_to_host(env, addr, MMU_DATA_LOAD, mmu_idx);
    if (host_addr == NULL) return;
    #ifdef TARGET_I386
    if (addr == 0x10000000) {
    #else
    // For the moment, the catch-all is an address for ARM targets. We should try other architectures as well.

    if (addr == 0x50000000) {
    //if (addr == 0x400000) {
    #endif
        if (demo_set == 0) {
            demo_set = 1;
            printf("ZOMG LOAD FROM 0x%lx DETECTED!!!!11\n", addr);
            if (second_ccache_flag == 0) {
                dfsan_label label = dfsan_create_label(0); // Changed from 0xBEEF
                dfsan_set_label(label, host_addr, 1, get_pc(env));
                //dfsan_set_label(label, (uint8_t*)host_addr, 8);
            }
        }
    }
    if ((uintptr_t)host_addr < 0x700000040000) {
        printf("WARNING: symsan_check_load_guest() returned address below 0x700000040000! PC: 0x%lx, Host address: %p, Guest Address: 0x%lx, MMU index: %ld\n", get_pc(env), host_addr, addr, mmu_idx);
    }
    //assert((uintptr_t)host_addr >= 0x700000040000);
    uint32_t res_label = dfsan_read_label((uint8_t*)host_addr, length);
    if (res_label != 0) {
        if (qemu_loglevel_mask(CPU_LOG_SYM_LDST_GUEST) && !noSymbolicData) {
            // fprintf(stderr, "[memtrace:switch] op: load_guest addr: 0x%lx host_addr %p mode: concrete\n",
            //                         addr, host_addr);
        }
        // TEMPORARY CODE: No raise exception

        if (second_ccache_flag == 0) {
            second_ccache_flag = 1; // Put this back down below
            tb_flush(cs);
        }
        else {
            printf("WARNING: System attempting raise another exception! Ignoring...\n");
            return;
        }
        #ifdef TARGET_I386
        raise_exception_err_ra(env, EXCP_SWITCH, 0, GETPC());
        #elif defined(TARGET_ARM)
        raise_exception_ra(env, EXCP_SWITCH, 0, 1, GETPC());
        #else
        #error "Unsupported architecture for symbolic execution"
        #endif
    }
}
void HELPER(symsan_check_store_guest)(CPUArchState *env, target_ulong addr, uint64_t length, uint64_t mmu_idx){
    assert(second_ccache_flag != 1);
    uint32_t value_label = 0;
    void *host_addr = tlb_vaddr_to_host(env, addr, MMU_DATA_STORE, mmu_idx);
    if (host_addr == NULL) return; // Don't store labels for a null address
    //void *host_addr = g2h(addr);
    /*
    if ((uintptr_t) host_addr < 0x700000040000) {
        printf("WARNING: host_addr is %p\n", host_addr);
    }
    
    // This can't be run in symbolic mode and the check shouldn't apply. For now.
    if ((uintptr_t)host_addr < 0x700000040000) {
        printf("WARNING: symsan_check_store_guest() returned address above 0x700000040000! PC: 0x%lx, Host address: %p, Guest Address: 0x%lx, MMU index: %ld\n", get_pc(env), host_addr, addr, mmu_idx);
        return;
    }
    */
    //assert((uintptr_t)host_addr >= 0x700000040000);
    // if (!noSymbolicData)
    // fprintf(stderr, "[memtrace] op: check_store_guest addr: 0x%lx mode: concrete\n", addr);
    dfsan_store_label(value_label, (uint8_t*)host_addr, length, get_pc(env));
}

/* Check the register status at the end of one basic block in symbolic mode
 * if there is no symbolic registers, switch to concrete mode
 */
void HELPER(symsan_check_state_switch)(CPUArchState *env) {
    int symbolic_flag = 0;
    #ifdef TARGET_AARCH64 // TO DO: Do this in the rest of the for loops

    /* ARM is a little different; 64/32 bit mode switches involve using
     * a fundamentally different set of registers rather than the 32 LSBs of
     * the first half. 32-bit x86 on an x86-64 chip, by contrast, shares the
     * same registers in both modes. 
     */
    if (env->aarch64) {
        // Register 31 is always zero/sp register, so we're not checking it
        for (unsigned char i=0; i<31;i++) {
            if (env->shadow_xregs[i]) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    else {
        // 32-bit mode check
        for (unsigned char i=0; i<16;i++) {
            if (env->shadow_regs[i]) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    #elif defined(TARGET_ARM)
    for (unsigned char i=0; i<16;i++) {
        if (env->shadow_regs[i]) {
            symbolic_flag = 1;
            break;
        }
    }
    #else
    for (unsigned char i=0; i<CPU_NB_REGS;i++) {
        if (env->shadow_regs[i]){
            symbolic_flag = 1;
            break;
        }
    }
    #endif
    if (symbolic_flag) {
        second_ccache_flag = 1;
        //if (!noSymbolicData) fprintf(stderr, "block 0x%lx state symbolic\n", env->eip);
        return;
    }
    #ifdef TARGET_I386
    if (env->shadow_cc_dst || env->shadow_cc_src || env->shadow_cc_src2) {
        symbolic_flag = 1;
    }
    #elif defined(TARGET_AARCH64)
    if (env->shadow_CF || env->shadow_NF || env->shadow_VF || env->shadow_ZF) {
        symbolic_flag = 1;
    }
    #endif

    // TO DO: Should we add support for the equivalent NEON registers in ARM?
    #ifdef TARGET_I386
    if (!symbolic_flag && sse_operation) {
        int size = sizeof(env->xmm_regs);
        uintptr_t xmm_reg_addr = (uintptr_t)env->xmm_regs;
        uint64_t xmm_reg = 0;
        for (uintptr_t addr = xmm_reg_addr; addr < xmm_reg_addr + size; addr+=8) {
            xmm_reg = dfsan_read_label((uint8_t *)addr, 8);
            if (xmm_reg != 0) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    #endif
    second_ccache_flag = symbolic_flag;
    if (second_ccache_flag == 0) {
        CPUState *cs = env_cpu(env);
        cpu_loop_exit_noexc(cs);
    }
}
void HELPER(symsan_check_state)(CPUArchState *env) {
    int symbolic_flag = 0;
    #ifdef TARGET_AARCH64 // TO DO: Do this in the rest of the for loops

    /* ARM is a little different; 64/32 bit mode switches involve using
     * a fundamentally different set of registers rather than the 32 LSBs of
     * the first half. 32-bit x86 on an x86-64 chip, by contrast, shares the
     * same registers in both modes.
     */
    if (env->aarch64) {
        // Register 31 is always zero/sp register, so we're not checking it
        for (unsigned char i=0; i<31;i++) {
            if (env->shadow_xregs[i]) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    else {
        // 32-bit mode check
        for (unsigned char i=0; i<16;i++) {
            if (env->shadow_regs[i]) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    #elif defined(TARGET_ARM)
    for (unsigned char i=0; i<16;i++) {
        if (env->shadow_regs[i]) {
            symbolic_flag = 1;
            break;
        }
    }
    #else
    for (unsigned char i=0; i<CPU_NB_REGS;i++) {
        if (env->shadow_regs[i]){
            symbolic_flag = 1;
            break;
        }
    }
    #endif
    if (symbolic_flag) {
        second_ccache_flag = 1;
        return;
    }
    #ifdef TARGET_I386
    if (env->shadow_cc_dst || env->shadow_cc_src || env->shadow_cc_src2) {
        symbolic_flag = 1;
    }
    #elif defined(TARGET_AARCH64)
    if (env->shadow_CF || env->shadow_NF || env->shadow_VF || env->shadow_ZF) {
        symbolic_flag = 1;
    }
    #endif

    #ifdef TARGET_I386
    if (!symbolic_flag && sse_operation) {
        int size = sizeof(env->xmm_regs);
        uintptr_t xmm_reg_addr = (uintptr_t)env->xmm_regs;
        uint64_t xmm_reg = 0;
        for (uintptr_t addr = xmm_reg_addr; addr < xmm_reg_addr + size; addr+=8) {
            xmm_reg = dfsan_read_label((uint8_t *)addr, 8);
            if (xmm_reg != 0) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    #endif
    second_ccache_flag = symbolic_flag;
}

void HELPER(symsan_check_state_no_sse)(CPUArchState *env) {
    int symbolic_flag = 0;
    #ifdef TARGET_AARCH64 // TO DO: Do this in the rest of the for loops

    /* ARM is a little different; 64/32 bit mode switches involve using
     * a fundamentally different set of registers rather than the 32 LSBs of
     * the first half. 32-bit x86 on an x86-64 chip, by contrast, shares the
     * same registers in both modes.
     */
    if (env->aarch64) {
        // Register 31 is always zero/sp register, so we're not checking it
        for (unsigned char i=0; i<31;i++) {
            if (env->shadow_xregs[i]) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    else {
        // 32-bit mode check
        for (unsigned char i=0; i<16;i++) {
            if (env->shadow_regs[i]) {
                symbolic_flag = 1;
                break;
            }
        }
    }
    #elif defined(TARGET_ARM)
    for (unsigned char i=0; i<16;i++) {
        if (env->shadow_regs[i]) {
            symbolic_flag = 1;
            break;
        }
    }
    #else
    for (unsigned char i=0; i<CPU_NB_REGS;i++) {
        if (env->shadow_regs[i]){
            symbolic_flag = 1;
            break;
        }
    }
    #endif
    if (symbolic_flag) {
        second_ccache_flag = 1;
        //if (!noSymbolicData) fprintf(stderr, "block 0x%lx state symbolic\n", env->eip);
        return;
    }
    #ifdef TARGET_I386
    if (env->shadow_cc_dst || env->shadow_cc_src || env->shadow_cc_src2) {
        symbolic_flag = 1;
    }
    #elif defined(TARGET_AARCH64)
    if (env->shadow_CF || env->shadow_NF || env->shadow_VF || env->shadow_ZF) {
        symbolic_flag = 1;
    }
    #endif
    second_ccache_flag = symbolic_flag;
    // if (!noSymbolicData) fprintf(stderr, "block 0x%lx state %s\n", env->eip, second_ccache_flag?"symbolic":"concrete");
    if (second_ccache_flag == 0) {
        CPUState *cs = env_cpu(env);
        cpu_loop_exit_noexc(cs);
    }
}

// void HELPER(symsan_notify_call)(uint64_t func_addr)
// {
//     addContextRecording(func_addr);
// }

