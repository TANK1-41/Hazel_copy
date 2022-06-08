#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool running = false;
	};

	//TO be defined by client
	Application* CreateApplication();

}

