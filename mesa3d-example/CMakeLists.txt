# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Mesa3DTriangleExample)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenGL and GLUT libraries
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Define executable and link libraries
add_executable(Mesa3DTriangle main.cpp)
target_link_libraries(Mesa3DTriangle ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
