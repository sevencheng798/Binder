// 这是native binder测试程序
// 通过IMemory binder实现数据共享
// 2020-07-15
// Creator @Sven
#include <utils/Log.h>
#include <binder/IServiceManager.h>

#include "ISharedBuffer.h"

#undef LOG_TAG
#define LOG_TAG "BpSharedBuffer"

namespace android {
enum {
	GET_BUFFER = IBinder::FIRST_CALL_TRANSACTION,
	SET_STATUS =IBinder::FIRST_CALL_TRANSACTION +1
};

// Binder proxy代理类Client
class BpSharedBuffer : public BpInterface<ISharedBuffer> {
public:
	BpSharedBuffer(const sp<IBinder> &impl):
		BpInterface<ISharedBuffer>(impl) {};
	
	virtual sp<IMemory> getBuffer() {
		ALOGD("%s() LINE = %d Entry.\n", __func__, __LINE__);
		Parcel data, reply;
		
		// Call BpBinder->transact().
		remote()->transact(GET_BUFFER, data, &reply);
		
		// Get BBinder of IMemory service.
		sp<IBinder> binder = reply.readStrongBinder();
		
		// Get MemoryBase of BpMemory of IMemory.
		sp<IMemory> mb = interface_cast<IMemory>(binder);
		
		ALOGD("%s() LINE = %d Leave.\n", __func__, __LINE__);
		return mb;
	}
	
	virtual void setStatus(int status) {
		ALOGD("%s() LINE = %d Entry.\n", __func__, __LINE__);
		Parcel data, reply;
		data.writeInt32(status);
		remote()->transact(SET_STATUS, data, &reply);
		ALOGD("%s() LINE = %d Leave.\n", __func__, __LINE__);
	}
};

IMPLEMENT_META_INTERFACE(SharedBuffer, SHARED_BUFFER_SERVICE_NAME);

status_t BnSharedBuffer::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
	switch(code) {
	case GET_BUFFER:
	{
		sp<IMemory> memory = getBuffer();
		// IInterface::asBinder(memory);
		reply->writeStrongBinder(memory->asBinder(memory));
	}
	break;
	case SET_STATUS:
	{
		setStatus(data.readInt32());
	}
	break;
	default:
		ALOGD("%s() LINE = %d default.\n",__func__, __LINE__);
		return BBinder::onTransact(code, data, reply, flags);
	}
	
	return NO_ERROR;
}

} // namespace android