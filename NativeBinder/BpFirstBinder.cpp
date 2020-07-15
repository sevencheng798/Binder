// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
// 这是Bpbinder 客户端业务逻辑
#include <utils/Log.h>
#include <binder/IServiceManager.h>

#include "IFirstBinder.h"

#undef LOG_TAG
#define LOG_TAG "BpFirstBinder"

using namespace android;
enum {
	REQUEST_SET_NAME = IBinder::FIRST_CALL_TRANSACTION,
	REQUEST_GET_NAME = IBinder::FIRST_CALL_TRANSACTION+1,
	REQUEST_ADD = IBinder::FIRST_CALL_TRANSACTION+2,
	REQUEST_TOTAL = IBinder::FIRST_CALL_TRANSACTION+3
};
	
class BpFirstBinder : public BpInterface<IFirstBinder> {
public:
    BpFirstBinder(const sp<IBinder> &impl)
	: BpInterface<IFirstBinder>(impl) {
		
	};
	
	virtual int setName(const String8 &name) {
		ALOGD("%s():LINE:%d Entry the new name: %s.\n",__func__, __LINE__, name.string());
		Parcel data, reply;
		data.writeString8(name);
		remote()->transact(REQUEST_SET_NAME, data, &reply);
		if(reply.errorCheck())
			return reply.errorCheck();
		else
			ALOGD("%s():LINE:%d reply:%d, Leave.\n", __func__, __LINE__, reply.readInt32());
		
		// success
		return 0;
	};
	
	virtual String8 getName() {
		ALOGD("%s():LINE:%d Entry.\n",__func__, __LINE__);
		Parcel data, reply;
		remote()->transact(REQUEST_GET_NAME, data, &reply);

		//ALOGD("%s():LINE:%d reply:%s, Leave.\n", __func__, __LINE__, reply.readString8().string());
		
		// success
		return reply.readString8();		
	};
	
	virtual int add(int a, int b) {
		ALOGD("%s():LINE:%d Entry.\n",__func__, __LINE__);
		Parcel data, reply;
		data.writeInt32(a);
		data.writeInt32(b);
		remote()->transact(REQUEST_ADD, data, &reply);
		if(reply.errorCheck())
			return reply.errorCheck();
		else
			ALOGD("%s():LINE:%d reply:%d, Leave.\n", __func__, __LINE__, reply.readInt32());
		// success
		return 0;
	};
	
	virtual int total() {
		ALOGD("%s():LINE:%d Entry.\n",__func__, __LINE__);
		Parcel data, reply;
		remote()->transact(REQUEST_TOTAL, data, &reply);
		if(reply.errorCheck())
			return reply.errorCheck();
		else
			ALOGD("%s():LINE:%d total->reply:%d, Leave.\n", __func__, __LINE__, reply.readInt32());		
		
		// success
		return 0;
	};
};

IMPLEMENT_META_INTERFACE(FirstBinder, FIRST_SERVICE_NAME);

status_t BnFirstBinder::onTransact(
	uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
	switch(code) {
		case REQUEST_SET_NAME:
		{
			String8 name = data.readString8();
			int ret = setName(name);
			reply->writeInt32(ret);
		}
		break;
		case REQUEST_GET_NAME:
		{
			String8 name = getName();
			reply->writeString8(name);
		}
		break;
		case REQUEST_ADD:
		{
			int a = data.readInt32();
			int b = data.readInt32();
			int sum = add(a, b);
			reply->writeInt32(sum);
		}
		break;
		case REQUEST_TOTAL:
		{
			int sum = total();
			reply->writeInt32(sum);
		}
		break;
		default:
		{
			ALOGD("%s() LINE = %d, status = %d \n",__func__, __LINE__,data.readInt32() );
			return BBinder::onTransact(code, data, reply, flags);
		}
		break;
	}
	
	return 0;
}

