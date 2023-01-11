#pragma once
#include "spdlog/spdlog.h"
namespace Core
{
    class CORE_API Log{
        public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
        private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
   
} // namespace Core


#define CORE_TRACE(...) ::Core::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...) ::Core::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...) ::Core::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) ::Core::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) ::Core::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define TRACE(...) ::Core::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define INFO(...) ::Core::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WARN(...) ::Core::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ERROR(...) ::Core::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FATAL(...) ::Core::Log::GetCoreLogger()->critical(__VA_ARGS__)
