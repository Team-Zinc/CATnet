#ifndef LOG_HPP
#define LOG_HPP

#include <memory>
#include <map>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

/// \brief A singleton class that has getters and setters for shared spdlog logger pointers.
class Log {
public:
	/// \breif An init function that initializes spdlog sinks, sets patterns, and regisers everything.
	static void Init(spdlog::level::level_enum);

	/// \brief A getter function for the daemon logger.
	static std::shared_ptr<spdlog::logger>& GetDaemonLogger() { return s_DaemonLogger; }

    static std::map<std::string, spdlog::level::level_enum> GetStrEnumConversionMap();
private:
	/// \brief A shared pointer that, once initialized, points to a spd logger for the daemon.
	static std::shared_ptr<spdlog::logger> s_DaemonLogger;
};

// Head log macros
#define CND_TRACE(...)    ::Log::GetDaemonLogger()->trace(__VA_ARGS__)
#define CND_WARN(...)     ::Log::GetDaemonLogger()->warn(__VA_ARGS__)
#define CND_INFO(...)     ::Log::GetDaemonLogger()->info(__VA_ARGS__)
#define CND_ERROR(...)    ::Log::GetDaemonLogger()->error(__VA_ARGS__)
#define CND_CRITICAL(...) ::Log::GetDaemonLogger()->critical(__VA_ARGS__)

#endif /* LOG_HPP */
