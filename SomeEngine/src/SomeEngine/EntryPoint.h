#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SomeEngine::Application* SomeEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto application = SomeEngine::CreateApplication();
	application->Run();
	delete application;
}
#endif