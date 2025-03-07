
project "Genesis.Core"
    location "%{wks.location}/Genesis"
    kind "StaticLib"

    files {
        "%{prj.location}/src/GenesisCore/**.h",
        "%{prj.location}/src/GenesisCore/**.c",
        "%{prj.location}/src/GenesisCore/**.hpp",
        "%{prj.location}/src/GenesisCore/**.cpp"
    }

    includedirs {
        includeDirs["Genesis"],
    }
