set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(bruhEngine)

file(GLOB_RECURSE src_files CONFIGURE_DEPENDS "src/*.cpp" "src/*.hpp" "src/*.c")

add_executable(bruhEngine ${src_files})

target_link_libraries(bruhEngine glfw GL X11 pthread Xrandr Xi dl)
target_include_directories(bruhEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
