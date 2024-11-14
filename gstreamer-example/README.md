This example code initializes GStreamer, creates a simple pipeline to play a video file, and runs it. 
We’ll use playbin, a convenient GStreamer element that automatically handles playback for most audio/video formats.

Prerequisites:
    sudo apt update
    sudo apt install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev

gstreamer-example/
├── CMakeLists.txt
└── main.cpp

Building and Running the Example
    cd gstreamer-example
    mkdir build && cd build
    cmake ..
    make
    ./GStreamerExample /path/to/your/video/file.mp4

Explanation:
1. GStreamer Initialization: gst_init initializes the GStreamer library.
2. Creating the Playbin: We use the playbin element, which is a high-level element that automatically handles many of the lower-level GStreamer details for playing media files.
3. Setting the URI: We specify the video file path as a URI. GStreamer uses the file:// URI prefix to identify local files.
4. Event Loop and Message Handling: We use a GstBus to listen for error or end-of-stream (EOS) messages, allowing the program to handle these events appropriately.
5. Cleanup: After playback is complete, we reset the pipeline state and release resources.
This example should play your video using GStreamer, showing the basic setup and event handling for a media playback application.
