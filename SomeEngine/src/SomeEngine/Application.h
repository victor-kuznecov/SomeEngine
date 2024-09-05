#pragma once
#include "Core.h"

namespace SomeEngine {
	
	class SE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}


