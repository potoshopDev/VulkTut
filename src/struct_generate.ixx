module;

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

export module struct_generate;
import std;

export namespace vta
{

    struct vk_objects
    {
        VkInstance instance{};


            ~vk_objects()
        {
            vkDestroyInstance(instance, nullptr);
        }
    };

    class struct_generate final
    {
        struct isg_VkApplicationInfo
        {
            virtual ~isg_VkApplicationInfo()
            {
            }
            virtual VkApplicationInfo get_VkApplicationInfo(const char *) const noexcept = 0;
        };

        struct isg_VkInstanceCreateInfo
        {
            virtual ~isg_VkInstanceCreateInfo() {}
            virtual VkInstanceCreateInfo get_VkInstanceCreateInfo(const VkApplicationInfo *) const noexcept = 0;
        };

        struct isg_vk_object
        {
            virtual ~isg_vk_object() {}
            virtual vk_objects get_vk_object(const VkInstanceCreateInfo *create_info) const = 0;
        };

        struct istruct_generate : public isg_VkApplicationInfo,
                                  public isg_VkInstanceCreateInfo,
                                  public isg_vk_object
        {
        };

        struct ostruct_generate final : public istruct_generate
        {
            virtual VkApplicationInfo get_VkApplicationInfo(const char *app_name = "Hello Triangle") const noexcept override;
            virtual VkInstanceCreateInfo get_VkInstanceCreateInfo(const VkApplicationInfo *app_info = nullptr) const noexcept override;
            virtual vk_objects get_vk_object(const VkInstanceCreateInfo *create_info = nullptr) const override;
        };

    private:
        using str_gnr = std::unique_ptr<istruct_generate>;
        str_gnr generator{std::make_unique<ostruct_generate>()};

    public:
        VkApplicationInfo get_VkApplicationInfo(const char *app_name = "Hello Triangle") const noexcept { return generator->get_VkApplicationInfo(app_name); }
        VkInstanceCreateInfo get_VkInstanceCreateInfo(const VkApplicationInfo *app_info = nullptr) const noexcept { return generator->get_VkInstanceCreateInfo(app_info); }
        vk_objects get_vk_object(const VkInstanceCreateInfo *create_info = nullptr) const { return generator->get_vk_object(create_info); }
    };
} // namespace prvt
