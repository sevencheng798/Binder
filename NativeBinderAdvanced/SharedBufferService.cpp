// 这是native binder测试程序
// 2020-07-15
// Creator @Sven
// 这是Bnbinder 服务端业务逻辑

#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/BinderService.h>
#include <cutils/compiler.h>

#include "ISharedBuffer.h"

#undef LOG_TAG
#define LOG_TAG "SharedBufferService"

using namespace android;

#define AUDIO_BUFFER_SIZE (1*1024*1024)

namespace android {
class SharedBufferService : 
	public BnSharedBuffer,
	public BinderService<SharedBufferService> {
public:
	static const char* getServiceName() ANDROID_API { return "audio.shared.buffer.service"; }

	SharedBufferService():mMemory{NULL}, mConnected{0} {
		sp<IMemoryHeap> mh = new MemoryHeapBase(AUDIO_BUFFER_SIZE, 0, "AudioMemoryHeap");
		if(mh != NULL)
		    mMemory = new MemoryBase(mh, 0, AUDIO_BUFFER_SIZE);
			int32_t* data = (int32_t*)mMemory->pointer();
			if(data != NULL)
				*data = 0;
	}
	
	~SharedBufferService() {
		mMemory = NULL;
	}
	
	virtual sp<IMemory> getBuffer() {
		return mMemory;
	}
	
	virtual void setStatus(int status) {
		mConnected = status;
	}

private:	
	sp<IMemory> mMemory;
	int mConnected;
};

}

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
	SharedBufferService::instantiate();
	
	ALOGD("%s():line:%d start ThreadPool().", __func__, __LINE__);
	ProcessState::self()->startThreadPool();
	
	ALOGD("%s():line:%d start joinThreadPool().", __func__, __LINE__);
	IPCThreadState::self()->joinThreadPool();
	
	ALOGD("%s():line:%d End.", __func__, __LINE__);
}

 