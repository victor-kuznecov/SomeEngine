#include <SomeEngine.h>

class Sandbox : public SomeEngine::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

SomeEngine::Application* SomeEngine::CreateApplication()
{
	return new Sandbox();
}