
project "Dependencies.spdlog"
    location "%{wks.location}/Dependencies/spdlog"
    kind "StaticLib"

    files {
        "%{prj.location}/src/async.cpp",
        "%{prj.location}/src/cfg.cpp",
        "%{prj.location}/src/color_sinks.cpp",
        "%{prj.location}/src/file_sinks.cpp",
        "%{prj.location}/src/spdlog.cpp",
        "%{prj.location}/src/stdout_sinks.cpp",
    }

    defines {
        "SPDLOG_COMPILED_LIB"
    }

    includedirs {
        "%{prj.location}/include"
    }
