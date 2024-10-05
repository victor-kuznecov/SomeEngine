#include <SomeEngine.h>

class ExampleLayer : public SomeEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") 
	{
	}

	void OnUpdate() override
	{
		SE_INFO("ExampleLayer::Update");
	}

	void OnEvent(SomeEngine::Event& event) override
	{
		SE_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public SomeEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new SomeEngine::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

SomeEngine::Application* SomeEngine::CreateApplication()
{
	return new Sandbox();
}