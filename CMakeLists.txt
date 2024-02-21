cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(bruhEngine)

file(GLOB_RECURSE src_files CONFIGURE_DEPENDS "src/*.cpp" "src/*.hpp" "src/*.c")

add_executable(bruhEngine ${src_files})

target_include_directories(bruhEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(bruhEngine ${CMAKE_CURRENT_SOURCE_DIR}/lib/libglfw.3.dylib)

find_library(COCOA cocoa)
find_library(IOKIT iokit)
find_library(OPENGL opengl)
target_link_libraries(bruhEngine ${OPENGL} ${COCOA} ${IOKIT})
