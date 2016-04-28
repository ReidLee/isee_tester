include $(TDS_SDK_ROOT)/build/depend.mk

SRC_CC = ./src/gptee_ta.cc



MY_CFLAGS = -DLOG_LV_INFO \
			-I$(INCLUDE_PLATFORM_PATH) \
			-I$(INCLUDE_CONTRIB) \
		   	$(INCLUDE_PLATFORM_BTA) \
			$(INCLUDE_REE_CLIENT_API) \
			$(INCLUDE_PLATFORM_BASE) \
           	$(INCLUDE_PLATFORM_TS) \
           	$(INCLUDE_PLATFORM_TIME) \
           	$(INCLUDE_PLATFORM_ALIPAY) \
			$(INCLUDE_PLATFORM_FP) \
			$(INCLUDE_PLATFORM_GP) \
			-Iinclude \
			

#			-DOPENSSL_NO_EC -DOPENSSL_NO_ECDSA -DOPENSSL_NO_ECDH -DOPENSSL_NO_SHA512 -DOPENSSL_NO_RC4 -DOPENSSL_NO_DH -DOPENSSL_NO_OCSP

MY_LDFLAGS = -lcunit \
	     -L$(LIB_PLATFORM_PATH) -lmatrix_s -lutsem \
	     	$(LIB_PLATFORM_BTA) \
	     	$(LIB_PLATFORM_COMMON) \
		    $(LIB_PLATFORM_BASE) \
		    $(LIB_PLATFORM_TS) \
		    $(LIB_PLATFORM_ALIPAY) \
		    $(LIB_PLATFORM_FP) \
			$(LIB_PLATFORM_GP)
TARGET = gptee_ta

# 是否用动态库链接
MODE = static
# MODE = shared

include $(TDS_SDK_ROOT)/build/prog.mk
# include $(TDS_SDK_ROOT)/build/lib.mk
