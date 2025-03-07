
project "Genesis.Server"
    location "%{wks.location}/Genesis"
    kind "StaticLib"

    files {
        "%{prj.location}/src/GenesisServer/**.h",
        "%{prj.location}/src/GenesisServer/**.c",
        "%{prj.location}/src/GenesisServer/**.hpp",
        "%{prj.location}/src/GenesisServer/**.cpp"
    }

    includedirs {
        includeDirs["Genesis"],
    }
