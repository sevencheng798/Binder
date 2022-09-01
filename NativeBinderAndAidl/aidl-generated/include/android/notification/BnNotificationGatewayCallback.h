#ifndef AIDL_GENERATED_ANDROID_NOTIFICATION_BN_NOTIFICATION_GATEWAY_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_NOTIFICATION_BN_NOTIFICATION_GATEWAY_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/notification/INotificationGatewayCallback.h>

namespace android {

namespace notification {

class BnNotificationGatewayCallback : public ::android::BnInterface<INotificationGatewayCallback> {
public:
::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags = 0) override;
};  // class BnNotificationGatewayCallback

}  // namespace notification

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NOTIFICATION_BN_NOTIFICATION_GATEWAY_CALLBACK_H_
