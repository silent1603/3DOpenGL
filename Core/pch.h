#pragma once
//Stardard
#include <iostream>
#include <sstream>
#include <fstream>
#include <thread>
#include <memory>

//eastl
#include <eastl/array.h>
#include <eastl/chrono.h>
#include <eastl/vector.h>
#include <eastl/map.h>
#include <eastl/functional.h>
#include <eastl/atomic.h>
#include <eastl/allocator.h>
#include <eastl/algorithm.h>
#include <eastl/allocator_malloc.h>
#include <eastl/numeric.h>
#include <eastl/iterator.h>
#include <eastl/random.h>
#include <eastl/ratio.h>
#include <eastl/list.h>
#include <eastl/safe_ptr.h>
#include <eastl/scoped_ptr.h>
#include <eastl/shared_array.h>
#include <eastl/shared_ptr.h>
#include <eastl/string_view.h>
#include <eastl/string.h>
#include <eastl/sort.h>
#include <eastl/span.h>
#include <eastl/optional.h>
#include <eastl/weak_ptr.h>
#include <eastl/unique_ptr.h>
#include <eastl/utility.h>
#include <eastl/scoped_array.h>
#include <eastl/variant.h>



#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
   
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__ANDROID__)
    #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
    
#else
    #define PLATFORM_NAME NULL
#endif


#if defined(GAME_CORE_WINDOWS) 
    #ifdef GAME_CORE_EXPORTS_DLL
        #define CORE_API __declspec(dllexport)
    #elif GAME_CORE_IMPORTS_DLL
        #define CORE_API __declspec(dllimport)
#endif    
#else
        #define CORE_API 
#endif
