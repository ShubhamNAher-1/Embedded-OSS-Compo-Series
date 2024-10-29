# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(WaylandClientExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Wayland package
find_package(PkgConfig REQUIRED)
pkg_check_modules(WAYLAND_CLIENT REQUIRED wayland-client)

# Include directories
include_directories(${WAYLAND_CLIENT_INCLUDE_DIRS})

# Define executable and link Wayland libraries
add_executable(WaylandClientExample main.cpp)
target_link_libraries(WaylandClientExample ${WAYLAND_CLIENT_LIBRARIES})
