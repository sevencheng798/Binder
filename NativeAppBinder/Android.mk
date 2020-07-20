# 定义当前路径
LOCAL_PATH := $(call my-dir)


# 清空变量
include $(CLEAR_VARS)

# 设置binder设备节点
#LOCAL_CFLAGS += -DVENDORSERVICES

# 设置依赖库
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
	liblog \
    libbinder

# 输出模块名称	
LOCAL_MODULE := AppBinderClient

# 源文件
LOCAL_SRC_FILES := \
    BpAppBinder.cpp \
	AppBinderClient.cpp 
   
# 编译选项类型
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)
#LOCAL_CFLAGS += -DVENDORSERVICES
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
	liblog \
    libbinder
	
LOCAL_MODULE := AppBinderService
LOCAL_SRC_FILES := \
	BpAppBinder.cpp \
    AppBinderService.cpp
    
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
