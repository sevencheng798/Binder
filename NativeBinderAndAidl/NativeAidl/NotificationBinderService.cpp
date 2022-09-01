/*
 * NotificationBinderService.cpp
 *
 *  Created on: May 22, 2018
 *  Author: young
 */

#include <utils/Log.h>
#include <binder/IPCThreadState.h>
#include <binder/Status.h>
#include <chrono>

#include "NotificationBinderService.h"

#undef LOG_TAG
#define LOG_TAG "NotificationBinderService"

namespace android {
namespace notification {

NotificationBinderService::NotificationBinderService() {
	ALOGD("Notification>>NotificationBinderService");
	printf("Notification>>NotificationBinderService");
	int err;

	// Used for periodic test callback function.
	ntid = std::thread(&NotificationBinderService::callbackLoop, this);
}

NotificationBinderService::~NotificationBinderService() {

}
	
void NotificationBinderService::callbackLoop()
{
	while(1) {
		std::this_thread::sleep_for(std::chrono::seconds(5));
		String16 tmp("123abc");
		onClickNotification(tmp);
	}
}

Status NotificationBinderService::addNotification(
	const String16& title, 
	const String16& content, 
	const String16& icon,
	const String16& notificationid, 
	const String16& packageName, 
	int32_t priority, bool isAction){
	
	(void)(content);
	const char* retitle = String8(title).string();
	char re1[strlen(retitle)] ;
	strcpy(re1,retitle);
	const char* reicon = String8(icon).string();
	char re2[strlen(reicon)];
	strcpy(re2,reicon);
	const char* renotificationid = String8(notificationid).string();
	char re3[strlen(renotificationid)];
	strcpy(re3,renotificationid);
	const char* repackageName = String8(packageName).string();
	char re4[strlen(repackageName)];
	strcpy(re4,repackageName);


	ALOGD("Notification>>REQ_ADD_NOTIFICATION"
		  "title:%s icon:%s notificationid:%s packageName:%s priority:%d isAction:%d",
		  re1, re2, re3, re4, priority, isAction);
	return Status::ok();
}
	
Status NotificationBinderService::addPopup(
	const String16& notificationid, 
	const String16& packageName, 
	const String16& icon, 
	const String16& paramsJson) {

	ALOGD("Notification>>REQ_ADD_POPUP" 
		  "notificationid:%s packageName:%s icon:%s paramsJson:%s",
		  (char *)notificationid.string(), (char *)packageName.string(), (char *)icon.string(), (char *)paramsJson.string());
		  
	return Status::ok();
}
	
Status NotificationBinderService::delAllNotification(const String16& packageName){
	ALOGE("Notification>>REQ_DEL_ALL packageName:%s", (char *)packageName.string());
	return Status::ok();
}
	
Status NotificationBinderService::registerNotificationCallback(
	const sp<notification::INotificationGatewayCallback>& callback) {
	std::lock_guard < std::mutex > guard(mutex_);
	if (callback_.get()) {
		ALOGW("Notification>>Failed to register callback, already registered");
		return Status::fromStatusT(ALREADY_EXISTS);
	}
	
	ALOGD("Notification>>Success to register callback");
	callback_ = callback;
	IInterface::asBinder(callback_)->linkToDeath(this);
	return Status::ok();
}
	
//callback and pass on to binder client
void NotificationBinderService::onClickNotification(const String16& notificationid) {
	if (!callback_.get()) {
		ALOGD("Notification>>INotificationGatewayCallback callback_ is null notificationid:%s", (char *)notificationid.string());
		return;
	}
	
	ALOGD("Notification>>onClickNotification");
	Status status = callback_->onClickNotification(notificationid);
}
	
void NotificationBinderService::onDelNotification(const String16& notificationid) {
	if (!callback_.get()) {
		ALOGD("Notification>>INotificationGatewayCallback callback_ is null notificationid:%s", (char *)notificationid.string());
		return;
	}
	
	ALOGD("Notification>>onDelNotification");
	Status status = callback_->onDelNotification(notificationid);
}
	
void NotificationBinderService::binderDied(const wp<IBinder>& /* who */) {
	std::lock_guard < std::mutex > guard(mutex_);
	callback_ = nullptr;
}
	
} // notification
} // android
