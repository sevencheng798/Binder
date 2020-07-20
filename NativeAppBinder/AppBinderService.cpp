// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
// 这是Bnbinder 服务端业务逻辑
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/BinderService.h>
#include <cutils/compiler.h>

#include "IAppBinder.h"

#undef LOG_TAG
#define LOG_TAG "AppBinderService"
using namespace android;

namespace android {

class AppBinderService :
	public BnAppBinder,
	public BinderService<AppBinderService> {
public:
    static const char* getServiceName() ANDROID_API { return "app.binder.service"; }
	
	AppBinderService():totals(0) {};
	virtual int setName(const std::string &name) {
		ALOGD("%s() LINE: %d, name: %s\n", __func__, __LINE__, name.c_str());
		if(name.empty())
			return -1;
		else
			m_name = name;
		
	printf("Now server receive requset from client: [call setName %s]\n", name.c_str());
		return 0;
	};
	
	virtual std::string getName() {
		ALOGD("%s() LINE: %d, name: %s\n", __func__, __LINE__, m_name.c_str());
		printf("Now server receive requset from client: [call getName %s]\n", m_name.c_str());
		return m_name;
	}
	
	virtual int add(int a, int b){
		totals = a+b;
		printf("Now server receive requset from client: [call add %d]\n", totals);
		return totals;
	};
	
	virtual int total() {
		printf("Now server receive requset from client: [call totals %d]\n", totals);
		return totals;
	};
	
private:
	int totals;
	std::string m_name;
};
} // namespace android

int main(int argc, char *argv[]) {
	//sp<ProcessState> proc(ProcessState::self());
	// 使用vndbinder注册
#ifdef VENDORSERVICES
	ProcessState::initWithDriver("/dev/vndbinder");
#endif	
	sp<IServiceManager> sm = defaultServiceManager();

	ALOGD("ServiceManager: %p", sm.get());
	// 注册服务
	ALOGD("%s():line:%d start addServer().", __func__, __LINE__);
	AppBinderService::instantiate();
	
	ALOGD("%s():line:%d start ThreadPool().", __func__, __LINE__);
	ProcessState::self()->startThreadPool();
	
	ALOGD("%s():line:%d start joinThreadPool().", __func__, __LINE__);
	IPCThreadState::self()->joinThreadPool();
	
	ALOGD("%s():line:%d End.", __func__, __LINE__);
}