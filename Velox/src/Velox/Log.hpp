#pragma once

#include <memory>

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Velox {

	class VELOX_API Log
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

#define VX_CORE_FATAL(...) ::Velox::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define VX_CORE_ERROR(...) ::Velox::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VX_CORE_WARN(...) ::Velox::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VX_CORE_INFO(...) ::Velox::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VX_CORE_TRACE(...) ::Velox::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define VX_FATAL(...) ::Velox::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define VX_ERROR(...) ::Velox::Log::GetClientLogger()->error(__VA_ARGS__)
#define VX_WARN(...) ::Velox::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VX_INFO(...) ::Velox::Log::GetClientLogger()->info(__VA_ARGS__)
#define VX_TRACE(...) ::Velox::Log::GetClientLogger()->trace(__VA_ARGS__)
