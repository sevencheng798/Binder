/*
 * NotificationBinderService.h
 *
 *  Created on: May 22, 2018
 *      Author: young
 */

#ifndef NOTIFICATIONBINDERSERVICE_HPP_
#define NOTIFICATIONBINDERSERVICE_HPP_
#include <thread>
#include <android/notification/BnNotificationGatewayService.h>//调用编译自动生成的头文件
#include <android/notification/INotificationGatewayCallback.h>

using namespace android;
using namespace android::binder;
namespace android {
namespace notification {
	
//继承BnNotificationGatewayService ，此文件是自动编译生成，可以通过locate BnNotificationGatewayService找到
//BnNotificationGatewayService 是Service，具体的方法都是在这个里面实现的
class NotificationBinderService: public BnNotificationGatewayService, public IBinder::DeathRecipient {
public:
	NotificationBinderService();
	~NotificationBinderService();

	Status addNotification(
		const String16& title,
		const String16& content,
		const String16& icon,
		const String16& notificationid,
		const String16& packageName,
		int32_t priority,
		bool isAction) override;
		
	Status addPopup(
		const String16& notificationid,
		const String16& packageName,
		const String16& icon,
		const String16& paramsJson) override;
		
	Status delAllNotification(const String16& packageName) override;
	Status registerNotificationCallback(const sp<notification::INotificationGatewayCallback>& callback) override;

	///
	void onClickNotification(const String16& notificationid);
	void onDelNotification(const String16& notificationid);
private:
	NotificationBinderService(const NotificationBinderService&) = delete;
	NotificationBinderService& operator=(const NotificationBinderService&) = delete;

	// @c DeathRecipient methods
	void binderDied(const wp<IBinder>& who) override;
	
	sp<android::notification::INotificationGatewayCallback> callback_;
	
	void callbackLoop();
	std::mutex mutex_;
	std::thread ntid;
};

}
}
#endif 