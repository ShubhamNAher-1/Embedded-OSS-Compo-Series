# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(GStreamerExample)

set(CMAKE_CXX_STANDARD 11)

# Find the GStreamer package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GST REQUIRED gstreamer-1.0)

# Include directories
include_directories(${GST_INCLUDE_DIRS})

# Define the executable and link GStreamer libraries
add_executable(GStreamerExample main.cpp)
target_link_libraries(GStreamerExample ${GST_LIBRARIES})
