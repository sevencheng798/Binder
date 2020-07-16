// 这是native binder测试程序
// 2020-07-15
// Creator @Sven
// 这是Bnbinder 客户端写共享内存业务逻辑

#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/BinderService.h>
#include <cutils/compiler.h>

#include "ISharedBuffer.h"

#undef LOG_TAG
#define LOG_TAG "SharedBufferClientW"

using namespace android;

int main(int argc, char **argv) {
	ALOGD("%s():LINE:%d Start.\n",__func__, __LINE__);
#ifdef VENDORSERVICES
	// 我们使用vndbinder节点测试binder通信。因为binder节点有太多的服务，查看log不方便。
    ProcessState::initWithDriver("/dev/vndbinder");
#endif

	sp<IServiceManager> sm = defaultServiceManager();
	ALOGD("%s() LINE:%d sm.get:%p\n", __func__, __LINE__, sm.get());
	
	// 获取BpBinder	
	sp<IBinder> binder = sm->getService(String16(SHARED_BUFFER_SERVICE_NAME));
	if(binder == NULL) {
		ALOGE("%s() LINE:%d Get binder failed.\n", __func__, __LINE__);
		return -1;
	}
	
	// 通过BpBinder得到binder proxy代理Bp服务, 注意BpBinder->mHandler是target of BBinder的Handler	
	sp<ISharedBuffer> client = interface_cast<ISharedBuffer>(binder);
	if(client == NULL) {
		ALOGE("%s() LINE:%d Get client bp failed.\n", __func__, __LINE__);
		return -1;		
	}
	
	// 获取共享内存Binder
	sp<IMemory> mb = client->getBuffer();
	if(mb == NULL) {
		ALOGE("%s() LINE:%d Get IMemory failed.\n", __func__, __LINE__);
		return -1;
	}
	
	char *buffer = (char *)mb->pointer();
	if(buffer == NULL) {
		ALOGE("%s() LINE:%d Get IMemory->pointer() failed.\n", __func__, __LINE__);
		return -1;		
	}
	
	size_t size = mb->size();
	ALOGD("%s() LINE:%d Get IMemory->size() -> %d\n", __func__, __LINE__, size);
	
	std::string padStr("I am is SharedBuffer example!!!");
	memcpy(buffer, padStr.c_str(), padStr.length());
	
	ALOGD("%s() LINE:%d End.\n", __func__, __LINE__);
    return 0;
}
