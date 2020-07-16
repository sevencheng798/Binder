// 这是native binder测试程序
// 通过IMemory binder实现数据共享
// 2020-07-15
// Creator @Sven

#ifndef _ISHARED_BUFFER_H
#define _ISHARED_BUFFER_H

#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/MemoryBase.h>
#include <binder/MemoryHeapBase.h>

#define SHARED_BUFFER_SERVICE_NAME "audio.shared.buffer.service"
using namespace android;

namespace android {
class ISharedBuffer : public IInterface {
public:
	DECLARE_META_INTERFACE(SharedBuffer); // declare macro

	virtual sp<IMemory> getBuffer() = 0;
	virtual void setStatus(int status) = 0;
};

class BnSharedBuffer : public BnInterface<ISharedBuffer> {
public:
	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
};

} // namespace android

#endif