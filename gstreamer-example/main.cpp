/*
    Author - ShubhamNAher
    C++ code initializes GStreamer, creates a simple pipeline to play a video file, and runs it.
    Date:14-Nov-2024
*/
#include <gst/gst.h>
#include <iostream>

int main(int argc, char *argv[]) {
    gst_init(&argc, &argv);

    // Check if a file path was provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path-to-video-file>" << std::endl;
        return -1;
    }

    // Create the GStreamer playbin pipeline
    GstElement *pipeline = gst_element_factory_make("playbin", "player");
    if (!pipeline) {
        std::cerr << "Failed to create playbin pipeline!" << std::endl;
        return -1;
    }

    // Set the URI for the file to play
    std::string uri = "file://";
    uri += argv[1];
    g_object_set(pipeline, "uri", uri.c_str(), NULL);

    // Start playing
    GstStateChangeReturn ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        std::cerr << "Failed to start playback!" << std::endl;
        gst_object_unref(pipeline);
        return -1;
    }

    // Create a GStreamer bus to listen for messages
    GstBus *bus = gst_element_get_bus(pipeline);
    bool terminate = false;

    while (!terminate) {
        GstMessage *msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                                     GstMessageType(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

        // Handle different message types
        if (msg) {
            switch (GST_MESSAGE_TYPE(msg)) {
                case GST_MESSAGE_ERROR: {
                    GError *err;
                    gchar *debug_info;
                    gst_message_parse_error(msg, &err, &debug_info);
                    std::cerr << "Error received from element " << GST_OBJECT_NAME(msg->src) << ": " << err->message
                              << std::endl;
                    std::cerr << "Debugging information: " << (debug_info ? debug_info : "none") << std::endl;
                    g_clear_error(&err);
                    g_free(debug_info);
                    terminate = true;
                    break;
                }
                case GST_MESSAGE_EOS:
                    std::cout << "End-Of-Stream reached." << std::endl;
                    terminate = true;
                    break;
                default:
                    // Unhandled messages
                    break;
            }
            gst_message_unref(msg);
        }
    }

    // Free resources
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    std::cout << "Playback finished." << std::endl;
    return 0;
}
