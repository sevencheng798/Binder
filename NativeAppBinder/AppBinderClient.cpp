// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
// 这是客户端测试程序
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>

#include "IAppBinder.h"

#undef LOG_TAG
#define LOG_TAG "AppBinderClient"

int main(int argc, char**argv) {
	ALOGD("%s():LINE:%d Start.\n",__func__, __LINE__);
	printf("%s():LINE:%d Start.\n",__func__, __LINE__);
#ifdef VENDORSERVICES
	// 使用vndbinder节点测试binder通信.
    ProcessState::initWithDriver("/dev/vndbinder");
#endif
	sp<IServiceManager> sm = defaultServiceManager();
	ALOGD("ServiceManager: %p", sm.get());
	
	// 获取BpBinder
	sp<IBinder> binder = sm->getService(String16(APP_SERVICE_NAME));
	if(binder == NULL)
	{
		ALOGE("Failed to get service: %s \n", APP_SERVICE_NAME);
		return -1;
	}
	
	// 通过BpBinder得到binder proxy代理Bp服务, 注意BpBinder->mHandler是target of BBinder的Handler
	sp<IAppBinder> service = interface_cast<IAppBinder>(binder);
	if(service == NULL)
	{
		return -2;
	}
	ALOGD("%s():LINE:%d start setName(). \n",__func__, __LINE__);
	std::string newName1("SvenCheng");
	service->setName(newName1);
	ALOGD("%s():LINE:%d start getName(). \n",__func__, __LINE__);
	std::string newName = service->getName();
	ALOGD("%s():LINE:%d getName()->%s. \n",__func__, __LINE__, newName.c_str());
	
	ALOGD("%s():LINE:%d start add(). \n",__func__, __LINE__);
	service->add(5, 6);
	ALOGD("%s():LINE:%d start total(). \n",__func__, __LINE__);
	service->total();
	
	ALOGD("%s():LINE:%d End.\n",__func__, __LINE__);
	printf("%s():LINE:%d End.\n",__func__, __LINE__);
}
