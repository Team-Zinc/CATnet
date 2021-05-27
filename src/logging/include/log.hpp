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

		/// \brief A getter function for the daemon logger.
		static std::shared_ptr<spdlog::logger>& GetDaemonLogger() { return s_DaemonLogger; }
	private:
		/// \brief A shared pointer that, once initialized, points to a spd logger for the daemon.
		static std::shared_ptr<spdlog::logger> s_DaemonLogger;
	};

}

// Head log macros
#define CND_TRACE(...)    ::CatnetUtils::Log::GetDaemonLogger()->trace(__VA_ARGS__)
#define CND_WARN(...)     ::CatnetUtils::Log::GetDaemonLogger()->warn(__VA_ARGS__)
#define CND_INFO(...)     ::CatnetUtils::Log::GetDaemonLogger()->info(__VA_ARGS__)
#define CND_ERROR(...)    ::CatnetUtils::Log::GetDaemonLogger()->error(__VA_ARGS__)
#define CND_CRITICAL(...) ::CatnetUtils::Log::GetDaemonLogger()->critical(__VA_ARGS__)

#endif /* LOG_HPP */
