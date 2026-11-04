# Every .cpp under src/ is picked up automatically. CONFIGURE_DEPENDS makes
# CMake re-scan the tree when files are added or removed, so new source files
# work without editing this file.
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

if(NOT GAME_SOURCES)
    message(FATAL_ERROR "No .cpp files found under ${CMAKE_CURRENT_SOURCE_DIR}")
endif()

add_executable(who_am_i_fighting ${GAME_SOURCES})
set_target_properties(who_am_i_fighting PROPERTIES
    OUTPUT_NAME "who-am-i-fighting"
)

# Headers next to the sources can be included as "render/foo.hpp", etc.
target_include_directories(who_am_i_fighting PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(who_am_i_fighting PRIVATE
    project::options
    project::third_party
)
