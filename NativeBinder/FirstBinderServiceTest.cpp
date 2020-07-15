// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
// 这是Bnbinder 服务端业务逻辑
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/BinderService.h>
#include <cutils/compiler.h>

#include "IFirstBinder.h"

#undef LOG_TAG
#define LOG_TAG "FirstBinderServiceTest"
using namespace android;

namespace android {
class FirstBinderServiceTest :
	public BnFirstBinder,
	public BinderService<FirstBinderServiceTest> {
public:
    static const char* getServiceName() ANDROID_API { return "first.binder.service"; }
	
	FirstBinderServiceTest():totals(0) {};
	virtual int setName(const String8 &name) {
		ALOGD("%s() LINE: %d, name: %s\n", __func__, __LINE__, name.string());
		if(name.isEmpty())
			return -1;
		else
			m_name = name;
		
		return 0;
	};
	
	virtual String8 getName() {
		ALOGD("%s() LINE: %d, name: %s\n", __func__, __LINE__, m_name.string());
		return m_name;
	}
	
	virtual int add(int a, int b){
		totals = a+b;
		return totals;
	};
	
	virtual int total() {
		return totals;
	};
	
private:
	int totals;
	String8 m_name;
};
} // namespace android

int main(int argc, char *argv[]) {
	//sp<ProcessState> proc(ProcessState::self());
	// 我们使用vndbinder注册
#ifdef VENDORSERVICES
	ProcessState::initWithDriver("/dev/vndbinder");
#endif	
	sp<IServiceManager> sm = defaultServiceManager();

	ALOGD("ServiceManager: %p", sm.get());
	// 注册服务
	ALOGD("%s():line:%d start addServer().", __func__, __LINE__);
	FirstBinderServiceTest::instantiate();
	
	ALOGD("%s():line:%d start ThreadPool().", __func__, __LINE__);
	ProcessState::self()->startThreadPool();
	
	ALOGD("%s():line:%d start joinThreadPool().", __func__, __LINE__);
	IPCThreadState::self()->joinThreadPool();
	
	ALOGD("%s():line:%d End.", __func__, __LINE__);
}