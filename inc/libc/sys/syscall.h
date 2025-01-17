// sys/syscall.h // ~ eylon

#if !defined(__LIBC_SYSCALL_H)
#define __LIBC_SYSCALL_H

#define SYS_nop         0x00
#define SYS_exit        0x01
#define SYS_fork        0x02
#define SYS_read        0x03
#define SYS_write       0x04
#define SYS_open        0x05
#define SYS_close       0x06
#define SYS_waitpid     0x07
#define SYS_creat       0x08
#define SYS_link        0x09
#define SYS_unlink      0x0a
#define SYS_execve      0x0b
#define SYS_chdir       0x0c
#define SYS_sched_yield	0x9e

#define SYS_int 92      // syscall interrupt number (0x5C)

#endif