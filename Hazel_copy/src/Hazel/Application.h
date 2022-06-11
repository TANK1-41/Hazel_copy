#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"

#include "Window.h"
namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_running = true;
	};

	//TO be defined by client
	Application* CreateApplication();

}

