#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
import <glm/vec4.hpp>;
import <glm/mat4x4.hpp>;

import std;
import HelloTriangleApp;


int main() {

    auto app {vta::make_hello_app()};

    try
    {
        app->run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
}