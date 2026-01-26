/* Auto-generated ARM64 syscall arg table for Linux 6.1.54 */
#include <stdint.h>

#ifndef SYSCALL_ARG_TYPES_ARM64_AUTOGEN
#define SYSCALL_ARG_TYPES_ARM64_AUTOGEN

#define ARG_NONE 0
#define ARG_CHAR 1
#define ARG_SHORT 2
#define ARG_INT 3
#define ARG_LONG 4
#define ARG_LONGLONG 5
#define ARG_PTR 6
#define ARG_STR 7
#define ARG_FD 8

#define MAX_SYSCALL_ARGS 6

typedef struct { int arg_type[MAX_SYSCALL_ARGS]; } syscall_args_t;

/* Table indexed by syscall number. */
static const syscall_args_t syscall_args_table[452] = {
    [0] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 0: io_setup defined_in=fs/aio.c */
    [1] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 1: io_destroy defined_in=fs/aio.c */
    [2] = { { ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 2: io_submit defined_in=fs/aio.c */
    [3] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 3: io_cancel defined_in=fs/aio.c */
    [4] = { { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 4: io_getevents defined_in=fs/aio.c */
    [5] = { { ARG_CHAR, ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 5: setxattr defined_in=fs/xattr.c */
    [6] = { { ARG_CHAR, ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 6: lsetxattr defined_in=fs/xattr.c */
    [7] = { { ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 7: fsetxattr defined_in=fs/xattr.c */
    [8] = { { ARG_CHAR, ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 8: getxattr defined_in=fs/xattr.c */
    [9] = { { ARG_CHAR, ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 9: lgetxattr defined_in=fs/xattr.c */
    [10] = { { ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 10: fgetxattr defined_in=fs/xattr.c */
    [11] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 11: listxattr defined_in=fs/xattr.c */
    [12] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 12: llistxattr defined_in=fs/xattr.c */
    [13] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 13: flistxattr defined_in=fs/xattr.c */
    [14] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 14: removexattr defined_in=fs/xattr.c */
    [15] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 15: lremovexattr defined_in=fs/xattr.c */
    [16] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 16: fremovexattr defined_in=fs/xattr.c */
    [17] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 17: getcwd defined_in=fs/d_path.c */
    [18] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 18: lookup_dcookie */
    [19] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 19: eventfd2 defined_in=fs/eventfd.c */
    [20] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 20: epoll_create1 defined_in=fs/eventpoll.c */
    [21] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 21: epoll_ctl defined_in=fs/eventpoll.c */
    [22] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 22: epoll_pwait defined_in=fs/eventpoll.c */
    [23] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 23: dup defined_in=fs/file.c */
    [24] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 24: dup3 defined_in=fs/file.c */
    [25] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [26] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 26: inotify_init1 defined_in=fs/notify/inotify/inotify_user.c */
    [27] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 27: inotify_add_watch defined_in=fs/notify/inotify/inotify_user.c */
    [28] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 28: inotify_rm_watch defined_in=fs/notify/inotify/inotify_user.c */
    [29] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 29: ioctl defined_in=fs/ioctl.c */
    [30] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 30: ioprio_set */
    [31] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 31: ioprio_get */
    [32] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 32: flock defined_in=fs/locks.c */
    [33] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 33: mknodat defined_in=fs/namei.c */
    [34] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 34: mkdirat defined_in=fs/namei.c */
    [35] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 35: unlinkat defined_in=fs/namei.c */
    [36] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 36: symlinkat defined_in=fs/namei.c */
    [37] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 37: linkat defined_in=fs/namei.c */
    [38] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 38: renameat defined_in=fs/namei.c */
    [39] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 39: umount2 */
    [40] = { { ARG_CHAR, ARG_CHAR, ARG_CHAR, ARG_INT, ARG_PTR, ARG_NONE } },/* 40: mount defined_in=fs/namespace.c */
    [41] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 41: pivot_root defined_in=fs/namespace.c */
    [42] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 42: nfsservctl */
    [43] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [44] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [45] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [46] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [47] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 47: fallocate defined_in=fs/open.c */
    [48] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 48: faccessat defined_in=fs/open.c */
    [49] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 49: chdir defined_in=fs/open.c */
    [50] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 50: fchdir defined_in=fs/open.c */
    [51] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 51: chroot defined_in=fs/open.c */
    [52] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 52: fchmod defined_in=fs/open.c */
    [53] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 53: fchmodat defined_in=fs/open.c */
    [54] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 54: fchownat defined_in=fs/open.c */
    [55] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 55: fchown defined_in=fs/open.c */
    [56] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 56: openat defined_in=fs/open.c */
    [57] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 57: close defined_in=fs/open.c */
    [58] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 58: vhangup */
    [59] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 59: pipe2 defined_in=fs/pipe.c */
    [60] = { { ARG_INT, ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 60: quotactl defined_in=fs/quota/quota.c */
    [61] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 61: getdents64 defined_in=fs/readdir.c */
    [62] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [63] = { { ARG_INT, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 63: read defined_in=fs/read_write.c */
    [64] = { { ARG_INT, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 64: write defined_in=fs/read_write.c */
    [65] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 65: readv defined_in=fs/read_write.c */
    [66] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 66: writev defined_in=fs/read_write.c */
    [67] = { { ARG_INT, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 67: pread64 defined_in=fs/read_write.c */
    [68] = { { ARG_INT, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 68: pwrite64 defined_in=fs/read_write.c */
    [69] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 69: preadv defined_in=fs/read_write.c */
    [70] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 70: pwritev defined_in=fs/read_write.c */
    [71] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [72] = { { ARG_INT, ARG_INT, ARG_INT, ARG_LONG, ARG_PTR, ARG_NONE } },/* 72: pselect6 defined_in=fs/select.c */
    [73] = { { ARG_INT, ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE } },/* 73: ppoll defined_in=fs/select.c */
    [74] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 74: signalfd4 defined_in=fs/signalfd.c */
    [75] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 75: vmsplice defined_in=fs/splice.c */
    [76] = { { ARG_LONGLONG, ARG_LONGLONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 76: splice defined_in=fs/splice.c */
    [77] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 77: tee defined_in=fs/splice.c */
    [78] = { { ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 78: readlinkat defined_in=fs/stat.c */
    [79] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [80] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [81] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 81: sync */
    [82] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 82: fsync defined_in=fs/sync.c */
    [83] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 83: fdatasync defined_in=fs/sync.c */
    [84] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 84: sync_file_range defined_in=fs/sync.c */
    [85] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 85: timerfd_create defined_in=fs/timerfd.c */
    [86] = { { ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 86: timerfd_settime defined_in=fs/timerfd.c */
    [87] = { { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 87: timerfd_gettime defined_in=fs/timerfd.c */
    [88] = { { ARG_CHAR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 88: utimensat defined_in=fs/utimes.c */
    [89] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 89: acct defined_in=kernel/acct.c */
    [90] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 90: capget defined_in=kernel/capability.c */
    [91] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 91: capset defined_in=kernel/capability.c */
    [92] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 92: personality defined_in=kernel/exec_domain.c */
    [93] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 93: exit defined_in=kernel/exit.c */
    [94] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 94: exit_group defined_in=kernel/exit.c */
    [95] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 95: waitid defined_in=kernel/exit.c */
    [96] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 96: set_tid_address defined_in=kernel/fork.c */
    [97] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 97: unshare defined_in=kernel/fork.c */
    [98] = { { ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 98: futex defined_in=kernel/futex/syscalls.c */
    [99] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 99: set_robust_list defined_in=kernel/futex/syscalls.c */
    [100] = { { ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 100: get_robust_list defined_in=kernel/futex/syscalls.c */
    [101] = { { ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 101: nanosleep defined_in=kernel/time/hrtimer.c */
    [102] = { { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 102: getitimer defined_in=kernel/time/itimer.c */
    [103] = { { ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 103: setitimer defined_in=kernel/time/itimer.c */
    [104] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE } },/* 104: kexec_load defined_in=kernel/kexec.c */
    [105] = { { ARG_PTR, ARG_INT, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 105: init_module defined_in=kernel/module/main.c */
    [106] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 106: delete_module defined_in=kernel/module/main.c */
    [107] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 107: timer_create defined_in=kernel/time/posix-timers.c */
    [108] = { { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 108: timer_gettime defined_in=kernel/time/posix-timers.c */
    [109] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 109: timer_getoverrun defined_in=kernel/time/posix-timers.c */
    [110] = { { ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 110: timer_settime defined_in=kernel/time/posix-timers.c */
    [111] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 111: timer_delete defined_in=kernel/time/posix-timers.c */
    [112] = { { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 112: clock_settime defined_in=kernel/time/posix-stubs.c */
    [113] = { { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 113: clock_gettime defined_in=kernel/time/posix-stubs.c */
    [114] = { { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 114: clock_getres defined_in=kernel/time/posix-stubs.c */
    [115] = { { ARG_INT, ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE } },/* 115: clock_nanosleep defined_in=kernel/time/posix-stubs.c */
    [116] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 116: syslog defined_in=kernel/printk/printk.c */
    [117] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 117: ptrace defined_in=kernel/ptrace.c */
    [118] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 118: sched_setparam defined_in=kernel/sched/core.c */
    [119] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 119: sched_setscheduler defined_in=kernel/sched/core.c */
    [120] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 120: sched_getscheduler defined_in=kernel/sched/core.c */
    [121] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 121: sched_getparam defined_in=kernel/sched/core.c */
    [122] = { { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 122: sched_setaffinity defined_in=kernel/compat.c */
    [123] = { { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 123: sched_getaffinity defined_in=kernel/compat.c */
    [124] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 124: sched_yield */
    [125] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 125: sched_get_priority_max defined_in=kernel/sched/core.c */
    [126] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 126: sched_get_priority_min defined_in=kernel/sched/core.c */
    [127] = { { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 127: sched_rr_get_interval defined_in=kernel/sched/core.c */
    [128] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 128: restart_syscall */
    [129] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 129: kill defined_in=kernel/signal.c */
    [130] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 130: tkill defined_in=kernel/signal.c */
    [131] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 131: tgkill defined_in=kernel/signal.c */
    [132] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 132: sigaltstack defined_in=kernel/signal.c */
    [133] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 133: rt_sigsuspend defined_in=kernel/signal.c */
    [134] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 134: rt_sigaction defined_in=kernel/signal.c */
    [135] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 135: rt_sigprocmask defined_in=kernel/signal.c */
    [136] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 136: rt_sigpending defined_in=kernel/signal.c */
    [137] = { { ARG_INT, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE } },/* 137: rt_sigtimedwait defined_in=kernel/signal.c */
    [138] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 138: rt_sigqueueinfo defined_in=kernel/signal.c */
    [139] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 139: rt_sigreturn */
    [140] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 140: setpriority defined_in=kernel/sys.c */
    [141] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 141: getpriority defined_in=kernel/sys.c */
    [142] = { { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 142: reboot defined_in=kernel/reboot.c */
    [143] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 143: setregid defined_in=kernel/sys.c */
    [144] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 144: setgid defined_in=kernel/sys.c */
    [145] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 145: setreuid defined_in=kernel/sys.c */
    [146] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 146: setuid defined_in=kernel/sys.c */
    [147] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 147: setresuid defined_in=kernel/sys.c */
    [148] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 148: getresuid defined_in=kernel/sys.c */
    [149] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 149: setresgid defined_in=kernel/sys.c */
    [150] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 150: getresgid defined_in=kernel/sys.c */
    [151] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 151: setfsuid defined_in=kernel/sys.c */
    [152] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 152: setfsgid defined_in=kernel/sys.c */
    [153] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 153: times defined_in=kernel/sys.c */
    [154] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 154: setpgid defined_in=kernel/sys.c */
    [155] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 155: getpgid defined_in=kernel/sys.c */
    [156] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 156: getsid defined_in=kernel/sys.c */
    [157] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 157: setsid */
    [158] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 158: getgroups defined_in=kernel/groups.c */
    [159] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 159: setgroups defined_in=kernel/groups.c */
    [160] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 160: uname defined_in=kernel/sys.c */
    [161] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 161: sethostname defined_in=kernel/sys.c */
    [162] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 162: setdomainname defined_in=kernel/sys.c */
    [163] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 163: getrlimit defined_in=kernel/sys.c */
    [164] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 164: setrlimit defined_in=kernel/sys.c */
    [165] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 165: getrusage defined_in=kernel/sys.c */
    [166] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 166: umask defined_in=kernel/sys.c */
    [167] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE } },/* 167: prctl defined_in=kernel/sys.c */
    [168] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 168: getcpu defined_in=kernel/sys.c */
    [169] = { { ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 169: gettimeofday defined_in=kernel/time/time.c */
    [170] = { { ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 170: settimeofday defined_in=kernel/time/time.c */
    [171] = { { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 171: adjtimex defined_in=kernel/time/time.c */
    [172] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 172: getpid */
    [173] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 173: getppid */
    [174] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 174: getuid */
    [175] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 175: geteuid */
    [176] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 176: getgid */
    [177] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 177: getegid */
    [178] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 178: gettid */
    [179] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 179: sysinfo defined_in=kernel/sys.c */
    [180] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 180: mq_open defined_in=ipc/mqueue.c */
    [181] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 181: mq_unlink defined_in=ipc/mqueue.c */
    [182] = { { ARG_CHAR, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE } },/* 182: mq_timedsend defined_in=ipc/mqueue.c */
    [183] = { { ARG_CHAR, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE } },/* 183: mq_timedreceive defined_in=ipc/mqueue.c */
    [184] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 184: mq_notify defined_in=ipc/mqueue.c */
    [185] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 185: mq_getsetattr defined_in=ipc/mqueue.c */
    [186] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 186: msgget defined_in=ipc/msg.c */
    [187] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 187: msgctl defined_in=ipc/msg.c */
    [188] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 188: msgrcv defined_in=ipc/msg.c */
    [189] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 189: msgsnd defined_in=ipc/msg.c */
    [190] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 190: semget defined_in=ipc/sem.c */
    [191] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 191: semctl defined_in=ipc/sem.c */
    [192] = { { ARG_INT, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE } },/* 192: semtimedop defined_in=ipc/sem.c */
    [193] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 193: semop defined_in=ipc/sem.c */
    [194] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 194: shmget defined_in=ipc/shm.c */
    [195] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 195: shmctl defined_in=ipc/shm.c */
    [196] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 196: shmat defined_in=ipc/shm.c */
    [197] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 197: shmdt defined_in=ipc/shm.c */
    [198] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 198: socket defined_in=net/socket.c */
    [199] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 199: socketpair defined_in=net/socket.c */
    [200] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 200: bind defined_in=net/socket.c */
    [201] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 201: listen defined_in=net/socket.c */
    [202] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 202: accept defined_in=net/socket.c */
    [203] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 203: connect defined_in=net/socket.c */
    [204] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 204: getsockname defined_in=net/socket.c */
    [205] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 205: getpeername defined_in=net/socket.c */
    [206] = { { ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 206: sendto defined_in=net/socket.c */
    [207] = { { ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE } },/* 207: recvfrom defined_in=net/compat.c */
    [208] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 208: setsockopt defined_in=net/socket.c */
    [209] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 209: getsockopt defined_in=net/socket.c */
    [210] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 210: shutdown defined_in=net/socket.c */
    [211] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 211: sendmsg defined_in=net/compat.c */
    [212] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 212: recvmsg defined_in=net/compat.c */
    [213] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 213: readahead defined_in=mm/readahead.c */
    [214] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 214: brk defined_in=mm/mmap.c */
    [215] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 215: munmap defined_in=mm/mmap.c */
    [216] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 216: mremap defined_in=mm/mremap.c */
    [217] = { { ARG_CHAR, ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 217: add_key defined_in=security/keys/keyctl.c */
    [218] = { { ARG_CHAR, ARG_CHAR, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 218: request_key defined_in=security/keys/keyctl.c */
    [219] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 219: keyctl defined_in=security/keys/compat.c */
    [220] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 220: clone defined_in=kernel/fork.c */
    [221] = { { ARG_CHAR, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 221: execve defined_in=fs/exec.c */
    [222] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [223] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [224] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 224: swapon defined_in=mm/swapfile.c */
    [225] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 225: swapoff defined_in=mm/swapfile.c */
    [226] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 226: mprotect defined_in=mm/mprotect.c */
    [227] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 227: msync defined_in=mm/msync.c */
    [228] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 228: mlock defined_in=mm/mlock.c */
    [229] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 229: munlock defined_in=mm/mlock.c */
    [230] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 230: mlockall defined_in=mm/mlock.c */
    [231] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 231: munlockall */
    [232] = { { ARG_INT, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 232: mincore defined_in=mm/mincore.c */
    [233] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 233: madvise defined_in=mm/madvise.c */
    [234] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 234: remap_file_pages defined_in=mm/mmap.c */
    [235] = { { ARG_INT, ARG_INT, ARG_INT, ARG_LONG, ARG_INT, ARG_INT } },/* 235: mbind defined_in=mm/mempolicy.c */
    [236] = { { ARG_INT, ARG_LONG, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 236: get_mempolicy defined_in=mm/mempolicy.c */
    [237] = { { ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 237: set_mempolicy defined_in=mm/mempolicy.c */
    [238] = { { ARG_INT, ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE } },/* 238: migrate_pages defined_in=mm/mempolicy.c */
    [239] = { { ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE } },/* 239: move_pages defined_in=mm/migrate.c */
    [240] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 240: rt_tgsigqueueinfo defined_in=kernel/signal.c */
    [241] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 241: perf_event_open defined_in=kernel/events/core.c */
    [242] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 242: accept4 defined_in=net/socket.c */
    [243] = { { ARG_INT, ARG_INT, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE } },/* 243: recvmmsg defined_in=net/socket.c */
    [244] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 244: arch_specific_syscall */
    [245] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [246] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [247] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [248] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [249] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [250] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [251] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [252] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [253] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [254] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [255] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [256] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [257] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [258] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [259] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [260] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 260: wait4 defined_in=kernel/exit.c */
    [261] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 261: prlimit64 defined_in=kernel/sys.c */
    [262] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 262: fanotify_init defined_in=fs/notify/fanotify/fanotify_user.c */
    [263] = { { ARG_INT, ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 263: fanotify_mark defined_in=fs/notify/fanotify/fanotify_user.c */
    [264] = { { ARG_CHAR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 264: name_to_handle_at defined_in=fs/fhandle.c */
    [265] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 265: open_by_handle_at defined_in=fs/fhandle.c */
    [266] = { { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 266: clock_adjtime defined_in=kernel/time/posix-timers.c */
    [267] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 267: syncfs defined_in=fs/sync.c */
    [268] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 268: setns defined_in=kernel/nsproxy.c */
    [269] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 269: sendmmsg defined_in=net/compat.c */
    [270] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 270: process_vm_readv defined_in=mm/process_vm_access.c */
    [271] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 271: process_vm_writev defined_in=mm/process_vm_access.c */
    [272] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 272: kcmp defined_in=kernel/kcmp.c */
    [273] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 273: finit_module defined_in=kernel/module/main.c */
    [274] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 274: sched_setattr defined_in=kernel/sched/core.c */
    [275] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 275: sched_getattr defined_in=kernel/sched/core.c */
    [276] = { { ARG_CHAR, ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 276: renameat2 defined_in=fs/namei.c */
    [277] = { { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 277: seccomp defined_in=kernel/seccomp.c */
    [278] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 278: getrandom */
    [279] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 279: memfd_create defined_in=mm/memfd.c */
    [280] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 280: bpf defined_in=kernel/bpf/syscall.c */
    [281] = { { ARG_CHAR, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 281: execveat defined_in=fs/exec.c */
    [282] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 282: userfaultfd defined_in=fs/userfaultfd.c */
    [283] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 283: membarrier defined_in=kernel/sched/membarrier.c */
    [284] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 284: mlock2 defined_in=mm/mlock.c */
    [285] = { { ARG_LONGLONG, ARG_LONGLONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 285: copy_file_range defined_in=fs/read_write.c */
    [286] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 286: preadv2 defined_in=fs/read_write.c */
    [287] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE } },/* 287: pwritev2 defined_in=fs/read_write.c */
    [288] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 288: pkey_mprotect defined_in=mm/mprotect.c */
    [289] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 289: pkey_alloc defined_in=mm/mprotect.c */
    [290] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 290: pkey_free defined_in=mm/mprotect.c */
    [291] = { { ARG_CHAR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 291: statx defined_in=fs/stat.c */
    [292] = { { ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 292: io_pgetevents defined_in=fs/aio.c */
    [293] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 293: rseq defined_in=kernel/rseq.c */
    [294] = { { ARG_INT, ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 294: kexec_file_load defined_in=kernel/kexec_file.c */
    [295] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [296] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [297] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [298] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [299] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [300] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [301] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [302] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [303] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [304] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [305] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [306] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [307] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [308] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [309] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [310] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [311] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [312] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [313] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [314] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [315] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [316] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [317] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [318] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [319] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [320] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [321] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [322] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [323] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [324] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [325] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [326] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [327] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [328] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [329] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [330] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [331] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [332] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [333] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [334] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [335] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [336] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [337] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [338] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [339] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [340] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [341] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [342] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [343] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [344] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [345] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [346] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [347] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [348] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [349] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [350] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [351] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [352] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [353] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [354] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [355] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [356] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [357] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [358] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [359] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [360] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [361] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [362] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [363] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [364] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [365] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [366] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [367] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [368] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [369] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [370] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [371] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [372] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [373] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [374] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [375] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [376] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [377] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [378] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [379] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [380] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [381] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [382] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [383] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [384] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [385] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [386] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [387] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [388] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [389] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [390] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [391] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [392] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [393] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [394] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [395] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [396] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [397] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [398] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [399] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [400] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [401] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [402] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [403] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 403: clock_gettime64 */
    [404] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 404: clock_settime64 */
    [405] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 405: clock_adjtime64 */
    [406] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 406: clock_getres_time64 */
    [407] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 407: clock_nanosleep_time64 */
    [408] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 408: timer_gettime64 */
    [409] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 409: timer_settime64 */
    [410] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 410: timerfd_gettime64 */
    [411] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 411: timerfd_settime64 */
    [412] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 412: utimensat_time64 */
    [413] = { { ARG_LONG, ARG_LONG, ARG_LONG, ARG_LONG, ARG_PTR, ARG_NONE } },/* 413: pselect6_time64 defined_in=fs/select.c */
    [414] = { { ARG_INT, ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE } },/* 414: ppoll_time64 defined_in=fs/select.c */
    [415] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* <unused> */
    [416] = { { ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 416: io_pgetevents_time64 defined_in=fs/aio.c */
    [417] = { { ARG_INT, ARG_INT, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE } },/* 417: recvmmsg_time64 defined_in=net/compat.c */
    [418] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 418: mq_timedsend_time64 */
    [419] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 419: mq_timedreceive_time64 */
    [420] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 420: semtimedop_time64 */
    [421] = { { ARG_INT, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE } },/* 421: rt_sigtimedwait_time64 defined_in=kernel/signal.c */
    [422] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 422: futex_time64 */
    [423] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 423: sched_rr_get_interval_time64 */
    [424] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 424: pidfd_send_signal defined_in=kernel/signal.c */
    [425] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 425: io_uring_setup */
    [426] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 426: io_uring_enter */
    [427] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 427: io_uring_register */
    [428] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 428: open_tree defined_in=fs/namespace.c */
    [429] = { { ARG_CHAR, ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 429: move_mount defined_in=fs/namespace.c */
    [430] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 430: fsopen defined_in=fs/fsopen.c */
    [431] = { { ARG_INT, ARG_CHAR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 431: fsconfig defined_in=fs/fsopen.c */
    [432] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 432: fsmount defined_in=fs/namespace.c */
    [433] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 433: fspick defined_in=fs/fsopen.c */
    [434] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 434: pidfd_open defined_in=kernel/pid.c */
    [435] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 435: clone3 defined_in=kernel/fork.c */
    [436] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 436: close_range defined_in=fs/open.c */
    [437] = { { ARG_CHAR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 437: openat2 defined_in=fs/open.c */
    [438] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 438: pidfd_getfd defined_in=kernel/pid.c */
    [439] = { { ARG_CHAR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 439: faccessat2 defined_in=fs/open.c */
    [440] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 440: process_madvise defined_in=mm/madvise.c */
    [441] = { { ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 441: epoll_pwait2 defined_in=fs/eventpoll.c */
    [442] = { { ARG_CHAR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 442: mount_setattr defined_in=fs/namespace.c */
    [443] = { { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE } },/* 443: quotactl_fd defined_in=fs/quota/quota.c */
    [444] = { { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE } },/* 444: landlock_create_ruleset defined_in=security/landlock/syscalls.c */
    [445] = { { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE } },/* 445: landlock_add_rule defined_in=security/landlock/syscalls.c */
    [446] = { { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 446: landlock_restrict_self defined_in=security/landlock/syscalls.c */
    [447] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 447: memfd_secret defined_in=mm/secretmem.c */
    [448] = { { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 448: process_mrelease defined_in=mm/oom_kill.c */
    [449] = { { ARG_INT, ARG_INT, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE } },/* 449: futex_waitv defined_in=kernel/futex/syscalls.c */
    [450] = { { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE } },/* 450: set_mempolicy_home_node defined_in=mm/mempolicy.c */
    [451] = { { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE } },/* 451: syscalls */
};

#endif /* SYSCALL_ARG_TYPES_ARM64_AUTOGEN */
