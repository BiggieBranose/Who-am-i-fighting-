# Generated OpenGL loader (glad 2.0.8).
#
# These files are checked in so building the game requires no Python or
# system OpenGL loader package. See README.md in this directory to regenerate.
add_library(glad STATIC src/gl.c)
add_library(glad::glad ALIAS glad)

target_include_directories(glad PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
