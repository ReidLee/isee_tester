#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "log.h"
#include "common.h"



void* my_malloc(uint32_t size, uint32_t hint) {
	ENTER_FUNC
	void *pt = NULL;
	if(size == 0) {
		return NULL;
	}
	pt =  malloc(size);

	if (hint == 0 && pt != NULL) {
		memset(pt, 0, size);
	}
	LEAVE_FUNC
	return  pt;
}

void my_free(void* buffer) {
	if(buffer == NULL) {
		return ;
	}
	free(buffer);
}
/**
 * 判断是存储类型是否是小端存储
 *
 */
bool is_little_endian() {
    uint16_t data = 1;
    return *(uint8_t*)(&data);
}


/**
 *
 * @param buffer:
 */
uint16_t read16(const uint8_t* buffer) {
    if (is_little_endian()) {
        return buffer[1] << 8 | buffer[0];
    }
    return buffer[0] << 8 | buffer[1];
}

/**
 *
 * @param buffer:
 * @param value:
 */
void write16(uint8_t* buffer, uint16_t value) {
    if (is_little_endian()) {
        buffer[0] = value & 0xFF;
        buffer[1] = (value >> 8) & 0xFF;
    } else {
        buffer[1] = value & 0xFF;
        buffer[0] = (value >> 8) & 0xFF;
    }
}
/**
 *
 * @param buffer:
 */
uint32_t read32(const uint8_t* buffer) {
    if (is_little_endian()) {
        return buffer[3] << 24 | buffer[2] << 16 | buffer[1] << 8 | buffer[0];
    }
    return buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3];
}

/**
 *
 * @param buffer:
 * @param value:
 */
void write32(uint8_t* buffer, uint32_t value) {
    if (is_little_endian()) {
        buffer[0] = value & 0xFF;
        buffer[1] = (value >> 8) & 0xFF;
        buffer[2] = (value >> 16) & 0xFF;
        buffer[3] = (value >> 24) & 0xFF;
    } else {
        buffer[3] = value & 0xFF;
        buffer[2] = (value >> 8) & 0xFF;
        buffer[1] = (value >> 16) & 0xFF;
        buffer[0] = (value >> 24) & 0xFF;
    }
}

/**
 *
 * @param buf:
 * @param size:
 */
char* malloc_string(uint8_t* buf, uint32_t size) {
    char* str = (char*)my_malloc(size + 1, 0);
    if (str != NULL) {
        memcpy(str, buf, size);
        str[size] = '\0';
    }
    return str;
}
/**
 *
 * @param str:
 */
void free_string(char* str){
     my_free(str);
 }



 /**
  *
  * @param out:
  * @param in:
  * @param in_len:
  */
void copy_buffer_to_buffer(unsigned char* out, unsigned char* in,uint16_t in_len) {
  unsigned char* pin = in;
  unsigned char* pout = out;
  while (in_len-- > 0) {
    if (is_little_endian() == 1) {
      *pout++ = *pin++;
    } else {
      *pout-- = *pin--;
    }
  }
}


unsigned int bytetoInt(char* bytes) {
	int result;
    if (is_little_endian() == 1){
        result = ((unsigned int) bytes[0] & 0xff) << 0;
    	result += ((unsigned int) bytes[1] & 0xff) << 8;
    	result += ((unsigned int) bytes[2] & 0xff) << 16;
    	result += ((unsigned int) bytes[3] & 0xff) << 24;
    }
    else{
        result = ((unsigned int) bytes[3] & 0xff) << 0;
    	result += ((unsigned int) bytes[2] & 0xff) << 8;
    	result += ((unsigned int) bytes[1] & 0xff) << 16;
    	result += ((unsigned int) bytes[0] & 0xff) << 24;
    }

	return result;
}


void HexDump(const char *buf,int len,int addr) {
    int i,j,k;
    if(!buf || len<0 || addr<0 || addr>len) {

        return ;
    }
    char binstr[512];
    for (i=0;i<len;i++) {
        if (0==(i%16)) {
            sprintf(binstr,"%08x -",i+addr);
            sprintf(binstr,"%s %02x",binstr,(unsigned char)buf[i]);
        } else if (15==(i%16)) {
            sprintf(binstr,"%s %02x",binstr,(unsigned char)buf[i]);
            sprintf(binstr,"%s  ",binstr);
            for (j=i-15;j<=i;j++) {
                sprintf(binstr,"%s%c",binstr,('!'<buf[j]&&buf[j]<='~')?buf[j]:'.');
            }
            printf("%s\n",binstr);
        } else {
            sprintf(binstr,"%s %02x",binstr,(unsigned char)buf[i]);
        }
    }
    if (0!=(i%16)) {
        k=16-(i%16);
        for (j=0;j<k;j++) {
            sprintf(binstr,"%s   ",binstr);
        }
        sprintf(binstr,"%s  ",binstr);
        k=16-k;
        for (j=i-k;j<i;j++) {
            sprintf(binstr,"%s%c",binstr,('!'<buf[j]&&buf[j]<='~')?buf[j]:'.');
        }
        printf("%s\n",binstr);
    }

}
