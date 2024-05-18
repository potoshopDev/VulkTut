module;

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

module init_window;
import std;

namespace prvt
{
    void settings_window()
    {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }

    uglfw_window create_uglfw_window(const uint32_t width, const uint32_t height)
    {
        return uglfw_window(glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr), &prvt::destroy_window);
    }

    void destroy_window(GLFWwindow *win)
    {
        glfwDestroyWindow(win);
    }
}