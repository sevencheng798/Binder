#ifndef AIDL_GENERATED_ANDROID_NOTIFICATION_I_NOTIFICATION_GATEWAY_SERVICE_H_
#define AIDL_GENERATED_ANDROID_NOTIFICATION_I_NOTIFICATION_GATEWAY_SERVICE_H_

#include <android/notification/INotificationGatewayCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace notification {

class INotificationGatewayService : public ::android::IInterface {
public:
DECLARE_META_INTERFACE(NotificationGatewayService)
static const ::android::String16& SERVICE_NAME();
virtual ::android::binder::Status addNotification(const ::android::String16& title, const ::android::String16& content, const ::android::String16& icon, const ::android::String16& notificationid, const ::android::String16& packageName, int32_t priority, bool isAction) = 0;
virtual ::android::binder::Status addPopup(const ::android::String16& notificationid, const ::android::String16& packageName, const ::android::String16& icon, const ::android::String16& paramsJson) = 0;
virtual ::android::binder::Status delAllNotification(const ::android::String16& packageName) = 0;
virtual ::android::binder::Status registerNotificationCallback(const ::android::sp<::android::notification::INotificationGatewayCallback>& callback) = 0;
enum Call {
  ADDNOTIFICATION = ::android::IBinder::FIRST_CALL_TRANSACTION + 0,
  ADDPOPUP = ::android::IBinder::FIRST_CALL_TRANSACTION + 1,
  DELALLNOTIFICATION = ::android::IBinder::FIRST_CALL_TRANSACTION + 2,
  REGISTERNOTIFICATIONCALLBACK = ::android::IBinder::FIRST_CALL_TRANSACTION + 3,
};
};  // class INotificationGatewayService

}  // namespace notification

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NOTIFICATION_I_NOTIFICATION_GATEWAY_SERVICE_H_
