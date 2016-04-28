#ifndef COMMON_H
#define COMMON_H

#define EXTERNC_BEGIN  extern "C"{
#define EXTERNC_END }
#if defined(__cplusplus)
    #define EXTERNC extern "C"
#else
    #define EXTERNC
#endif  // defined(__cplusplus)


#endif //end of COMMON_H
