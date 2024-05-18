module;

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

module HelloTriangleApp;
import std;
import init_window;

namespace prvt
{
    void init_vulkan()
    {
        std::println("HelloTriangleApp: Initializing....");
    }

    void main_loop()
    {
        std::println("HelloTriangleApp: \"Main Loop\" starting");

        const auto windows_fabric{vta::make_glfw_window_fabric()};
        const auto window{windows_fabric->create_new_window()};

        while (!glfwWindowShouldClose(window.get()))
        {
            glfwPollEvents();
        }
    }

    void cleanup_vulkan()
    {
        std::println("HelloTriangleApp: cleanup...");
    }
}