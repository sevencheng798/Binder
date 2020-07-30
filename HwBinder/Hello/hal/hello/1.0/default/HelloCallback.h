#ifndef VENDOR_MEDIATEK_HARDWARE_HELLO_V1_0_HELLOCALLBACK_H
#define VENDOR_MEDIATEK_HARDWARE_HELLO_V1_0_HELLOCALLBACK_H

#include <vendor/mediatek/hardware/hello/1.0/IHelloCallback.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

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

struct HelloCallback : public IHelloCallback {
    // Methods from IHelloCallback follow.
    Return<void> onNotify(const HalEvent& event) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IHelloCallback* HIDL_FETCH_IHelloCallback(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace hello
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor

#endif  // VENDOR_MEDIATEK_HARDWARE_HELLO_V1_0_HELLOCALLBACK_H
