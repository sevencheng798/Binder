#ifndef AIDL_GENERATED_ANDROID_NOTIFICATION_I_NOTIFICATION_GATEWAY_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_NOTIFICATION_I_NOTIFICATION_GATEWAY_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace notification {

class INotificationGatewayCallback : public ::android::IInterface {
public:
DECLARE_META_INTERFACE(NotificationGatewayCallback)
virtual ::android::binder::Status onClickNotification(const ::android::String16& notificationid) = 0;
virtual ::android::binder::Status onDelNotification(const ::android::String16& notificationid) = 0;
enum Call {
  ONCLICKNOTIFICATION = ::android::IBinder::FIRST_CALL_TRANSACTION + 0,
  ONDELNOTIFICATION = ::android::IBinder::FIRST_CALL_TRANSACTION + 1,
};
};  // class INotificationGatewayCallback

}  // namespace notification

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NOTIFICATION_I_NOTIFICATION_GATEWAY_CALLBACK_H_
