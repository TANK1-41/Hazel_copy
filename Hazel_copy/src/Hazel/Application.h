#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Window.h"
namespace Hazel
{

    class HAZEL_API Application {
    public:
        Application();
        ~Application();

        void Run();
        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_running = true;

        LayerStack m_LayerStack;
    };

    //TO be defined by client
    Application *CreateApplication();

}// namespace Hazel
