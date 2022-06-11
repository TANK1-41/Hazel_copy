#pragma once


#ifdef HZ_PLATFORM_WINDOWS

//user defines application
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	Hazel::Log::Init();
	HZ_CORE_WARN("init core logger");
	HZ_CRITICAL("init client logger");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // HZ_PLATFORM_WINDOWS
