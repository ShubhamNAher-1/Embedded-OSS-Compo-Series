This C++ code initializes an OpenGL context and renders a simple triangle on the screen.

Prerequisites:
    sudo apt update
    sudo apt install mesa-common-dev freeglut3-dev

mesa3d-example/
├── CMakeLists.txt
└── main.cpp

Building and Running the Example
    cd mesa3d-example
    mkdir build && cd build
    cmake ..
    make
    ./Mesa3DTriangle

Explanation:
    OpenGL Context: The code sets up an OpenGL context using glutInit and configures a display window.
    Rendering a Triangle: The display function defines a triangle using three vertices, each with a different color, which OpenGL then interpolates across the triangle's surface.
    Main Loop: glutMainLoop enters the main event loop, which keeps the window open and renders the triangle.
    
This simple example should help you get started with Mesa3D and OpenGL on a Linux system using C++ and CMake!
