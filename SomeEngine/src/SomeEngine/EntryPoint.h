#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SomeEngine::Application* SomeEngine::CreateApplication();

int main(int argc, char** argv)
{
	SomeEngine::Log::Init();
	SE_CORE_WARN("Log has initialised");
	int var = 5;
	SE_INFO("Hello! var = {0}", var);

	auto application = SomeEngine::CreateApplication();
	application->Run();
	delete application;
}
#endif