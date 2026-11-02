# Shared compiler settings. Link `project::options` into every target so the
# whole project is built with the same language level and warnings.
add_library(project_options INTERFACE)
add_library(project::options ALIAS project_options)

target_compile_features(project_options INTERFACE cxx_std_20)

option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(ENABLE_SANITIZERS "Build with AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

if(ENABLE_SANITIZERS AND NOT MSVC)
    target_compile_options(project_options INTERFACE
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
    )
    target_link_options(project_options INTERFACE
        -fsanitize=address,undefined
    )
endif()

if(MSVC)
    target_compile_options(project_options INTERFACE /W4 /permissive-)

    if(WARNINGS_AS_ERRORS)
        target_compile_options(project_options INTERFACE /WX)
    endif()
else()
    target_compile_options(project_options INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wcast-align
        -Wunused
    )

    if(WARNINGS_AS_ERRORS)
        target_compile_options(project_options INTERFACE -Werror)
    endif()
endif()
