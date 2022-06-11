#include <Hazel.h>

class ExampleLayer : public Hazel::Layer {
public:
    ExampleLayer()
        : Layer("Example")
    {}


    void OnUpdate() override
    {
        HZ_INFO("ExampleLayer::Update");
    }

    void OnEvent(Hazel::Event &event) override
    {
        HZ_TRACE("{0}", event);
    }
};


class Sandbox : public Hazel::Application {
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }


    ~Sandbox()
    {
    }
};

Hazel::Application *Hazel::CreateApplication()
{
    //by creating a divrived class of application we can create a new application
    return new Sandbox();
}
