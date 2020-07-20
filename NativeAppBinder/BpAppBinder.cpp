// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
// 这是Bpbinder 客户端业务逻辑
#include <utils/Log.h>
#include <binder/IServiceManager.h>

#include "IAppBinder.h"

#undef LOG_TAG
#define LOG_TAG "BpAppBinder"

using namespace android;

enum {
	REQUEST_SET_NAME = IBinder::FIRST_CALL_TRANSACTION,
	REQUEST_GET_NAME = IBinder::FIRST_CALL_TRANSACTION+1,
	REQUEST_ADD = IBinder::FIRST_CALL_TRANSACTION+2,
	REQUEST_TOTAL = IBinder::FIRST_CALL_TRANSACTION+3
};

class BpAppBinder : public BpInterface<IAppBinder> {
public:
    BpAppBinder(const sp<IBinder> &impl)
	: BpInterface<IAppBinder>(impl) {
		
	};
	
	virtual int setName(const std::string &name) {
		ALOGD("%s():LINE:%d Entry the new name: %s.\n",__func__, __LINE__, name.c_str());
		Parcel data, reply;
		
		// Request interface verification.
		data.writeInterfaceToken(this->getInterfaceDescriptor());
		
		data.writeString16(String16(name.c_str()));
		remote()->transact(REQUEST_SET_NAME, data, &reply);
		if(reply.errorCheck())
			return reply.errorCheck();
		else
			ALOGD("%s():LINE:%d reply:%d, Leave.\n", __func__, __LINE__, reply.readInt32());
		
		// success
		return 0;
	};

	virtual std::string getName() {
		ALOGD("%s():LINE:%d Entry.\n",__func__, __LINE__);
		Parcel data, reply;
		// Request interface verification.
		data.writeInterfaceToken(IAppBinder::getInterfaceDescriptor());
		
		remote()->transact(REQUEST_GET_NAME, data, &reply);

		std::string name;
		String16 str16 = reply.readString16();
		String8 str8 = String8(str16);
		name = std::string(str8.string());
		ALOGD("%s():LINE:%d reply:%s, Leave.\n", __func__, __LINE__, name.c_str());
		
		// success
		return name;
	};
	
	virtual int add(int a, int b) {
		ALOGD("%s():LINE:%d Entry.\n",__func__, __LINE__);
		Parcel data, reply;
		
		// Request interface verification.
		data.writeInterfaceToken(IAppBinder::getInterfaceDescriptor());
		
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
		// Request interface verification.
		// 测试不请求接口校验
		//data.writeInterfaceToken(IAppBinder::getInterfaceDescriptor());
		
		remote()->transact(REQUEST_TOTAL, data, &reply);
		if(reply.errorCheck())
			return reply.errorCheck();
		else
			ALOGD("%s():LINE:%d total->reply:%d, Leave.\n", __func__, __LINE__, reply.readInt32());		
		
		// success
		return 0;
	};
};

IMPLEMENT_META_INTERFACE(AppBinder, APP_SERVICE_NAME);

status_t BnAppBinder::onTransact(
	uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
	switch(code) {
		case REQUEST_SET_NAME:
		{
			// interface verification.
			CHECK_INTERFACE(IAppBinder, data, reply);
			
			String16 str16 = data.readString16();
			String8 str8 = String8(str16);
			//printf("Now server receive requset from client: [call setName %s - %s]\n", str16.string(), str8.string());
			int ret = setName(std::string(str8.string()));
			reply->writeInt32(ret);
		}
		break;
		case REQUEST_GET_NAME:
		{
			CHECK_INTERFACE(IAppBinder, data, reply);
			
			std::string name = getName();
			String16 str16 = String16(name.c_str());
			reply->writeString16(str16);
		}
		break;
		case REQUEST_ADD:
		{
			CHECK_INTERFACE(IAppBinder, data, reply);
			
			int a = data.readInt32();
			int b = data.readInt32();
			int sum = add(a, b);
			reply->writeInt32(sum);
		}
		break;
		case REQUEST_TOTAL:
		{
			CHECK_INTERFACE(IAppBinder, data, reply);
			
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
	
	return NO_ERROR;
}
