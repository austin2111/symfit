/* Auto-generated syscall arg table (partial heuristics) */

#ifndef SYSCALL_ARG_TYPES_AUTOGEN
#define SYSCALL_ARG_TYPES_AUTOGEN

#define ARG_NONE 0
#define ARG_CHAR 1
#define ARG_SHORT 2
#define ARG_INT 3
#define ARG_LONG 4
#define ARG_LONGLONG 5
#ifdef PTR_AS_STRING
#define ARG_PTR 7
#else
#define ARG_PTR 6
#endif
#define ARG_STR 7
#define ARG_FD 8

#define MAX_SYSCALL_ARGS 6

typedef struct { int arg_type[MAX_SYSCALL_ARGS]; } syscall_args_t;

/* Table indexed by syscall number. */
static const syscall_args_t syscall_args_table[548] = {
    [0] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 0: read defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [1] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 1: write defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [2] = { ARG_STR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 2: open defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [3] = { ARG_FD, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 3: close defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [4] = { ARG_STR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 4: stat defined_in=/home/user/LUNIX/linux-6.1.54/fs/stat.c */
    [5] = { ARG_FD, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 5: fstat defined_in=/home/user/LUNIX/linux-6.1.54/fs/stat.c */
    [6] = { ARG_STR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 6: lstat defined_in=/home/user/LUNIX/linux-6.1.54/fs/stat.c */
    [7] = { ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 7: poll defined_in=/home/user/LUNIX/linux-6.1.54/fs/select.c */
    [8] = { ARG_FD, ARG_LONGLONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 8: lseek defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [9] = { ARG_PTR, ARG_LONG, ARG_INT, ARG_INT, ARG_FD, ARG_LONG }, /* 9: mmap defined_in=/home/user/LUNIX/linux-6.1.54/arch/arm64/kernel/sys.c */
    [10] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 10: mprotect defined_in=/home/user/LUNIX/linux-6.1.54/mm/mprotect.c */
    [11] = { ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 11: munmap defined_in=/home/user/LUNIX/linux-6.1.54/mm/nommu.c */
    [12] = { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 12: brk defined_in=/home/user/LUNIX/linux-6.1.54/mm/nommu.c */
    [13] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_LONG, ARG_PTR, ARG_NONE }, /* 13: rt_sigaction defined_in=/home/user/LUNIX/linux-6.1.54/arch/alpha/kernel/signal.c */
    [14] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 14: rt_sigprocmask defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [15] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 15: rt_sigreturn defined_in=/home/user/LUNIX/linux-6.1.54/arch/arm64/kernel/signal.c */
    [16] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 16: ioctl defined_in=/home/user/LUNIX/linux-6.1.54/fs/ioctl.c */
    [17] = { ARG_FD, ARG_STR, ARG_LONG, ARG_INT, ARG_INT, ARG_NONE }, /* 17: pread64 defined_in=/home/user/LUNIX/linux-6.1.54/arch/sparc/kernel/sys_sparc32.c */
    [18] = { ARG_FD, ARG_STR, ARG_LONG, ARG_INT, ARG_INT, ARG_NONE }, /* 18: pwrite64 defined_in=/home/user/LUNIX/linux-6.1.54/arch/sparc/kernel/sys_sparc32.c */
    [19] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 19: readv defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [20] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 20: writev defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [21] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 21: access defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [22] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 22: pipe defined_in=/home/user/LUNIX/linux-6.1.54/fs/pipe.c */
    [23] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_NONE }, /* 23: select defined_in=/home/user/LUNIX/linux-6.1.54/fs/select.c */
    [24] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 24: sched_yield defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [25] = { ARG_PTR, ARG_LONG, ARG_LONG, ARG_INT, ARG_LONG, ARG_NONE }, /* 25: mremap defined_in=/home/user/LUNIX/linux-6.1.54/mm/nommu.c */
    [26] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 26: msync defined_in=/home/user/LUNIX/linux-6.1.54/mm/msync.c */
    [27] = { ARG_LONG, ARG_LONG, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 27: mincore defined_in=/home/user/LUNIX/linux-6.1.54/mm/mincore.c */
    [28] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 28: madvise defined_in=/home/user/LUNIX/linux-6.1.54/mm/madvise.c */
    [29] = { ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 29: shmget defined_in=/home/user/LUNIX/linux-6.1.54/ipc/shm.c */
    [30] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 30: shmat defined_in=/home/user/LUNIX/linux-6.1.54/ipc/shm.c */
    [31] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 31: shmctl defined_in=/home/user/LUNIX/linux-6.1.54/ipc/shm.c */
    [32] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 32: dup defined_in=/home/user/LUNIX/linux-6.1.54/fs/file.c */
    [33] = { ARG_FD, ARG_FD, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 33: dup2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/file.c */
    [34] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 34: pause defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [35] = { ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 35: nanosleep defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/hrtimer.c */
    [36] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 36: getitimer defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/itimer.c */
    [37] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 37: alarm defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/itimer.c */
    [38] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 38: setitimer defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/itimer.c */
    [39] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 39: getpid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [40] = { ARG_INT, ARG_INT, ARG_LONGLONG, ARG_LONG, ARG_NONE, ARG_NONE }, /* 40: sendfile defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [41] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 41: socket defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [42] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 42: connect defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [43] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 43: accept defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [44] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_INT, ARG_PTR, ARG_INT }, /* 44: sendto defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [45] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_INT, ARG_PTR, ARG_INT }, /* 45: recvfrom defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [46] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 46: sendmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [47] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 47: recvmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [48] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 48: shutdown defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [49] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 49: bind defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [50] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 50: listen defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [51] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 51: getsockname defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [52] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 52: getpeername defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [53] = { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 53: socketpair defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [54] = { ARG_FD, ARG_INT, ARG_INT, ARG_STR, ARG_INT, ARG_NONE }, /* 54: setsockopt defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [55] = { ARG_FD, ARG_INT, ARG_INT, ARG_STR, ARG_INT, ARG_NONE }, /* 55: getsockopt defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [56] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_INT, ARG_LONG, ARG_NONE }, /* 56: clone defined_in=/home/user/LUNIX/linux-6.1.54/kernel/fork.c */
    [57] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 57: fork defined_in=/home/user/LUNIX/linux-6.1.54/kernel/fork.c */
    [58] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 58: vfork defined_in=/home/user/LUNIX/linux-6.1.54/kernel/fork.c */
    [59] = { ARG_STR, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 59: execve defined_in=/home/user/LUNIX/linux-6.1.54/fs/exec.c */
    [60] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 60: exit defined_in=/home/user/LUNIX/linux-6.1.54/kernel/exit.c */
    [61] = { ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE }, /* 61: wait4 defined_in=/home/user/LUNIX/linux-6.1.54/kernel/exit.c */
    [62] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 62: kill defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [63] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 63: uname defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [64] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 64: semget defined_in=/home/user/LUNIX/linux-6.1.54/ipc/sem.c */
    [65] = { ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 65: semop defined_in=/home/user/LUNIX/linux-6.1.54/ipc/sem.c */
    [66] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 66: semctl defined_in=/home/user/LUNIX/linux-6.1.54/ipc/sem.c */
    [67] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 67: shmdt defined_in=/home/user/LUNIX/linux-6.1.54/ipc/shm.c */
    [68] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 68: msgget defined_in=/home/user/LUNIX/linux-6.1.54/ipc/msg.c */
    [69] = { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 69: msgsnd defined_in=/home/user/LUNIX/linux-6.1.54/ipc/msg.c */
    [70] = { ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE }, /* 70: msgrcv defined_in=/home/user/LUNIX/linux-6.1.54/ipc/msg.c */
    [71] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 71: msgctl defined_in=/home/user/LUNIX/linux-6.1.54/ipc/msg.c */
    [72] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 72: fcntl defined_in=/home/user/LUNIX/linux-6.1.54/fs/fcntl.c */
    [73] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 73: flock defined_in=/home/user/LUNIX/linux-6.1.54/fs/locks.c */
    [74] = { ARG_FD, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 74: fsync defined_in=/home/user/LUNIX/linux-6.1.54/fs/sync.c */
    [75] = { ARG_FD, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 75: fdatasync defined_in=/home/user/LUNIX/linux-6.1.54/fs/sync.c */
    [76] = { ARG_STR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 76: truncate defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [77] = { ARG_FD, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 77: ftruncate defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [78] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 78: getdents defined_in=/home/user/LUNIX/linux-6.1.54/fs/readdir.c */
    [79] = { ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 79: getcwd defined_in=/home/user/LUNIX/linux-6.1.54/fs/d_path.c */
    [80] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 80: chdir defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [81] = { ARG_FD, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 81: fchdir defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [82] = { ARG_STR, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 82: rename defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [83] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 83: mkdir defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [84] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 84: rmdir defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [85] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 85: creat defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [86] = { ARG_STR, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 86: link defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [87] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 87: unlink defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [88] = { ARG_STR, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 88: symlink defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [89] = { ARG_STR, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 89: readlink defined_in=/home/user/LUNIX/linux-6.1.54/fs/stat.c */
    [90] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 90: chmod defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [91] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 91: fchmod defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [92] = { ARG_STR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 92: chown defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [93] = { ARG_FD, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 93: fchown defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [94] = { ARG_STR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 94: lchown defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [95] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 95: umask defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [96] = { ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 96: gettimeofday defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/time.c */
    [97] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 97: getrlimit defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [98] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 98: getrusage defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [99] = { ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 99: sysinfo defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [100] = { ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 100: times defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [101] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 101: ptrace defined_in=/home/user/LUNIX/linux-6.1.54/kernel/ptrace.c */
    [102] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 102: getuid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [103] = { ARG_INT, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 103: syslog defined_in=/home/user/LUNIX/linux-6.1.54/kernel/printk/printk.c */
    [104] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 104: getgid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [105] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 105: setuid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [106] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 106: setgid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [107] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 107: geteuid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [108] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 108: getegid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [109] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 109: setpgid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [110] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 110: getppid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [111] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 111: getpgrp defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [112] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 112: setsid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [113] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 113: setreuid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [114] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 114: setregid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [115] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 115: getgroups defined_in=/home/user/LUNIX/linux-6.1.54/kernel/groups.c */
    [116] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 116: setgroups defined_in=/home/user/LUNIX/linux-6.1.54/kernel/groups.c */
    [117] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 117: setresuid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [118] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 118: getresuid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [119] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 119: setresgid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [120] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 120: getresgid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [121] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 121: getpgid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [122] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 122: setfsuid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [123] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 123: setfsgid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [124] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 124: getsid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [125] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 125: capget defined_in=/home/user/LUNIX/linux-6.1.54/kernel/capability.c */
    [126] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 126: capset defined_in=/home/user/LUNIX/linux-6.1.54/kernel/capability.c */
    [127] = { ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 127: rt_sigpending defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [128] = { ARG_PTR, ARG_PTR, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE }, /* 128: rt_sigtimedwait defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [129] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 129: rt_sigqueueinfo defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [130] = { ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 130: rt_sigsuspend defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [131] = { ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 131: sigaltstack defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [132] = { ARG_STR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 132: utime defined_in=/home/user/LUNIX/linux-6.1.54/fs/utimes.c */
    [133] = { ARG_STR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 133: mknod defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [134] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 134: uselib defined_in=/home/user/LUNIX/linux-6.1.54/fs/exec.c */
    [135] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 135: personality defined_in=/home/user/LUNIX/linux-6.1.54/kernel/exec_domain.c */
    [136] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 136: ustat defined_in=/home/user/LUNIX/linux-6.1.54/fs/statfs.c */
    [137] = { ARG_STR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 137: statfs defined_in=/home/user/LUNIX/linux-6.1.54/fs/statfs.c */
    [138] = { ARG_FD, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 138: fstatfs defined_in=/home/user/LUNIX/linux-6.1.54/fs/statfs.c */
    [139] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 139: sysfs defined_in=/home/user/LUNIX/linux-6.1.54/fs/filesystems.c */
    [140] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 140: getpriority defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [141] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 141: setpriority defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [142] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 142: sched_setparam defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [143] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 143: sched_getparam defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [144] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 144: sched_setscheduler defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [145] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 145: sched_getscheduler defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [146] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 146: sched_get_priority_max defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [147] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 147: sched_get_priority_min defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [148] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 148: sched_rr_get_interval defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [149] = { ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 149: mlock defined_in=/home/user/LUNIX/linux-6.1.54/mm/mlock.c */
    [150] = { ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 150: munlock defined_in=/home/user/LUNIX/linux-6.1.54/mm/mlock.c */
    [151] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 151: mlockall defined_in=/home/user/LUNIX/linux-6.1.54/mm/mlock.c */
    [152] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 152: munlockall defined_in=/home/user/LUNIX/linux-6.1.54/mm/mlock.c */
    [153] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 153: vhangup defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [154] = { ARG_INT, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 154: modify_ldt defined_in=/home/user/LUNIX/linux-6.1.54/arch/x86/um/ldt.c */
    [155] = { ARG_STR, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 155: pivot_root defined_in=/home/user/LUNIX/linux-6.1.54/fs/namespace.c */
    [156] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 156: _sysctl defined_in=/home/user/LUNIX/linux-6.1.54/arch/s390/kernel/syscall.c */
    [157] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_LONG, ARG_LONG, ARG_NONE }, /* 157: prctl defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [158] = { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 158: arch_prctl defined_in=/home/user/LUNIX/linux-6.1.54/arch/x86/um/syscalls_32.c */
    [159] = { ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 159: adjtimex defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/time.c */
    [160] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 160: setrlimit defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [161] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 161: chroot defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [162] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 162: sync defined_in=/home/user/LUNIX/linux-6.1.54/fs/sync.c */
    [163] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 163: acct defined_in=/home/user/LUNIX/linux-6.1.54/kernel/acct.c */
    [164] = { ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 164: settimeofday defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/time.c */
    [165] = { ARG_STR, ARG_STR, ARG_STR, ARG_INT, ARG_PTR, ARG_NONE }, /* 165: mount defined_in=/home/user/LUNIX/linux-6.1.54/fs/namespace.c */
    [166] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 166: umount2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/namespace.c */
    [167] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 167: swapon defined_in=/home/user/LUNIX/linux-6.1.54/mm/swapfile.c */
    [168] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 168: swapoff defined_in=/home/user/LUNIX/linux-6.1.54/mm/swapfile.c */
    [169] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 169: reboot defined_in=/home/user/LUNIX/linux-6.1.54/kernel/reboot.c */
    [170] = { ARG_STR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 170: sethostname defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [171] = { ARG_STR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 171: setdomainname defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [172] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 172: iopl defined_in=/home/user/LUNIX/linux-6.1.54/arch/x86/kernel/ioport.c */
    [173] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 173: ioperm defined_in=/home/user/LUNIX/linux-6.1.54/arch/x86/kernel/ioport.c */
    [174] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 174: create_module */
    [175] = { ARG_PTR, ARG_LONG, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 175: init_module defined_in=/home/user/LUNIX/linux-6.1.54/kernel/module/main.c */
    [176] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 176: delete_module defined_in=/home/user/LUNIX/linux-6.1.54/kernel/module/main.c */
    [177] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 177: get_kernel_syms */
    [178] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 178: query_module */
    [179] = { ARG_INT, ARG_STR, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE }, /* 179: quotactl defined_in=/home/user/LUNIX/linux-6.1.54/fs/quota/quota.c */
    [180] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 180: nfsservctl */
    [181] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 181: getpmsg */
    [182] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 182: putpmsg */
    [183] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 183: afs_syscall */
    [184] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 184: tuxcall */
    [185] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 185: security */
    [186] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 186: gettid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [187] = { ARG_FD, ARG_INT, ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE }, /* 187: readahead defined_in=/home/user/LUNIX/linux-6.1.54/arch/sparc/kernel/sys_sparc32.c */
    [188] = { ARG_STR, ARG_STR, ARG_PTR, ARG_LONG, ARG_INT, ARG_NONE }, /* 188: setxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [189] = { ARG_STR, ARG_STR, ARG_PTR, ARG_LONG, ARG_INT, ARG_NONE }, /* 189: lsetxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [190] = { ARG_FD, ARG_STR, ARG_PTR, ARG_LONG, ARG_INT, ARG_NONE }, /* 190: fsetxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [191] = { ARG_STR, ARG_STR, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE }, /* 191: getxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [192] = { ARG_STR, ARG_STR, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE }, /* 192: lgetxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [193] = { ARG_FD, ARG_STR, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE }, /* 193: fgetxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [194] = { ARG_STR, ARG_STR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 194: listxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [195] = { ARG_STR, ARG_STR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 195: llistxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [196] = { ARG_FD, ARG_STR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 196: flistxattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [197] = { ARG_STR, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 197: removexattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [198] = { ARG_STR, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 198: lremovexattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [199] = { ARG_FD, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 199: fremovexattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/xattr.c */
    [200] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 200: tkill defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [201] = { ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 201: time defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/time.c */
    [202] = { ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_INT }, /* 202: futex defined_in=/home/user/LUNIX/linux-6.1.54/kernel/futex/syscalls.c */
    [203] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 203: sched_setaffinity defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [204] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 204: sched_getaffinity defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [205] = { ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 205: set_thread_area defined_in=/home/user/LUNIX/linux-6.1.54/arch/mips/kernel/syscall.c */
    [206] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 206: io_setup defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [207] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 207: io_destroy defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [208] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_PTR, ARG_PTR, ARG_NONE }, /* 208: io_getevents defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [209] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 209: io_submit defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [210] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 210: io_cancel defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [211] = { ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 211: get_thread_area defined_in=/home/user/LUNIX/linux-6.1.54/arch/x86/um/tls_32.c */
    [212] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 212: lookup_dcookie */
    [213] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 213: epoll_create defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventpoll.c */
    [214] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 214: epoll_ctl_old */
    [215] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 215: epoll_wait_old */
    [216] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_LONG, ARG_INT, ARG_NONE }, /* 216: remap_file_pages defined_in=/home/user/LUNIX/linux-6.1.54/mm/mmap.c */
    [217] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 217: getdents64 defined_in=/home/user/LUNIX/linux-6.1.54/fs/readdir.c */
    [218] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 218: set_tid_address defined_in=/home/user/LUNIX/linux-6.1.54/kernel/fork.c */
    [219] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 219: restart_syscall defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [220] = { ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE }, /* 220: semtimedop defined_in=/home/user/LUNIX/linux-6.1.54/ipc/sem.c */
    [221] = { ARG_FD, ARG_INT, ARG_INT, ARG_LONG, ARG_INT, ARG_NONE }, /* 221: fadvise64 defined_in=/home/user/LUNIX/linux-6.1.54/arch/sparc/kernel/sys_sparc32.c */
    [222] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 222: timer_create defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [223] = { ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE }, /* 223: timer_settime defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [224] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 224: timer_gettime defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [225] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 225: timer_getoverrun defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [226] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 226: timer_delete defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [227] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 227: clock_settime defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [228] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 228: clock_gettime defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [229] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 229: clock_getres defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [230] = { ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE }, /* 230: clock_nanosleep defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [231] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 231: exit_group defined_in=/home/user/LUNIX/linux-6.1.54/kernel/exit.c */
    [232] = { ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 232: epoll_wait defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventpoll.c */
    [233] = { ARG_INT, ARG_INT, ARG_FD, ARG_PTR, ARG_NONE, ARG_NONE }, /* 233: epoll_ctl defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventpoll.c */
    [234] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 234: tgkill defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [235] = { ARG_STR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 235: utimes defined_in=/home/user/LUNIX/linux-6.1.54/fs/utimes.c */
    [236] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 236: vserver */
    [237] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_LONG, ARG_LONG, ARG_INT }, /* 237: mbind defined_in=/home/user/LUNIX/linux-6.1.54/mm/mempolicy.c */
    [238] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 238: set_mempolicy defined_in=/home/user/LUNIX/linux-6.1.54/mm/mempolicy.c */
    [239] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_PTR, ARG_INT, ARG_NONE }, /* 239: get_mempolicy defined_in=/home/user/LUNIX/linux-6.1.54/mm/mempolicy.c */
    [240] = { ARG_STR, ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE }, /* 240: mq_open defined_in=/home/user/LUNIX/linux-6.1.54/ipc/mqueue.c */
    [241] = { ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 241: mq_unlink defined_in=/home/user/LUNIX/linux-6.1.54/ipc/mqueue.c */
    [242] = { ARG_INT, ARG_STR, ARG_LONG, ARG_INT, ARG_PTR, ARG_NONE }, /* 242: mq_timedsend defined_in=/home/user/LUNIX/linux-6.1.54/ipc/mqueue.c */
    [243] = { ARG_INT, ARG_STR, ARG_LONG, ARG_INT, ARG_PTR, ARG_NONE }, /* 243: mq_timedreceive defined_in=/home/user/LUNIX/linux-6.1.54/ipc/mqueue.c */
    [244] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 244: mq_notify defined_in=/home/user/LUNIX/linux-6.1.54/ipc/mqueue.c */
    [245] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 245: mq_getsetattr defined_in=/home/user/LUNIX/linux-6.1.54/ipc/mqueue.c */
    [246] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 246: kexec_load defined_in=/home/user/LUNIX/linux-6.1.54/kernel/kexec.c */
    [247] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_NONE }, /* 247: waitid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/exit.c */
    [248] = { ARG_STR, ARG_STR, ARG_PTR, ARG_LONG, ARG_INT, ARG_NONE }, /* 248: add_key defined_in=/home/user/LUNIX/linux-6.1.54/security/keys/keyctl.c */
    [249] = { ARG_STR, ARG_STR, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE }, /* 249: request_key defined_in=/home/user/LUNIX/linux-6.1.54/security/keys/keyctl.c */
    [250] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_LONG, ARG_LONG, ARG_NONE }, /* 250: keyctl defined_in=/home/user/LUNIX/linux-6.1.54/security/keys/keyctl.c */
    [251] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 251: ioprio_set defined_in=/home/user/LUNIX/linux-6.1.54/block/ioprio.c */
    [252] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 252: ioprio_get defined_in=/home/user/LUNIX/linux-6.1.54/block/ioprio.c */
    [253] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 253: inotify_init defined_in=/home/user/LUNIX/linux-6.1.54/fs/notify/inotify/inotify_user.c */
    [254] = { ARG_FD, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 254: inotify_add_watch defined_in=/home/user/LUNIX/linux-6.1.54/fs/notify/inotify/inotify_user.c */
    [255] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 255: inotify_rm_watch defined_in=/home/user/LUNIX/linux-6.1.54/fs/notify/inotify/inotify_user.c */
    [256] = { ARG_INT, ARG_LONG, ARG_LONG, ARG_LONG, ARG_NONE, ARG_NONE }, /* 256: migrate_pages defined_in=/home/user/LUNIX/linux-6.1.54/mm/mempolicy.c */
    [257] = { ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 257: openat defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [258] = { ARG_INT, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 258: mkdirat defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [259] = { ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 259: mknodat defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [260] = { ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_INT, ARG_NONE }, /* 260: fchownat defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [261] = { ARG_INT, ARG_STR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 261: futimesat defined_in=/home/user/LUNIX/linux-6.1.54/fs/utimes.c */
    [262] = { ARG_INT, ARG_STR, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 262: newfstatat defined_in=/home/user/LUNIX/linux-6.1.54/fs/stat.c */
    [263] = { ARG_INT, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 263: unlinkat defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [264] = { ARG_INT, ARG_STR, ARG_INT, ARG_STR, ARG_NONE, ARG_NONE }, /* 264: renameat defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [265] = { ARG_INT, ARG_STR, ARG_INT, ARG_STR, ARG_INT, ARG_NONE }, /* 265: linkat defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [266] = { ARG_STR, ARG_INT, ARG_STR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 266: symlinkat defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [267] = { ARG_INT, ARG_STR, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 267: readlinkat defined_in=/home/user/LUNIX/linux-6.1.54/fs/stat.c */
    [268] = { ARG_INT, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 268: fchmodat defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [269] = { ARG_INT, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 269: faccessat defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [270] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_INT }, /* 270: pselect6 defined_in=/home/user/LUNIX/linux-6.1.54/fs/select.c */
    [271] = { ARG_PTR, ARG_INT, ARG_PTR, ARG_PTR, ARG_LONG, ARG_NONE }, /* 271: ppoll defined_in=/home/user/LUNIX/linux-6.1.54/fs/select.c */
    [272] = { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 272: unshare defined_in=/home/user/LUNIX/linux-6.1.54/kernel/fork.c */
    [273] = { ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 273: set_robust_list defined_in=/home/user/LUNIX/linux-6.1.54/kernel/futex/syscalls.c */
    [274] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 274: get_robust_list defined_in=/home/user/LUNIX/linux-6.1.54/kernel/futex/syscalls.c */
    [275] = { ARG_INT, ARG_LONGLONG, ARG_INT, ARG_LONGLONG, ARG_LONG, ARG_INT }, /* 275: splice defined_in=/home/user/LUNIX/linux-6.1.54/fs/splice.c */
    [276] = { ARG_INT, ARG_INT, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE }, /* 276: tee defined_in=/home/user/LUNIX/linux-6.1.54/fs/splice.c */
    [277] = { ARG_FD, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT }, /* 277: sync_file_range defined_in=/home/user/LUNIX/linux-6.1.54/arch/sparc/kernel/sys_sparc32.c */
    [278] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE }, /* 278: vmsplice defined_in=/home/user/LUNIX/linux-6.1.54/fs/splice.c */
    [279] = { ARG_INT, ARG_LONG, ARG_PTR, ARG_INT, ARG_INT, ARG_INT }, /* 279: move_pages defined_in=/home/user/LUNIX/linux-6.1.54/mm/migrate.c */
    [280] = { ARG_INT, ARG_STR, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 280: utimensat defined_in=/home/user/LUNIX/linux-6.1.54/fs/utimes.c */
    [281] = { ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_INT }, /* 281: epoll_pwait defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventpoll.c */
    [282] = { ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 282: signalfd defined_in=/home/user/LUNIX/linux-6.1.54/fs/signalfd.c */
    [283] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 283: timerfd_create defined_in=/home/user/LUNIX/linux-6.1.54/fs/timerfd.c */
    [284] = { ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 284: eventfd defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventfd.c */
    [285] = { ARG_FD, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT }, /* 285: fallocate defined_in=/home/user/LUNIX/linux-6.1.54/arch/sparc/kernel/sys_sparc32.c */
    [286] = { ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE }, /* 286: timerfd_settime defined_in=/home/user/LUNIX/linux-6.1.54/fs/timerfd.c */
    [287] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 287: timerfd_gettime defined_in=/home/user/LUNIX/linux-6.1.54/fs/timerfd.c */
    [288] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 288: accept4 defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [289] = { ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 289: signalfd4 defined_in=/home/user/LUNIX/linux-6.1.54/fs/signalfd.c */
    [290] = { ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 290: eventfd2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventfd.c */
    [291] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 291: epoll_create1 defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventpoll.c */
    [292] = { ARG_FD, ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 292: dup3 defined_in=/home/user/LUNIX/linux-6.1.54/fs/file.c */
    [293] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 293: pipe2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/pipe.c */
    [294] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 294: inotify_init1 defined_in=/home/user/LUNIX/linux-6.1.54/fs/notify/inotify/inotify_user.c */
    [295] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_NONE }, /* 295: preadv defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [296] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_NONE }, /* 296: pwritev defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [297] = { ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE }, /* 297: rt_tgsigqueueinfo defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [298] = { ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_NONE }, /* 298: perf_event_open defined_in=/home/user/LUNIX/linux-6.1.54/kernel/events/core.c */
    [299] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_NONE }, /* 299: recvmmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [300] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 300: fanotify_init defined_in=/home/user/LUNIX/linux-6.1.54/fs/notify/fanotify/fanotify_user.c */
    [301] = { ARG_INT, ARG_INT, ARG_LONGLONG, ARG_INT, ARG_STR, ARG_NONE }, /* 301: fanotify_mark defined_in=/home/user/LUNIX/linux-6.1.54/fs/notify/fanotify/fanotify_user.c */
    [302] = { ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE }, /* 302: prlimit64 defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [303] = { ARG_INT, ARG_STR, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE }, /* 303: name_to_handle_at defined_in=/home/user/LUNIX/linux-6.1.54/fs/fhandle.c */
    [304] = { ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 304: open_by_handle_at defined_in=/home/user/LUNIX/linux-6.1.54/fs/fhandle.c */
    [305] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 305: clock_adjtime defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [306] = { ARG_FD, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 306: syncfs defined_in=/home/user/LUNIX/linux-6.1.54/fs/sync.c */
    [307] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 307: sendmmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [308] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 308: setns defined_in=/home/user/LUNIX/linux-6.1.54/kernel/nsproxy.c */
    [309] = { ARG_PTR, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 309: getcpu defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sys.c */
    [310] = { ARG_INT, ARG_PTR, ARG_LONG, ARG_PTR, ARG_LONG, ARG_INT }, /* 310: process_vm_readv defined_in=/home/user/LUNIX/linux-6.1.54/mm/process_vm_access.c */
    [311] = { ARG_INT, ARG_PTR, ARG_LONG, ARG_PTR, ARG_LONG, ARG_INT }, /* 311: process_vm_writev defined_in=/home/user/LUNIX/linux-6.1.54/mm/process_vm_access.c */
    [312] = { ARG_INT, ARG_INT, ARG_INT, ARG_LONG, ARG_LONG, ARG_NONE }, /* 312: kcmp defined_in=/home/user/LUNIX/linux-6.1.54/kernel/kcmp.c */
    [313] = { ARG_FD, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 313: finit_module defined_in=/home/user/LUNIX/linux-6.1.54/kernel/module/main.c */
    [314] = { ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 314: sched_setattr defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [315] = { ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 315: sched_getattr defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/core.c */
    [316] = { ARG_INT, ARG_STR, ARG_INT, ARG_STR, ARG_INT, ARG_NONE }, /* 316: renameat2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/namei.c */
    [317] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 317: seccomp defined_in=/home/user/LUNIX/linux-6.1.54/kernel/seccomp.c */
    [318] = { ARG_STR, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 318: getrandom defined_in=/home/user/LUNIX/linux-6.1.54/drivers/char/random.c */
    [319] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 319: memfd_create defined_in=/home/user/LUNIX/linux-6.1.54/mm/memfd.c */
    [320] = { ARG_INT, ARG_INT, ARG_LONG, ARG_STR, ARG_INT, ARG_NONE }, /* 320: kexec_file_load defined_in=/home/user/LUNIX/linux-6.1.54/kernel/kexec_file.c */
    [321] = { ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 321: bpf defined_in=/home/user/LUNIX/linux-6.1.54/kernel/bpf/syscall.c */
    [322] = { ARG_FD, ARG_STR, ARG_PTR, ARG_PTR, ARG_INT, ARG_NONE }, /* 322: execveat defined_in=/home/user/LUNIX/linux-6.1.54/fs/exec.c */
    [323] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 323: userfaultfd defined_in=/home/user/LUNIX/linux-6.1.54/fs/userfaultfd.c */
    [324] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 324: membarrier defined_in=/home/user/LUNIX/linux-6.1.54/kernel/sched/membarrier.c */
    [325] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 325: mlock2 defined_in=/home/user/LUNIX/linux-6.1.54/mm/mlock.c */
    [326] = { ARG_INT, ARG_LONGLONG, ARG_INT, ARG_LONGLONG, ARG_LONG, ARG_INT }, /* 326: copy_file_range defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [327] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT }, /* 327: preadv2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [328] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT }, /* 328: pwritev2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [329] = { ARG_LONG, ARG_LONG, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 329: pkey_mprotect defined_in=/home/user/LUNIX/linux-6.1.54/mm/mprotect.c */
    [330] = { ARG_INT, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 330: pkey_alloc defined_in=/home/user/LUNIX/linux-6.1.54/mm/mprotect.c */
    [331] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 331: pkey_free defined_in=/home/user/LUNIX/linux-6.1.54/mm/mprotect.c */
    [332] = { ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_PTR, ARG_NONE }, /* 332: statx defined_in=/home/user/LUNIX/linux-6.1.54/fs/stat.c */
    [333] = { ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR }, /* 333: io_pgetevents defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [334] = { ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 334: rseq defined_in=/home/user/LUNIX/linux-6.1.54/kernel/rseq.c */
    [335] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [336] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [337] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [338] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [339] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [340] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [341] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [342] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [343] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [344] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [345] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [346] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [347] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [348] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [349] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [350] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [351] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [352] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [353] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [354] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [355] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [356] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [357] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [358] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [359] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [360] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [361] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [362] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [363] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [364] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [365] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [366] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [367] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [368] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [369] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [370] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [371] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [372] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [373] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [374] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [375] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [376] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [377] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [378] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [379] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [380] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [381] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [382] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [383] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [384] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [385] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [386] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [387] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [388] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [389] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [390] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [391] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [392] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [393] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [394] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [395] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [396] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [397] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [398] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [399] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [400] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [401] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [402] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [403] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [404] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [405] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [406] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [407] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [408] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [409] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [410] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [411] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [412] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [413] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [414] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [415] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [416] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [417] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [418] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [419] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [420] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [421] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [422] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [423] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [424] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 424: pidfd_send_signal defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [425] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 425: io_uring_setup defined_in=/home/user/LUNIX/linux-6.1.54/io_uring/io_uring.c */
    [426] = { ARG_FD, ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_LONG }, /* 426: io_uring_enter defined_in=/home/user/LUNIX/linux-6.1.54/io_uring/io_uring.c */
    [427] = { ARG_FD, ARG_INT, ARG_NONE, ARG_INT, ARG_NONE, ARG_NONE }, /* 427: io_uring_register defined_in=/home/user/LUNIX/linux-6.1.54/io_uring/io_uring.c */
    [428] = { ARG_INT, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 428: open_tree defined_in=/home/user/LUNIX/linux-6.1.54/fs/namespace.c */
    [429] = { ARG_INT, ARG_STR, ARG_INT, ARG_STR, ARG_INT, ARG_NONE }, /* 429: move_mount defined_in=/home/user/LUNIX/linux-6.1.54/fs/namespace.c */
    [430] = { ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 430: fsopen defined_in=/home/user/LUNIX/linux-6.1.54/fs/fsopen.c */
    [431] = { ARG_FD, ARG_INT, ARG_STR, ARG_PTR, ARG_INT, ARG_NONE }, /* 431: fsconfig defined_in=/home/user/LUNIX/linux-6.1.54/fs/fsopen.c */
    [432] = { ARG_INT, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 432: fsmount defined_in=/home/user/LUNIX/linux-6.1.54/fs/namespace.c */
    [433] = { ARG_INT, ARG_STR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 433: fspick defined_in=/home/user/LUNIX/linux-6.1.54/fs/fsopen.c */
    [434] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 434: pidfd_open defined_in=/home/user/LUNIX/linux-6.1.54/kernel/pid.c */
    [435] = { ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 435: clone3 defined_in=/home/user/LUNIX/linux-6.1.54/kernel/fork.c */
    [436] = { ARG_FD, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 436: close_range defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [437] = { ARG_INT, ARG_STR, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE }, /* 437: openat2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [438] = { ARG_INT, ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 438: pidfd_getfd defined_in=/home/user/LUNIX/linux-6.1.54/kernel/pid.c */
    [439] = { ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 439: faccessat2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/open.c */
    [440] = { ARG_INT, ARG_PTR, ARG_LONG, ARG_INT, ARG_INT, ARG_NONE }, /* 440: process_madvise defined_in=/home/user/LUNIX/linux-6.1.54/mm/madvise.c */
    [441] = { ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_PTR, ARG_INT }, /* 441: epoll_pwait2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/eventpoll.c */
    [442] = { ARG_INT, ARG_STR, ARG_INT, ARG_PTR, ARG_LONG, ARG_NONE }, /* 442: mount_setattr defined_in=/home/user/LUNIX/linux-6.1.54/fs/namespace.c */
    [443] = { ARG_FD, ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE }, /* 443: quotactl_fd defined_in=/home/user/LUNIX/linux-6.1.54/fs/quota/quota.c */
    [444] = { ARG_PTR, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 444: landlock_create_ruleset defined_in=/home/user/LUNIX/linux-6.1.54/security/landlock/syscalls.c */
    [445] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 445: landlock_add_rule defined_in=/home/user/LUNIX/linux-6.1.54/security/landlock/syscalls.c */
    [446] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 446: landlock_restrict_self defined_in=/home/user/LUNIX/linux-6.1.54/security/landlock/syscalls.c */
    [447] = { ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 447: memfd_secret defined_in=/home/user/LUNIX/linux-6.1.54/mm/secretmem.c */
    [448] = { ARG_INT, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 448: process_mrelease defined_in=/home/user/LUNIX/linux-6.1.54/mm/oom_kill.c */
    [449] = { ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE }, /* 449: futex_waitv defined_in=/home/user/LUNIX/linux-6.1.54/kernel/futex/syscalls.c */
    [450] = { ARG_LONG, ARG_LONG, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE }, /* 450: set_mempolicy_home_node defined_in=/home/user/LUNIX/linux-6.1.54/mm/mempolicy.c */
    [451] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [452] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [453] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [454] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [455] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [456] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [457] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [458] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [459] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [460] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [461] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [462] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [463] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [464] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [465] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [466] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [467] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [468] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [469] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [470] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [471] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [472] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [473] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [474] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [475] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [476] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [477] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [478] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [479] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [480] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [481] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [482] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [483] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [484] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [485] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [486] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [487] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [488] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [489] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [490] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [491] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [492] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [493] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [494] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [495] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [496] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [497] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [498] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [499] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [500] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [501] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [502] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [503] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [504] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [505] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [506] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [507] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [508] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [509] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [510] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [511] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* <unused> */
    [512] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_LONG, ARG_PTR, ARG_NONE }, /* 512: rt_sigaction defined_in=/home/user/LUNIX/linux-6.1.54/arch/alpha/kernel/signal.c */
    [513] = { ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 513: rt_sigreturn defined_in=/home/user/LUNIX/linux-6.1.54/arch/arm64/kernel/signal.c */
    [514] = { ARG_FD, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 514: ioctl defined_in=/home/user/LUNIX/linux-6.1.54/fs/ioctl.c */
    [515] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 515: readv defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [516] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE }, /* 516: writev defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [517] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_INT, ARG_PTR, ARG_INT }, /* 517: recvfrom defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [518] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 518: sendmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [519] = { ARG_FD, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE }, /* 519: recvmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [520] = { ARG_STR, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 520: execve defined_in=/home/user/LUNIX/linux-6.1.54/fs/exec.c */
    [521] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 521: ptrace defined_in=/home/user/LUNIX/linux-6.1.54/kernel/ptrace.c */
    [522] = { ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 522: rt_sigpending defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [523] = { ARG_PTR, ARG_PTR, ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE }, /* 523: rt_sigtimedwait defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [524] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 524: rt_sigqueueinfo defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [525] = { ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 525: sigaltstack defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [526] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 526: timer_create defined_in=/home/user/LUNIX/linux-6.1.54/kernel/time/posix-timers.c */
    [527] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 527: mq_notify defined_in=/home/user/LUNIX/linux-6.1.54/ipc/mqueue.c */
    [528] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_NONE, ARG_NONE }, /* 528: kexec_load defined_in=/home/user/LUNIX/linux-6.1.54/kernel/kexec.c */
    [529] = { ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_NONE }, /* 529: waitid defined_in=/home/user/LUNIX/linux-6.1.54/kernel/exit.c */
    [530] = { ARG_PTR, ARG_LONG, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 530: set_robust_list defined_in=/home/user/LUNIX/linux-6.1.54/kernel/futex/syscalls.c */
    [531] = { ARG_INT, ARG_PTR, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 531: get_robust_list defined_in=/home/user/LUNIX/linux-6.1.54/kernel/futex/syscalls.c */
    [532] = { ARG_FD, ARG_PTR, ARG_LONG, ARG_INT, ARG_NONE, ARG_NONE }, /* 532: vmsplice defined_in=/home/user/LUNIX/linux-6.1.54/fs/splice.c */
    [533] = { ARG_INT, ARG_LONG, ARG_PTR, ARG_INT, ARG_INT, ARG_INT }, /* 533: move_pages defined_in=/home/user/LUNIX/linux-6.1.54/mm/migrate.c */
    [534] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_NONE }, /* 534: preadv defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [535] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_NONE }, /* 535: pwritev defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [536] = { ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE }, /* 536: rt_tgsigqueueinfo defined_in=/home/user/LUNIX/linux-6.1.54/kernel/signal.c */
    [537] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_NONE }, /* 537: recvmmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [538] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_NONE, ARG_NONE }, /* 538: sendmmsg defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [539] = { ARG_INT, ARG_PTR, ARG_LONG, ARG_PTR, ARG_LONG, ARG_INT }, /* 539: process_vm_readv defined_in=/home/user/LUNIX/linux-6.1.54/mm/process_vm_access.c */
    [540] = { ARG_INT, ARG_PTR, ARG_LONG, ARG_PTR, ARG_LONG, ARG_INT }, /* 540: process_vm_writev defined_in=/home/user/LUNIX/linux-6.1.54/mm/process_vm_access.c */
    [541] = { ARG_FD, ARG_INT, ARG_INT, ARG_STR, ARG_INT, ARG_NONE }, /* 541: setsockopt defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [542] = { ARG_FD, ARG_INT, ARG_INT, ARG_STR, ARG_INT, ARG_NONE }, /* 542: getsockopt defined_in=/home/user/LUNIX/linux-6.1.54/net/socket.c */
    [543] = { ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE, ARG_NONE }, /* 543: io_setup defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [544] = { ARG_INT, ARG_INT, ARG_PTR, ARG_NONE, ARG_NONE, ARG_NONE }, /* 544: io_submit defined_in=/home/user/LUNIX/linux-6.1.54/fs/aio.c */
    [545] = { ARG_FD, ARG_STR, ARG_PTR, ARG_PTR, ARG_INT, ARG_NONE }, /* 545: execveat defined_in=/home/user/LUNIX/linux-6.1.54/fs/exec.c */
    [546] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT }, /* 546: preadv2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
    [547] = { ARG_FD, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT }, /* 547: pwritev2 defined_in=/home/user/LUNIX/linux-6.1.54/fs/read_write.c */
};

#endif /* SYSCALL_ARG_TYPES_AUTOGEN */
