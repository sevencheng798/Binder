// main.cpp
#include <binder/IServiceManager.h>
#include <binder/BinderService.h>
#include "NotificationBinderService.h"

int main(int argc, char **argv)
{
	//android::sp<ProcessState> proc(ProcessState::self());
	sp<notification::NotificationBinderService> server =
								new notification::NotificationBinderService();
								
	sp<IServiceManager> sm(defaultServiceManager());
	status_t service_status = 
				sm->addService(String16(notification::INotificationGatewayService::SERVICE_NAME()), server, false);

	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
