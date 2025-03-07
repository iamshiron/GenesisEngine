
project "Genesis.Client"
    location "%{wks.location}/Genesis"
    kind "StaticLib"

    files {
        "%{prj.location}/src/GenesisClient/**.h",
        "%{prj.location}/src/GenesisClient/**.c",
        "%{prj.location}/src/GenesisClient/**.hpp",
        "%{prj.location}/src/GenesisClient/**.cpp"
    }

    includedirs {
        includeDirs["Genesis"],
        includeDirs["spdlog"],
        includeDirs["fmt"],
        includeDirs["glfw"],
    }
