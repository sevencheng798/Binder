// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
#ifndef _IFIRST_BINDER_TEST_H
#define _IFIRST_BINDER_TEST_H

#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

namespace android {

#define FIRST_SERVICE_NAME "first.binder.service"

// Binder Interface
class IFirstBinder : public IInterface {
public:	
	DECLARE_META_INTERFACE(FirstBinder); // declare macro
	
	virtual int setName(const String8& name) = 0;
	virtual String8 getName() = 0;
	virtual int add(int a, int b) = 0;
	virtual int total() = 0;
	
};

// Server -> BBinder 
class BnFirstBinder : public BnInterface<IFirstBinder> {
public:
	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);  
};

} // namespace android
#endif