cmake_minimum_required(VERSION 3.24)

project(
    WhoAmIFighting
    VERSION 0.1.0
    DESCRIPTION "A 3D turn-based tactical strategy game"
    LANGUAGES C CXX
)

# ---------------------------------------------------------------------------
# Global settings
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json for clangd and other editor tooling.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Keep all executables in <build>/bin so they are easy to find and run.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Default to a debug build for single-config generators.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CompilerOptions)
include(Dependencies)

add_subdirectory(src)

# Expose the compilation database at the project root for editor tooling
# (IntelliSense, clangd, etc.) that looks for it there.
if(CMAKE_EXPORT_COMPILE_COMMANDS AND UNIX)
    file(CREATE_LINK
        "${CMAKE_BINARY_DIR}/compile_commands.json"
        "${CMAKE_SOURCE_DIR}/compile_commands.json"
        SYMBOLIC
    )
endif()
