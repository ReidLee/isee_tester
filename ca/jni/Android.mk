LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
include $(TDS_SDK_ROOT)/build/depend.mk

LOCAL_MODULE    := tee_env_checker

LOCAL_SRC_FILES := src/gptee_env_check_main.c \
					src/fp_env_check_main.c \
					src/utils.c \
					src/main.c \


LOCAL_CFLAGS += -pie -fPIE
LOCAL_LDFLAGS += -pie -fPIE

LOCAL_C_INCLUDES += $(CA_INCLUDE_REE_CLIENT_API) \
					$(LOCAL_PATH)/include


LOCAL_LDLIBS := $(CA_LIB_REE_CLIENT_API)

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)
   LOCAL_MODULE := mtee
   LOCAL_SRC_FILES := libs/libmtee.so
include $(PREBUILT_SHARED_LIBRARY)
