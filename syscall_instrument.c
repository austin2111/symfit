#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Magic SVC number - must match QEMU implementation
#define SYMFIT_MAGIC_CPUID 0xBEEF

static inline void set_syscall_tracing(bool enable)
{
    register unsigned int eax __asm__("eax") = SYMFIT_MAGIC_CPUID;
    register unsigned int edi __asm__("edi") = enable ? 1 : 0;

    __asm__ __volatile__(
        "cpuid"
        : "+r"(eax)
        : "r"(edi)
        : "ebx", "ecx", "edx", "memory"
    );
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <enable|disable>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "enable") == 0) {
        printf("Enabling syscall instrumentation...\n");
        set_syscall_tracing(1);
        printf("DEBUG: SUCCESS!\n");
    }
    else if (strcmp(argv[1], "disable") == 0) {
        printf("Disabling syscall instrumentation...\n");
        set_syscall_tracing(0);
    }
    else {
        fprintf(stderr, "USAGE: %s <enable|disable>\n", argv[0]);
        return 1;
    }
    return 0;
}
