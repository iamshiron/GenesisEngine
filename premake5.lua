include "dependencies.lua"

workspace "GenesisEngine"
    language "C++"
    cppdialect "C++20"
    systemversion "latest"
    characterset "Unicode"

    targetdir "%{wks.location}/bin/%{cfg.system}/%{cfg.longname}/%{prj.name}"
    objdir "%{wks.location}/bin-int/%{cfg.system}/%{cfg.longname}/%{prj.name}"
    debugdir "%{wks.location}/bin/%{cfg.system}/%{cfg.longname}/%{prj.name}"

    configurations { "Debug-x64", "Release-x64", "Dist-x64", "Debug-x86", "Release-x86", "Dist-x86" }

    defines {
        "FMT_MODULE_EXPORT="
    }

    filter "configurations:*-x64"
        architecture "x86_64"
    filter "configurations:*-x86"
        architecture "x86"
    filter ""

    filter "configurations:Debug-*"
        defines { "GE_DEBUG" }
        symbols "On"
    filter "configurations:Release-*"
        defines { "GE_RELEASE" }
        optimize "On"
    filter "configurations:Dist-*"
        defines { "GE_DIST" }
        optimize "Speed"
    filter ""

    filter "action:vs*"
        buildoptions { "/utf-8", "/Zc:__cplusplus" }
    filter ""

    -- GeneissEngine
    group "GenesisEngine"
        include "Genesis/GenesisClient.lua"
        include "Genesis/GenesisCore.lua"
        include "Genesis/GenesisServer.lua"
        include "Genesis/GenesisEditor.lua"
    group ""

    -- Runtime
    group "Runtime"
        include "Runtime/RuntimeCore.lua"
        include "Runtime/RuntimeClient.lua"
        include "Runtime/RuntimeServer.lua"
    group ""

    -- Dependencies
    group "Dependencies"
        include "Dependencies/fmt.lua"
        include "Dependencies/spdlog.lua"
    group ""
