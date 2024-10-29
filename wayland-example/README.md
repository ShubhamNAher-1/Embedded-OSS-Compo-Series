This C++ code creates a basic Wayland client window.

Prerequisites:
    sudo apt update
    sudo apt install libwayland-dev

Project Structure:
    wayland-example/
    ├── CMakeLists.txt
    └── main.cpp

Building and Running the Example:
    cd wayland-example
    mkdir build && cd build
    cmake ..
    make
    ./WaylandClientExample

Explanation of the Code :
    Wayland Connection: We connect to the Wayland display using wl_display_connect, which initializes the Wayland connection.
    Registry and Compositor: We use the Wayland registry to retrieve global objects, like the wl_compositor, which we need to create surfaces.
    Surface Creation: We create a simple Wayland surface using wl_compositor_create_surface. A surface is essentially a window that can be displayed by the Wayland compositor.
    Event Loop: The wl_display_dispatch function is used to process Wayland events, which keeps the window open.
    This example sets up a minimal Wayland client window.

Creating a basic Wayland client example in C++ is a bit more involved, as Wayland doesn’t provide a full rendering library like OpenGL does. Instead, Wayland provides the protocol for compositing surfaces but relies on external libraries to render graphics.

