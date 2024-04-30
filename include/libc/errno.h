// errno.h // ~ eylon

#if !defined(__LIBC_ERRNO_H)
#define __LIBC_ERRNO_H

/* The <errno.h> header file defines symbolic names for each of the possible error
    numbers that may appear in errno. Valid error numbers are all positive numbers. 
    
    A common mistake is to do:

    if (somecall() == -1) {
        printf("somecall() failed\n");
        if (errno == ...) { ... }
    }

    where errno no longer needs to have the value it had upon return
    from somecall() (i.e., it may have been changed by the
    printf). If the value of errno should be preserved across a
    library call, it must be saved:

    if (somecall() == -1) {
        int errsv = errno;
        printf("somecall() failed\n");
        if (errsv == ...) { ... }
    }
*/

extern int errno;

#define EPERM               1       // Operation not permitted
#define ENOENT              2       // No such file or directory
#define ESRCH               3       // No such process
#define EINTR               4       // Interrupted system call
#define EIO                 5       // Input/output error
#define ENXIO               6       // No such device or address
#define E2BIG               7       // Argument list too long
#define ENOEXEC             8       // Exec format error
#define EBADF               9       // Bad file descriptor
#define ECHILD              10      // No child processes
#define EAGAIN              11      // Resource temporarily unavailable
#define EWOULDBLOCK         11      // Resource temporarily unavailable
#define ENOMEM              12      // Cannot allocate memory
#define EACCES              13      // Permission denied
#define EFAULT              14      // Bad address
#define ENOTBLK             15      // Block device required
#define EBUSY               16      // Device or resource busy
#define EEXIST              17      // File exists
#define EXDEV               18      // Invalid cross-device link
#define ENODEV              19      // No such device
#define ENOTDIR             20      // Not a directory
#define EISDIR              21      // Is a directory
#define EINVAL              22      // Invalid argument
#define ENFILE              23      // Too many open files in system
#define EMFILE              24      // Too many open files
#define ENOTTY              25      // Inappropriate ioctl for device
#define ETXTBSY             26      // Text file busy
#define EFBIG               27      // File too large
#define ENOSPC              28      // No space left on device
#define ESPIPE              29      // Illegal seek
#define EROFS               30      // Read-only file system
#define EMLINK              31      // Too many links
#define EPIPE               32      // Broken pipe
#define EDOM                33      // Numerical argument out of domain
#define ERANGE              34      // Numerical result out of range
#define EDEADLK             35      // Resource deadlock avoided
#define EDEADLOCK           35      // Resource deadlock avoided
#define ENAMETOOLONG        36      // File name too long
#define ENOLCK              37      // No locks available
#define ENOSYS              38      // Function not implemented
#define ENOTEMPTY           39      // Directory not empty
#define ELOOP               40      // Too many levels of symbolic links
#define ENOMSG              42      // No message of desired type
#define EIDRM               43      // Identifier removed
#define ECHRNG              44      // Channel number out of range
#define EL2NSYNC            45      // Level 2 not synchronized
#define EL3HLT              46      // Level 3 halted
#define EL3RST              47      // Level 3 reset
#define ELNRNG              48      // Link number out of range
#define EUNATCH             49      // Protocol driver not attached
#define ENOCSI              50      // No CSI structure available
#define EL2HLT              51      // Level 2 halted
#define EBADE               52      // Invalid exchange
#define EBADR               53      // Invalid request descriptor
#define EXFULL              54      // Exchange full
#define ENOANO              55      // No anode
#define EBADRQC             56      // Invalid request code
#define EBADSLT             57      // Invalid slot
#define EBFONT              59      // Bad font file format
#define ENOSTR              60      // Device not a stream
#define ENODATA             61      // No data available
#define ETIME               62      // Timer expired
#define ENOSR               63      // Out of streams resources
#define ENONET              64      // Machine is not on the network
#define ENOPKG              65      // Package not installed
#define EREMOTE             66      // Object is remote
#define ENOLINK             67      // Link has been severed
#define EADV                68      // Advertise error
#define ESRMNT              69      // Srmount error
#define ECOMM               70      // Communication error on send
#define EPROTO              71      // Protocol error
#define EMULTIHOP           72      // Multihop attempted
#define EDOTDOT             73      // RFS specific error
#define EBADMSG             74      // Bad message
#define EOVERFLOW           75      // Value too large for defined data type
#define ENOTUNIQ            76      // Name not unique on network
#define EBADFD              77      // File descriptor in bad state
#define EREMCHG             78      // Remote address changed
#define ELIBACC             79      // Can not access a needed shared library
#define ELIBBAD             80      // Accessing a corrupted shared library
#define ELIBSCN             81      // .lib section in a.out corrupted
#define ELIBMAX             82      // Attempting to link in too many shared libraries
#define ELIBEXEC            83      // Cannot exec a shared library directly
#define EILSEQ              84      // Invalid or incomplete multibyte or wide character
#define ERESTART            85      // Interrupted system call should be restarted
#define ESTRPIPE            86      // Streams pipe error
#define EUSERS              87      // Too many users
#define ENOTSOCK            88      // Socket operation on non-socket
#define EDESTADDRREQ        89      // Destination address required
#define EMSGSIZE            90      // Message too long
#define EPROTOTYPE          91      // Protocol wrong type for socket
#define ENOPROTOOPT         92      // Protocol not available
#define EPROTONOSUPPORT     93      // Protocol not supported
#define ESOCKTNOSUPPORT     94      // Socket type not supported
#define ENOTSUP             95      // Operation not supported
#define EOPNOTSUPP          95      // Operation not supported
#define EPFNOSUPPORT        96      // Protocol family not supported
#define EAFNOSUPPORT        97      // Address family not supported by protocol
#define EADDRINUSE          98      // Address already in use
#define EADDRNOTAVAIL       99      // Cannot assign requested address
#define ENETDOWN            100     // Network is down
#define ENETUNREACH         101     // Network is unreachable
#define ENETRESET           102     // Network dropped connection on reset
#define ECONNABORTED        103     // Software caused connection abort
#define ECONNRESET          104     // Connection reset by peer
#define ENOBUFS             105     // No buffer space available
#define EISCONN             106     // Transport endpoint is already connected
#define ENOTCONN            107     // Transport endpoint is not connected
#define ESHUTDOWN           108     // Cannot send after transport endpoint shutdown
#define ETOOMANYREFS        109     // Too many references: cannot splice
#define ETIMEDOUT           110     // Connection timed out
#define ECONNREFUSED        111     // Connection refused
#define EHOSTDOWN           112     // Host is down
#define EHOSTUNREACH        113     // No route to host
#define EALREADY            114     // Operation already in progress
#define EINPROGRESS         115     // Operation now in progress
#define ESTALE              116     // Stale file handle
#define EUCLEAN             117     // Structure needs cleaning
#define ENOTNAM             118     // Not a XENIX named type file
#define ENAVAIL             119     // No XENIX semaphores available
#define EISNAM              120     // Is a named type file
#define EREMOTEIO           121     // Remote I/O error
#define EDQUOT              122     // Disk quota exceeded
#define ENOMEDIUM           123     // No medium found
#define EMEDIUMTYPE         124     // Wrong medium type
#define ECANCELED           125     // Operation canceled
#define ENOKEY              126     // Required key not available
#define EKEYEXPIRED         127     // Key has expired
#define EKEYREVOKED         128     // Key has been revoked
#define EKEYREJECTED        129     // Key was rejected by service
#define EOWNERDEAD          130     // Owner died
#define ENOTRECOVERABLE     131     // State not recoverable
#define ERFKILL             132     // Operation not possible due to RF-kill
#define EHWPOISON           133     // Memory page has hardware error

#endif