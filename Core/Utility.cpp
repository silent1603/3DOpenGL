#include "Utility.h"

namespace Core
{
    const char*  Utility::getPlatformName() {
    return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
    }
}