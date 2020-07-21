LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(call all-java-files-under, app/src/main/java)
LOCAL_MANIFEST_FILE:= app/src/main/AndroidManifest.xml
LOCAL_RESOURCE_DIR:= $(LOCAL_PATH)/app/src/main/res
LOCAL_PACKAGE_NAME := AppBinderClient
LOCAL_CERTIFICATE := platform
LOCAL_PROGUARD_ENABLED := disabled
LOCAL_DEX_PREOPT := false
include $(BUILD_PACKAGE)

include $(CLEAR_VARS)
# Use the following include to make our test apk.
include $(call all-makefiles-under,$(LOCAL_PATH))