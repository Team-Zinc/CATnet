#ifndef LOG_HPP
#define LOG_HPP

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace CatnetUtils {
	/// \brief A singleton class that has getters and setters for shared spdlog logger pointers.
	class Log {
	public:
		/// An init function that initializes spdlog sinks, sets patterns, and regisers everything.
		static void Init();

		/// \brief A getter function for the head logger.
		static std::shared_ptr<spdlog::logger>& GetHeadLogger() { return s_HeadLogger; }
		/// \brief A getter function for the whisker logger.
		static std::shared_ptr<spdlog::logger>& GetWhiskerLogger() { return s_WhiskerLogger; }
	private:
		/// \brief A shared pointer that, once initialized, points to a spd logger for head.
		static std::shared_ptr<spdlog::logger> s_HeadLogger;
		/// \brief A shared pointer that, once initialized, points to a spd logger for whisker.
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
