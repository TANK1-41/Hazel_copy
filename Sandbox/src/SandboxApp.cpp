#include <Hazel.h>

class ExampleLayer : public Hazel::Layer {
public:
    ExampleLayer()
        : Layer("Example")
    {}


    void OnUpdate() override
    {
        //HZ_INFO("ExampleLayer::Update");
        if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
        {
            HZ_INFO("Tab key is pressed");
        }
    }

    void OnEvent(Hazel::Event &event) override
    {
        if (event.GetEventType() == Hazel::EventType::KeyPressed)
        {
            Hazel::KeyPressedEvent &e = (Hazel::KeyPressedEvent &) event;
            HZ_TRACE("{0}", (char) e.GetKeyCode());
        }
    }
};


class Sandbox : public Hazel::Application {
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Hazel::ImGuiLayer());
    }


    ~Sandbox()
    {
    }
};

Hazel::Application *Hazel::CreateApplication()
{
    //by creating a derived class of application we can create a new application
    return new Sandbox();
}
