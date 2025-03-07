
project "Runtime.Client"
    location "%{wks.location}/Runtime"
    kind "ConsoleApp"

    files {
        "%{prj.location}/src/RuntimeClient/**.h",
        "%{prj.location}/src/RuntimeClient/**.c",
        "%{prj.location}/src/RuntimeClient/**.hpp",
        "%{prj.location}/src/RuntimeClient/**.cpp"
    }

    includedirs {
        includeDirs["Runtime"],
        includeDirs["Genesis"],
        includeDirs["spdlog"],
        includeDirs["fmt"],
        includeDirs["glfw"],
    }

    links {
        "Runtime.Core",
        "Genesis.Core",
        "Genesis.Server",
        "Genesis.Client",
        "Dependencies.spdlog",
        "Dependencies.fmt",
        "Dependencies.glfw",
    }
