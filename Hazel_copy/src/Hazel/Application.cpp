#include "hzpch.h"

#include "Application.h"
#include "Hazel/Log.h"

#include "glad/glad.h"
namespace Hazel
{

#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }
    Application::~Application()
    {
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        HZ_CORE_TRACE("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.pushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_LayerStack.pushOverlay(overlay);
        overlay->OnAttach();
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_running = false;
        return true;
    }

    void Application::Run()
    {
        /*WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			HZ_WARN(e);
		}
		HZ_TRACE(e);*/

        while (m_running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer *layer: m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }


}// namespace Hazel
