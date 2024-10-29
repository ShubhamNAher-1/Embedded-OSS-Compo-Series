/*
    Author - ShubhamNAher
    This C++ code creates a basic Wayland client window.
    Date:29-Oct-2024
*/

#include <wayland-client.h>
#include <iostream>
#include <cstring>

struct WaylandClient {
    wl_display* display;
    wl_compositor* compositor;
    wl_surface* surface;

    WaylandClient() : display(nullptr), compositor(nullptr), surface(nullptr) {}

    bool initialize() {
        // Connect to the Wayland display
        display = wl_display_connect(nullptr);
        if (!display) {
            std::cerr << "Failed to connect to Wayland display." << std::endl;
            return false;
        }

        // Retrieve the Wayland registry
        wl_registry* registry = wl_display_get_registry(display);
        wl_registry_add_listener(registry, &registry_listener, this);

        // Process registry events
        wl_display_roundtrip(display);

        if (!compositor) {
            std::cerr << "Failed to get Wayland compositor." << std::endl;
            return false;
        }

        // Create a Wayland surface
        surface = wl_compositor_create_surface(compositor);
        if (!surface) {
            std::cerr << "Failed to create Wayland surface." << std::endl;
            return false;
        }

        std::cout << "Wayland client initialized successfully!" << std::endl;
        return true;
    }

    void run() {
        // Simple event loop to keep the window open
        while (wl_display_dispatch(display) != -1) {
            // Waiting for events...
        }
    }

    void cleanup() {
        if (surface) wl_surface_destroy(surface);
        if (compositor) wl_compositor_destroy(compositor);
        if (display) wl_display_disconnect(display);
    }

    ~WaylandClient() {
        cleanup();
    }

private:
    // Registry listener to retrieve global objects like the compositor
    static void registryHandler(void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version) {
        WaylandClient* client = static_cast<WaylandClient*>(data);
        if (strcmp(interface, "wl_compositor") == 0) {
            client->compositor = static_cast<wl_compositor*>(
                wl_registry_bind(registry, id, &wl_compositor_interface, 1));
        }
    }

    static void registryRemover(void* data, wl_registry* registry, uint32_t id) {
        // No cleanup needed in this example
    }

    // Listener struct for registry events
    static inline const wl_registry_listener registry_listener = {
        registryHandler,
        registryRemover
    };
};

int main() {
    WaylandClient client;
    if (!client.initialize()) {
        return -1;
    }

    client.run();

    return 0;
}
