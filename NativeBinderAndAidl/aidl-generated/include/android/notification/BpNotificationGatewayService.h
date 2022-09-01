#ifndef AIDL_GENERATED_ANDROID_NOTIFICATION_BP_NOTIFICATION_GATEWAY_SERVICE_H_
#define AIDL_GENERATED_ANDROID_NOTIFICATION_BP_NOTIFICATION_GATEWAY_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/notification/INotificationGatewayService.h>

namespace android {

namespace notification {

class BpNotificationGatewayService : public ::android::BpInterface<INotificationGatewayService> {
public:
explicit BpNotificationGatewayService(const ::android::sp<::android::IBinder>& _aidl_impl);
virtual ~BpNotificationGatewayService() = default;
::android::binder::Status addNotification(const ::android::String16& title, const ::android::String16& content, const ::android::String16& icon, const ::android::String16& notificationid, const ::android::String16& packageName, int32_t priority, bool isAction) override;
::android::binder::Status addPopup(const ::android::String16& notificationid, const ::android::String16& packageName, const ::android::String16& icon, const ::android::String16& paramsJson) override;
::android::binder::Status delAllNotification(const ::android::String16& packageName) override;
::android::binder::Status registerNotificationCallback(const ::android::sp<::android::notification::INotificationGatewayCallback>& callback) override;
};  // class BpNotificationGatewayService

}  // namespace notification

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NOTIFICATION_BP_NOTIFICATION_GATEWAY_SERVICE_H_
