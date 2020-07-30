#include "Naruto.h"

namespace android {
namespace hardware {
namespace naruto {
namespace V1_0 {
namespace implementation {

// Methods from INaruto follow.
Return<void> Naruto::helloWorld(const hidl_string& name, helloWorld_cb _hidl_cb) {
    // TODO implement
    char buf[100];

    memset(buf, 0, 100);
    snprintf(buf, 100, "HelloWorld, %s", name.c_str());
    hidl_string result(buf);

    _hidl_cb(result);

    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

INaruto* HIDL_FETCH_INaruto(const char* /* name */) {
    return new Naruto();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace naruto
}  // namespace hardware
}  // namespace android
