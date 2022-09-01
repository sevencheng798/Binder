# 定义当前路径
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#LOCAL_CFLAGS += -DVENDORSERVICES
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
	liblog \
    libbinder 


LOCAL_CPPFLAGS := -fsigned-char  -v -std=c++11 -fvisibility=hidden -fvisibility-inlines-hidden -Wl,--exclude-libs,ALL -fpermissive
LOCAL_LDLIBS := -landroid -dl -frtti -std=c++11
	
LOCAL_MODULE := NativetestService
LOCAL_SRC_FILES := \
		android/notification/INotificationGatewayCallback.aidl \
		android/notification/INotificationGatewayService.aidl \
		NotificationBinderService.cpp \
		main.cpp

# aidl文件路径，必须指定否则编译会提示找不到aidl文件
LOCAL_AIDL_INCLUDES := $(LOCAL_PATH)/
    
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)