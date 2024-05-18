module;

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

export module init_window;
import std;
import <cstdint>;

namespace prvt
{

    void settings_window();

    void destroy_window(GLFWwindow *win);
    using uglfw_window = std::unique_ptr<GLFWwindow, decltype(&destroy_window)>;

    uglfw_window create_uglfw_window(const uint32_t width, const uint32_t height);

    class iglfw_window
    {
    public:
        virtual uglfw_window create_new_window(const uint32_t width = 800, const uint32_t height = 600) noexcept = 0;
        virtual ~iglfw_window() { glfwTerminate(); }
    };

    class glfw_window final : public iglfw_window
    {
    public:
        glfw_window()
        {
            settings_window();
        }

        virtual uglfw_window create_new_window(const uint32_t width = 800, const uint32_t height = 600) noexcept
        {
            return create_uglfw_window(width, height);
        }
    };
}

export namespace vta
{
    using new_glfw_window = std::unique_ptr<prvt::iglfw_window>;
    new_glfw_window make_glfw_window_fabric()
    {
        return std::make_unique<prvt::glfw_window>();
    }
}