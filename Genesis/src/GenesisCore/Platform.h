#pragma once

// Platform Detection
#if defined(GE_WINDOWS)
    #define GE_PLATFORM_NAME "Windows"
#elif defined(GE_LINUX)
    #define GE_PLATFORM_NAME "Linux"
#elif defined(GE_MAC)
    #define GE_PLATFORM_NAME "macOS"
#else
    #define GE_PLATFORM_NAME "Unknown"
#endif

// Configuration Detection
#if defined(GE_DEBUG)
    #define GE_CONFIG_NAME "Debug"
#elif defined(GE_RELEASE)
    #define GE_CONFIG_NAME "Release"
#elif defined(GE_DIST)
    #define GE_CONFIG_NAME "Dist"
#else
    #define GE_CONFIG_NAME "Unknown"
#endif

// GE_NDEBUG is defined for Release and Dist builds (non-debug builds)
#ifdef GE_NDEBUG
    // This is a non-debug build (Release or Dist)
#endif

// Platform-specific helpers
#ifdef GE_WINDOWS
    #define GE_DEBUGBREAK() __debugbreak()
#elif defined(GE_UNIX)
    #include <signal.h>
    #define GE_DEBUGBREAK() raise(SIGTRAP)
#else
    #define GE_DEBUGBREAK()
#endif

// Enable assertions only in Debug and Release builds
#if defined(GE_DEBUG) || defined(GE_RELEASE)
    #define GE_ENABLE_ASSERTS
#endif

#ifdef GE_ENABLE_ASSERTS
    #include <iostream>
    #define GE_ASSERT(x, msg) \
        if (!(x)) { \
            std::cerr << "Assertion Failed: " << msg << "\n"; \
            std::cerr << "  File: " << __FILE__ << "\n"; \
            std::cerr << "  Line: " << __LINE__ << "\n"; \
            GE_DEBUGBREAK(); \
        }
#else
    #define GE_ASSERT(x, msg)
#endif

namespace ge {
    // Get platform name at runtime
    inline const char* GetPlatformName() {
        return GE_PLATFORM_NAME;
    }

    // Get configuration name at runtime
    inline const char* GetConfigName() {
        return GE_CONFIG_NAME;
    }

    // Check if running in debug mode
    inline bool IsDebugBuild() {
        #ifdef GE_DEBUG
            return true;
        #else
            return false;
        #endif
    }

    // Check if running in release mode
    inline bool IsReleaseBuild() {
        #ifdef GE_RELEASE
            return true;
        #else
            return false;
        #endif
    }

    // Check if running in dist mode
    inline bool IsDistBuild() {
        #ifdef GE_DIST
            return true;
        #else
            return false;
        #endif
    }
}
