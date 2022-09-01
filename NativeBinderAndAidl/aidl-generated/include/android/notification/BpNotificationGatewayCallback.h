#ifndef AIDL_GENERATED_ANDROID_NOTIFICATION_BP_NOTIFICATION_GATEWAY_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_NOTIFICATION_BP_NOTIFICATION_GATEWAY_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/notification/INotificationGatewayCallback.h>

namespace android {

namespace notification {

class BpNotificationGatewayCallback : public ::android::BpInterface<INotificationGatewayCallback> {
public:
explicit BpNotificationGatewayCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
virtual ~BpNotificationGatewayCallback() = default;
::android::binder::Status onClickNotification(const ::android::String16& notificationid) override;
::android::binder::Status onDelNotification(const ::android::String16& notificationid) override;
};  // class BpNotificationGatewayCallback

}  // namespace notification

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NOTIFICATION_BP_NOTIFICATION_GATEWAY_CALLBACK_H_
