
project "Dependencies.fmt"
    location "%{wks.location}/Dependencies/fmt"
    kind "StaticLib"

    files {
        "%{prj.location}/src/format.cc",
        "%{prj.location}/src/os.cc",
    }

    includedirs {
        "%{prj.location}/include",
    }
