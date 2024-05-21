module;

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

module struct_generate;
import std;
import <cstdint>;

namespace prvt
{
    using extension = std::pair<uint32_t, const char **>;
    extension get_vul_extension()
    {
        uint32_t glfwExtensionCount = 0;
        const char **glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        return {glfwExtensionCount, glfwExtensions};
    }

    VkInstance create_instance(const VkInstanceCreateInfo *create_info)
    {
        VkInstance instance{};

        if (vkCreateInstance(create_info, nullptr, &instance) != VK_SUCCESS)
            throw std::runtime_error("failed to create instance!");

        return instance;
    }
}

namespace vta
{

    VkApplicationInfo struct_generate::ostruct_generate::get_VkApplicationInfo(const char *app_name) const noexcept
    {
        return VkApplicationInfo{
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pApplicationName = app_name,
            .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
            .pEngineName = "No Engine",
            .engineVersion = VK_MAKE_VERSION(1, 0, 0),
            .apiVersion = VK_API_VERSION_1_0,
        };
    }

    VkInstanceCreateInfo struct_generate::ostruct_generate::get_VkInstanceCreateInfo(const VkApplicationInfo *app_info) const noexcept
    {
        const auto _app_info{app_info ? *app_info : get_VkApplicationInfo()};
        const auto [extensions_count, extensions] = prvt::get_vul_extension();

        return VkInstanceCreateInfo{
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pApplicationInfo = &_app_info,
            .enabledLayerCount = 0,
            .enabledExtensionCount = extensions_count,
            .ppEnabledExtensionNames = extensions,
        };
    }
    vk_objects struct_generate::ostruct_generate::get_vk_object(const VkInstanceCreateInfo *create_info) const
    {
        const auto _create_info{create_info ? *create_info : get_VkInstanceCreateInfo()};

        return vk_objects{.instance = prvt::create_instance(&_create_info)};
    }
}