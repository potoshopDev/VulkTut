module;

export module HelloTriangleApp;
import std;

namespace prvt
{
    void init_vulkan();
    void main_loop();
    void cleanup_vulkan();

    class iHelloTriangleApp
    {
    public:
        iHelloTriangleApp() = default;
        virtual void run() = 0;
        virtual ~iHelloTriangleApp() {}
    };

    class HelloTriangleApp final : public iHelloTriangleApp
    {
    public:
        HelloTriangleApp() { init_vulkan(); }
        virtual void run() override { main_loop(); }
        virtual ~HelloTriangleApp() { cleanup_vulkan(); }
    };
}

export namespace vta
{
    using ref_app = std::unique_ptr<prvt::iHelloTriangleApp>;
    ref_app make_hello_app()
    {
        return std::make_unique<prvt::HelloTriangleApp>();
    }
}