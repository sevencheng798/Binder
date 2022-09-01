#ifndef AIDL_GENERATED_ANDROID_NOTIFICATION_BN_NOTIFICATION_GATEWAY_SERVICE_H_
#define AIDL_GENERATED_ANDROID_NOTIFICATION_BN_NOTIFICATION_GATEWAY_SERVICE_H_

#include <binder/IInterface.h>
#include <android/notification/INotificationGatewayService.h>

namespace android {

namespace notification {

class BnNotificationGatewayService : public ::android::BnInterface<INotificationGatewayService> {
public:
::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags = 0) override;
};  // class BnNotificationGatewayService

}  // namespace notification

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NOTIFICATION_BN_NOTIFICATION_GATEWAY_SERVICE_H_
