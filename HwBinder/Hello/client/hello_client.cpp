#define LOG_TAG     "HelloClient"
#include <log/log.h>
#include <vendor/mediatek/hardware/hello/1.0/types.h>
#include <vendor/mediatek/hardware/hello/1.0/IHello.h>
#include <vendor/mediatek/hardware/hello/1.0/IHelloCallback.h>
#include <hidl/Status.h>
#include <hidl/HidlSupport.h>

using android::sp;
using android::hardware::Return;
using android::hardware::Void;
using vendor::mediatek::hardware::hello::V1_0::HalEvent;
using vendor::mediatek::hardware::hello::V1_0::IHello;
using vendor::mediatek::hardware::hello::V1_0::IHelloCallback;

class HelloCallback: public IHelloCallback {
public:
 HelloCallback() {

}

~HelloCallback() {

}

Return<void> onNotify(const HalEvent& event) {
 ALOGD("onNotify: value = %d", event.value);
 return Void();
}
};

int main(void)
{
 sp<IHello> service = IHello::getService();
 if(service == nullptr) {
 ALOGE("main: failed to get hello service");
 return -1;
 }

 ALOGD("main: get hello service ok");
sp<HelloCallback> callback = new HelloCallback();
service->setCallback(callback);
service->init();

::sleep(10);
service->release();

// 释放完最好等待一会， 因为这个回调接口中定义的方法是oneway必须保证线程安全，
// 在这我们简单延时等待一会，让这个函数指针确保完成， 否则会导致服务端奔溃crash
::sleep(3);

return 0;
}

