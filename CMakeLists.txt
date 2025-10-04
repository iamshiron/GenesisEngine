# --- Root CMakeLists.txt ---
cmake_minimum_required(VERSION 3.15)
project(GenesisEngine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ====================================================================================
# Platform Detection
# ====================================================================================
if(WIN32)
    set(PLATFORM "Windows")
    add_compile_definitions(GE_WINDOWS)
elseif(UNIX AND NOT APPLE)
    set(PLATFORM "Linux")
    add_compile_definitions(GE_LINUX GE_UNIX)
elseif(APPLE)
    set(PLATFORM "macOS")
    add_compile_definitions(GE_MAC GE_UNIX)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCHITECTURE "x64")
else()
    set(ARCHITECTURE "x86")
endif()

# ====================================================================================
# Build Configurations
# ====================================================================================
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)

add_compile_definitions(
    $<$<CONFIG:Debug>:GE_DEBUG>
    $<$<CONFIG:Release>:GE_RELEASE>
    $<$<CONFIG:Dist>:GE_DIST>
    $<$<NOT:$<CONFIG:Debug>>:GE_NDEBUG>
)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD /O2 /Ob2 /Zi /DNDEBUG")
    set(CMAKE_CXX_FLAGS_DIST "/MD /O2 /Ob2 /GL /DNDEBUG")
    set(CMAKE_EXE_LINKER_FLAGS_DIST "/LTCG /INCREMENTAL:NO /OPT:REF /OPT:ICF")
    set(CMAKE_SHARED_LINKER_FLAGS_DIST "/LTCG /INCREMENTAL:NO /OPT:REF /OPT:ICF")
    set(CMAKE_STATIC_LINKER_FLAGS_DIST "/LTCG")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-g -O2 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DIST "-O3 -DNDEBUG -ffunction-sections -fdata-sections")
    set(CMAKE_EXE_LINKER_FLAGS_DIST "-Wl,--gc-sections -s")
    set(CMAKE_SHARED_LINKER_FLAGS_DIST "-Wl,--gc-sections -s")
endif()

# ====================================================================================
# Output Directories
# ====================================================================================
foreach(CONFIG_TYPE ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${CONFIG_TYPE} CONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${CMAKE_SOURCE_DIR}/bin/${PLATFORM}/${CONFIG_TYPE}-${ARCHITECTURE}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${CMAKE_SOURCE_DIR}/bin/${PLATFORM}/${CONFIG_TYPE}-${ARCHITECTURE}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${CMAKE_SOURCE_DIR}/bin/${PLATFORM}/${CONFIG_TYPE}-${ARCHITECTURE}")
endforeach()

# ====================================================================================
# Helper Functions
# ====================================================================================

# Add a Genesis library with automatic configuration
function(ge_add_library TARGET_NAME)
    set(options "")
    set(oneValueArgs "")
    set(multiValueArgs SOURCES DEPENDENCIES)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Automatically find all .h and .cpp files if no sources specified
    if(NOT ARG_SOURCES)
        file(GLOB ARG_SOURCES "*.h" "*.cpp")
    endif()

    add_library(${TARGET_NAME} STATIC ${ARG_SOURCES})
    target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Genesis/src)

    if(ARG_DEPENDENCIES)
        target_link_libraries(${TARGET_NAME} PUBLIC ${ARG_DEPENDENCIES})
    endif()

    # Set output directories
    foreach(CONFIG_TYPE ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${CONFIG_TYPE} CONFIG_UPPER)
        set_target_properties(${TARGET_NAME} PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${CMAKE_SOURCE_DIR}/bin/${PLATFORM}/${CONFIG_TYPE}-${ARCHITECTURE}/${TARGET_NAME}"
            COMPILE_PDB_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${CMAKE_SOURCE_DIR}/bin-int/${PLATFORM}/${CONFIG_TYPE}-${ARCHITECTURE}/${TARGET_NAME}"
        )
    endforeach()
endfunction()

# Add a Genesis executable with automatic configuration
function(ge_add_executable TARGET_NAME)
    set(options "")
    set(oneValueArgs "")
    set(multiValueArgs SOURCES DEPENDENCIES)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Automatically find all .cpp files if no sources specified
    if(NOT ARG_SOURCES)
        file(GLOB ARG_SOURCES "*.cpp")
    endif()

    add_executable(${TARGET_NAME} ${ARG_SOURCES})
    target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Genesis/src)

    if(ARG_DEPENDENCIES)
        target_link_libraries(${TARGET_NAME} PRIVATE ${ARG_DEPENDENCIES})
    endif()

    # Set output directories
    foreach(CONFIG_TYPE ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${CONFIG_TYPE} CONFIG_UPPER)
        set_target_properties(${TARGET_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${CMAKE_SOURCE_DIR}/bin/${PLATFORM}/${CONFIG_TYPE}-${ARCHITECTURE}/${TARGET_NAME}"
            COMPILE_PDB_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${CMAKE_SOURCE_DIR}/bin-int/${PLATFORM}/${CONFIG_TYPE}-${ARCHITECTURE}/${TARGET_NAME}"
        )
    endforeach()
endfunction()

# ====================================================================================
# Subdirectories
# ====================================================================================
add_subdirectory(Genesis)
add_subdirectory(Runtime)
