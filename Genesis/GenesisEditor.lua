
project "Genesis.Editor"
    location "%{wks.location}/Genesis"
    kind "ConsoleApp"

    files {
        "%{prj.location}/src/GenesisEditor/**.h",
        "%{prj.location}/src/GenesisEditor/**.c",
        "%{prj.location}/src/GenesisEditor/**.hpp",
        "%{prj.location}/src/GenesisEditor/**.cpp"
    }

    includedirs {
        includeDirs["Genesis"],
        includeDirs["Runtime"],
    }

    links {
        "Runtime.Core",
        "Genesis.Core",
        "Genesis.Server",
        "Genesis.Client"
    }
