# define LOG_TAG "android.hardware.naruto@1.0-service"

# include <android/hardware/naruto/1.0/INaruto.h>

# include <hidl/LegacySupport.h>

using android::hardware::naruto::V1_0::INaruto;
using android::hardware::defaultPassthroughServiceImplementation;

int main() {
    return defaultPassthroughServiceImplementation<INaruto>();
}

