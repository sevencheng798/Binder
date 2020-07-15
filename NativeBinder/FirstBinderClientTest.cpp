// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
// 这是客户端测试程序
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>

#include "IFirstBinder.h"

#undef LOG_TAG
#define LOG_TAG "FirstBinderClientTest"

int main(int argc, char**argv) {
	ALOGD("%s():LINE:%d Start.\n",__func__, __LINE__);
#ifdef VENDORSERVICES
	// 我们使用vndbinder节点测试binder通信。因为binder节点有太多的服务，查看log不方便。
    ProcessState::initWithDriver("/dev/vndbinder");
#endif
	sp<IServiceManager> sm = defaultServiceManager();
	ALOGD("ServiceManager: %p", sm.get());
	
	// 获取BBinder
	sp<IBinder> binder = sm->getService(String16(FIRST_SERVICE_NAME));
	if(binder == NULL)
	{
		ALOGE("Failed to get service: %s \n", FIRST_SERVICE_NAME);
		return -1;
	}
	
	// 通过BBinder得到Bn服务
	sp<IFirstBinder> service = interface_cast<IFirstBinder>(binder);
	if(service == NULL)
	{
		return -2;
	}
	ALOGD("%s():LINE:%d start setName(). \n",__func__, __LINE__);
	String8 newName1("SvenCheng");
	service->setName(newName1);
	ALOGD("%s():LINE:%d start getName(). \n",__func__, __LINE__);
	String8 newName = service->getName();
	ALOGD("%s():LINE:%d getName()->%s. \n",__func__, __LINE__, newName.string());
	
	ALOGD("%s():LINE:%d start add(). \n",__func__, __LINE__);
	service->add(5, 6);
	ALOGD("%s():LINE:%d start total(). \n",__func__, __LINE__);
	service->total();
	
	ALOGD("%s():LINE:%d End.\n",__func__, __LINE__);
}