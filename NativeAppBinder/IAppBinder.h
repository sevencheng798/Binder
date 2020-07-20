// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
#ifndef _IAPP_BINDER_INTERFACE_H
#define _IAPP_BINDER_INTERFACE_H

#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

namespace android {

#define APP_SERVICE_NAME "app.binder.service"

// Binder Interface
class IAppBinder : public IInterface {
public:	
	DECLARE_META_INTERFACE(AppBinder); // declare macro
	
	virtual int setName(const std::string& name) = 0;
	virtual std::string getName() = 0;
	virtual int add(int a, int b) = 0;
	virtual int total() = 0;
	
};

// Server -> BBinder 
class BnAppBinder : public BnInterface<IAppBinder> {
public:
	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);  
};
} // namespace android
#endif // _IAPP_BINDER_INTERFACE_H