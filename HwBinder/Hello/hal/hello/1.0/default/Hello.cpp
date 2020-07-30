#define LOG_TAG     "Example"
#include "Hello.h"
#include <log/log.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace hello {
namespace V1_0 {
namespace implementation {

// Methods from IHello follow.
Return<void> Hello::init() {
    // TODO implement
    mExit = false;
    run("Hello example");
    return Void();
}

Return<void> Hello::release() {
    // TODO implement
    mExit = true;
    return Void();
}

Return<void> Hello::setCallback(const sp<IHelloCallback>& callback) {
    // TODO implement
    mCallback = callback;
    if(mCallback != nullptr) {
        ALOGD("setCallback: done!");
    }
    return Void();
}

bool Hello::threadLoop()
{
    static int32_t count = 0;
    HalEvent event;
    while(!mExit) {
    ::sleep(1);
    event.value = count ++;
    if(mCallback != nullptr) {
        mCallback->onNotify(event);
    }
    }
    ALOGD("threadLoop: exit");
    return false;
}

// Methods from ::android::hidl::base::V1_0::IBase follow.

IHello* HIDL_FETCH_IHello(const char* /* name */) {
    return new Hello();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace hello
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor
