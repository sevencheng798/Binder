#include "HelloCallback.h"

namespace vendor {
namespace mediatek {
namespace hardware {
namespace hello {
namespace V1_0 {
namespace implementation {

// Methods from IHelloCallback follow.
Return<void> HelloCallback::onNotify(const HalEvent& event) {
    // TODO implement
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//IHelloCallback* HIDL_FETCH_IHelloCallback(const char* /* name */) {
//    return new HelloCallback();
//}

}  // namespace implementation
}  // namespace V1_0
}  // namespace hello
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor
