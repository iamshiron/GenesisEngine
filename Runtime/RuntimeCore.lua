
project "Runtime.Core"
    location "%{wks.location}/Runtime"
    kind "StaticLib"

    files {
        "%{prj.location}/src/RuntimeCore/**.h",
        "%{prj.location}/src/RuntimeCore/**.c",
        "%{prj.location}/src/RuntimeCore/**.hpp",
        "%{prj.location}/src/RuntimeCore/**.cpp"
    }

    includedirs {
        includeDirs["Genesis"],
    }

    links {
        "Genesis.Core",
        "Genesis.Server",
        "Genesis.Client"
    }
