# Third-party dependencies.
#
# GLFW and GLM are used from the system when available and fetched/built from
# source otherwise. glad is vendored in third_party/glad and needs no system
# OpenGL loader package.
include(FetchContent)

find_package(Threads REQUIRED)

# --- glad (vendored OpenGL loader) ------------------------------------------
add_subdirectory(
    "${PROJECT_SOURCE_DIR}/third_party/glad"
    "${CMAKE_BINARY_DIR}/_deps/glad"
)

# --- GLFW -------------------------------------------------------------------
find_package(glfw3 3.3 QUIET)

if(NOT glfw3_FOUND)
    message(STATUS "glfw3 not found - fetching GLFW 3.4 from source")

    # GLFW 3.4 declares a CMake minimum older than CMake 4 accepts. This keeps
    # the dependency build working on newer CMake releases.
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 4.0 AND NOT DEFINED CMAKE_POLICY_VERSION_MINIMUM)
        set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
    endif()

    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(glfw)
endif()

# --- GLM --------------------------------------------------------------------
find_package(glm QUIET)

if(NOT glm_FOUND)
    message(STATUS "glm not found - fetching GLM 1.0.1 from source")

    FetchContent_Declare(glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(glm)
endif()

# Bundle the dependency link requirements into one target.
add_library(third_party INTERFACE)
add_library(project::third_party ALIAS third_party)

target_link_libraries(third_party INTERFACE
    glfw
    glm::glm
    glad::glad
    Threads::Threads
)
