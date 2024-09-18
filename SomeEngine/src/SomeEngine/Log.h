#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace SomeEngine {
	
	class SE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define SE_CORE_TRACE(...)    ::SomeEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)     ::SomeEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)     ::SomeEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...)    ::SomeEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_CRITICAL(...) ::SomeEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SE_TRACE(...)         ::SomeEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)          ::SomeEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...)          ::SomeEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_ERROR(...)         ::SomeEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_CRITICAL(...)      ::SomeEngine::Log::GetClientLogger()->critical(__VA_ARGS__)