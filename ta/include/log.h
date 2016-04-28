#ifndef LOG_H
#define LOG_H


#include <stdio.h>
#include "utils.h"



#define __DEBUG__


#define LOG_LEVEL_DEBUG     5
#define LOG_LEVEL_INFO      4
#define LOG_LEVEL_WARN      3
#define LOG_LEVEL_ERROR     2
#define LOG_LEVEL_FATAL     1
#define CURRENT_LEVEL       LOG_LEVEL_DEBUG





#define LOG(level, format, ...)                                                 \
do {                                                                            \
    printf("[IOCTL-TEST][%s]%s[%d]:", level, __FUNCTION__, __LINE__);           \
    printf(format, ##__VA_ARGS__);                                              \
    printf("\n");                                                               \
} while(0)



#define LOG_YELLOW_TPL(level, format, ...)                                          \
do {                                                                                \
    printf("\033[43;33;1m  [IOCTL-TEST][%s]%s[%d]:", level, __FUNCTION__, __LINE__);\
    printf(format, ##__VA_ARGS__);                                                  \
    printf(" \033[0m\n");                                                           \
} while(0)



#define LOG_GREEN_TPL(level, format, ...)                                          \
do {                                                                                \
    printf("\033[38m  [IOCTL-TEST][%s]%s[%d]:", level, __FUNCTION__, __LINE__);\
    printf(format, ##__VA_ARGS__);                                                  \
    printf(" \033[0m\n");                                                           \
} while(0)



#define LOG_ERR_FORMAT(level, format, ...)                                                 \
do {                                                                            \
    printf("\033[31m [IOCTL-TEST][%s]%s[%d]:", level, __FUNCTION__, __LINE__);                 \
    printf(format, ##__VA_ARGS__);                                              \
    printf(" \033[0m\n");                                                               \
} while(0)

// "\033[31m 红色字 \033[0m"

#ifdef __DEBUG__  //线下环境本地打日志
#define LOG_TRACE(format, ...)  LOG("TRACE", format, ##__VA_ARGS__);
#define LOG_DBG(format, ...) if (CURRENT_LEVEL >= LOG_LEVEL_DEBUG) { LOG("DBUG", format, ##__VA_ARGS__); }
#define LOG_INFO(format, ...) if (CURRENT_LEVEL >= LOG_LEVEL_INFO) { LOG("INFO", format, ##__VA_ARGS__); }
#define LOG_WARN(format, ...) if (CURRENT_LEVEL >= LOG_LEVEL_WARN) { LOG("WARN", format, ##__VA_ARGS__); }
#define LOG_ERROR(format, ...) if (CURRENT_LEVEL >= LOG_LEVEL_ERROR) { LOG_ERR_FORMAT("ERRO", format, ##__VA_ARGS__); }
#define LOG_FATAL(format, ...) if (CURRENT_LEVEL >= LOG_LEVEL_FATAL) { LOG("FATA", format, ##__VA_ARGS__); }
#define LOG_YELLOW(format, ...)  LOG_YELLOW_TPL("YELLOW", format, ##__VA_ARGS__);
#define LOG_GREEN(format, ...)  LOG_ERR_FORMAT("GREEN", format, ##__VA_ARGS__);
#define LOG_SUCCESS(format, ...) LOG_YELLOW_TPL("SUCCESS", format, ##__VA_ARGS__);


#define ENTER_FUNC LOG_YELLOW("ENTER %s", __func__);
#define LEAVE_FUNC LOG_YELLOW("LEAVE %s", __func__);
#define TEE_ASSERT(stmt, fmt, ...)             \
    {                                          \
        if (!(stmt)) {                         \
            LOG("A", fmt, ##__VA_ARGS__);      \
        }                                      \
    }

#define HEXDUMP(desc, addr, len) hexdump(desc, addr, len)
#else           //Release版本取消日志
#define LOG_DBG(format, ...)
#define LOG_INFO(format, ...)
#define LOG_WARN(format, ...)
#define LOG_ERROR(format, ...)
#define LOG_FATAL(format, ...)
#define LOG_YELLOW(format, ...)
#define LOG_GREEN(format, ...)
#define LOG_SUCCESS (format, ...)
#define ENTER_FUNC
#define LEAVE_FUNC
#define TEE_ASSERT(stmt, fmt, ...)
#define HEXDUMP(desc, addr, len)
#endif








#endif
