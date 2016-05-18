include $(TDS_SDK_ROOT)/build/inner_depend.mk

TARGET = fp_ta

SRC_CC = src/utils.cc \
		 src/fp_ta.cc \

MY_CFLAGS =  \
	-Iinclude \
    -I$(INCLUDE_PRIVATE_CONTRIB)/lib_common \
	$(INCLUDE_PLATFORM_FP) \
	-DLOG_LV_DEBUG


MY_LDFLAGS = -lmsg -ldrivers_spi  -L../fpc_ta_lib/obj $(LIB_PLATFORM_FP) $(LIB_PLATFORM_KM) -larm_time
include $(TDS_SDK_ROOT)/build/prog.mk
