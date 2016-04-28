#ifndef UTILS_H
#define UTILS_H
#include "common.h"
#include "stdint.h"
#include "stddef.h"
#include "stdio.h"


/**
 * 判断是存储类型是否是小端存储
 *
 */
EXTERNC bool is_little_endian(void);

/**
 *
 * @param buffer:
 */
EXTERNC uint16_t read16(const uint8_t* buffer);

/**
 *
 * @param buffer:
 * @param value:
 */
EXTERNC void write16(uint8_t* buffer, uint16_t value);

/**
 *
 * @param buffer:
 */
EXTERNC uint32_t read32(const uint8_t* buffer);

/**
 *
 * @param buffer:
 * @param value:
 */
EXTERNC void write32(uint8_t* buffer, uint32_t value);

/**
 *
 * @param buf:
 * @param size:
 */
EXTERNC char* malloc_string(uint8_t* buf, uint32_t size);

/**
 *
 * @param str:
 */
EXTERNC void free_string(char* str);

/**
 *
 * @param out:
 * @param in:
 * @param in_len:
 */
EXTERNC void copy_buffer_to_buffer(unsigned char* out, unsigned char* in,uint16_t in_len);

/**
 *
 * @param bytes:
 */
EXTERNC unsigned int bytetoInt(char* bytes);

/**
 *
 * @param buf:
 * @param len:
 * @param addr:
 */
EXTERNC void hexDump(const char *buf,int len,int addr);

EXTERNC void* my_malloc(uint32_t size, uint32_t hint);

EXTERNC void my_free(void* buffer);


#endif
