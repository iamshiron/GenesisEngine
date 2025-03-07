
project "Runtime.Server"
    location "%{wks.location}/Runtime"
    kind "ConsoleApp"

    files {
        "%{prj.location}/src/RuntimeServer/**.h",
        "%{prj.location}/src/RuntimeServer/**.c",
        "%{prj.location}/src/RuntimeServer/**.hpp",
        "%{prj.location}/src/RuntimeServer/**.cpp"
    }

    includedirs {
        includeDirs["Runtime"],
        includeDirs["Genesis"],
    }

    links {
        "Runtime.Core",
        "Genesis.Core",
        "Genesis.Server",
    }
