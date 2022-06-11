#include <Hazel.h>

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{

	}


	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	//by creating a divrived class of application we can create a new application
	return new Sandbox();
}