#include <vendor/mediatek/hardware/hello/1.0/IHello.h>
#include <hidl/LegacySupport.h>

using vendor::mediatek::hardware::hello::V1_0::IHello;
using android::hardware::defaultPassthroughServiceImplementation;

int main()
{
    return defaultPassthroughServiceImplementation<IHello>();
}

