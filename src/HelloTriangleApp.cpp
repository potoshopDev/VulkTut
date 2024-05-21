module;

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

module HelloTriangleApp;
import std;
import init_window;
import struct_generate;

namespace prvt
{
    vta::vk_objects init_vulkan()
    {
        std::println("HelloTriangleApp: Initializing....");

        const vta::struct_generate sgenerator{};
        return sgenerator.get_vk_object();
    }

    void main_loop()
    {
        std::println("HelloTriangleApp: \"Main Loop\" starting");

        const auto windows_fabric{vta::make_glfw_window_fabric()};
        const auto window{windows_fabric->create_new_window()};

        const vta::struct_generate sgenerator{};
        const auto app_info{sgenerator.get_VkApplicationInfo()};
        const auto inst{sgenerator.get_VkInstanceCreateInfo()};

        while (!glfwWindowShouldClose(window.get()))
        {
            glfwPollEvents();
        }
    }

    void cleanup_vulkan()
    {
        std::println("HelloTriangleApp: cleanup...");
        glfwTerminate();
    }
}