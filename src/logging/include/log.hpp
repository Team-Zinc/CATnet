#ifndef LOG_HPP
#define LOG_HPP

#include <memory>

// This ignores all warnings raised inside External headers
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace CatnetUtils {
	class Log {
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetHeadLogger() { return s_HeadLogger; }
		static std::shared_ptr<spdlog::logger>& GetWhiskerLogger() { return s_WhiskerLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_HeadLogger;
		static std::shared_ptr<spdlog::logger> s_WhiskerLogger;
	};

}

// Head log macros
#define HD_TRACE(...)    ::CatnetUtils::Log::GetHeadLogger()->trace(__VA_ARGS__)
#define HD_WARN(...)     ::CatnetUtils::Log::GetHeadLogger()->warn(__VA_ARGS__)
#define HD_INFO(...)     ::CatnetUtils::Log::GetHeadLogger()->info(__VA_ARGS__)
#define HD_ERROR(...)    ::CatnetUtils::Log::GetHeadLogger()->error(__VA_ARGS__)
#define HD_CRITICAL(...) ::CatnetUtils::Log::GetHeadLogger()->critical(__VA_ARGS__)

// Whisker log macros
#define WK_TRACE(...)    ::CatnetUtils::Log::GetWhiskerLogger()->trace(__VA_ARGS__)
#define WK_INFO(...)     ::CatnetUtils::Log::GetWhiskerLogger()->info(__VA_ARGS__)
#define WK_WARN(...)     ::CatnetUtils::Log::GetWhiskerLogger()->warn(__VA_ARGS__)
#define WK_ERROR(...)    ::CatnetUtils::Log::GetWhiskerLogger()->error(__VA_ARGS__)
#define WK_CRITICAL(...) ::CatnetUtils::Log::GetWhiskerLogger()->critical(__VA_ARGS__)

#endif /* LOG_HPP */
