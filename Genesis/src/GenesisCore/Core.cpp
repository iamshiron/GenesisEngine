#include "GenesisCore/Core.h"
#include "GenesisCore/Platform.h"
#include <iostream>

namespace ge {
    void Log(const std::string& message) {
        std::cout << "[Core] " << message << std::endl;
    }

    void LogPlatformInfo() {
        Log("=== Genesis Engine Platform Info ===");
        Log(std::string("Platform: ") + GetPlatformName());
        Log(std::string("Configuration: ") + GetConfigName());
        Log(std::string("Debug Build: ") + (IsDebugBuild() ? "Yes" : "No"));
        Log(std::string("Release Build: ") + (IsReleaseBuild() ? "Yes" : "No"));
        Log(std::string("Dist Build: ") + (IsDistBuild() ? "Yes" : "No"));
        Log("====================================");
    }
}
