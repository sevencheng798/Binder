#ifndef VENDOR_MEDIATEK_HARDWARE_HELLO_V1_0_HELLO_H
#define VENDOR_MEDIATEK_HARDWARE_HELLO_V1_0_HELLO_H

#include <vendor/mediatek/hardware/hello/1.0/IHello.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/Thread.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace hello {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Hello : public IHello, public android::Thread {
    // Methods from IHello follow.
    Return<void> init() override;
    Return<void> release() override;
    Return<void> setCallback(const sp<IHelloCallback>& callback) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    bool threadLoop() override;
    bool mExit;
    sp<IHelloCallback> mCallback;
};

// FIXME: most likely delete, this is only for passthrough implementations
   extern "C" IHello* HIDL_FETCH_IHello(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace hello
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor

#endif  // VENDOR_MEDIATEK_HARDWARE_HELLO_V1_0_HELLO_H
