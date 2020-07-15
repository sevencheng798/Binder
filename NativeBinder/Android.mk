# 定义当前路径
LOCAL_PATH := $(call my-dir)
 
# 清空变量
include $(CLEAR_VARS)

# 设置binder设备节点
LOCAL_CFLAGS += -DVENDORSERVICES

# 设置依赖库
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
	liblog \
    libbinder

# 输出模块名称	
LOCAL_MODULE := FirstBinderClient

# 源文件
LOCAL_SRC_FILES := \
    BpFirstBinder.cpp \
	FirstBinderClientTest.cpp 
   
# 编译选项类型
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
  
include $(CLEAR_VARS)
LOCAL_CFLAGS += -DVENDORSERVICES
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
	liblog \
    libbinder
	
LOCAL_MODULE := FirstBinderService
LOCAL_SRC_FILES := \
    BpFirstBinder.cpp \
    FirstBinderServiceTest.cpp
    
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)