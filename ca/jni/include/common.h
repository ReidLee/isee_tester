#ifndef COMMON_H
#define COMMON_H

#define EXTERNC_BEGIN  extern "C"{
#define EXTERNC_END }
#if defined(__cplusplus)
    #define EXTERNC extern "C"
#else
    #define EXTERNC
#endif  // defined(__cplusplus)

typedef enum {
    false,
    true
} bool;





#define UT_FP_ENTRY_IOCTL_DEVICE "/dev/teei_fp"
#define UT_FP_ENTRY_IOCTL_MAGIC_NO _IO(0x775A777E,0x2)
#define IOCTL_BUFFER_SIZE 1024 * 512





#endif //end of COMMON_H
