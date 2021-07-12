#ifndef LOG_HPP
#define LOG_HPP

#include <memory>
#include <unordered_map>

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

/// Contains all possible locations to log from.
enum Logger
{
	DAEMON,
	DAEMON_WORKER,
	DAEMON_PARTICIPANT_PE,
	DAEMON_PARTICIPANT_RE,
	DAEMON_REGISTRAR
};

/// A singleton class that has getters and setters for shared spdlog
/// logger pointers.
class Log
{
  public:
	/// An init function that initializes spdlog sinks, sets patterns,
	/// and regisers everything.
	static void Init(spdlog::level::level_enum);

	/// A getter function for the daemon logger. Don't call this directly,
	// instead call the macros.
	static std::shared_ptr<spdlog::logger>& GetLogger(Logger logger)
	{
		return s_Loggers.at(logger);
	}

	/// Getter function for s_Loggers
	static std::unordered_map<std::string, spdlog::level::level_enum>
	GetStrEnumConversionMap();

  private:
	/// Map that contains maping data from an input string to a logging level
	/// enum.
	///     "debug" -> spd::level::level_enum::DEBUG
	///     "error" -> spd::level::level_enum::ERROR
	inline static std::unordered_map<Logger, std::shared_ptr<spdlog::logger>>
	  s_Loggers;
};

// TODO: I'm ashamed of this
/// Daemon trace logging macro.
#define CND_DAEMON_TRACE(...)                                                  \
	::Log::GetLogger(::Logger::DAEMON)->trace(__VA_ARGS__)
/// Daemon debug logging macro.
#define CND_DAEMON_DEBUG(...)                                                  \
	::Log::GetLogger(::Logger::DAEMON)->debug(__VA_ARGS__)
/// Daemon info logging macro.
#define CND_DAEMON_INFO(...)                                                   \
	::Log::GetLogger(::Logger::DAEMON)->info(__VA_ARGS__)
/// Daemon warn logging macro.
#define CND_DAEMON_WARN(...)                                                   \
	::Log::GetLogger(::Logger::DAEMON)->warn(__VA_ARGS__)
/// Daemon error logging macro.
#define CND_DAEMON_ERROR(...)                                                  \
	::Log::GetLogger(::Logger::DAEMON)->error(__VA_ARGS__)
/// Daemon critical logging macro.
#define CND_DAEMON_CRITICAL(...)                                               \
	::Log::GetLogger(::Logger::DAEMON)->critical(__VA_ARGS__)

#endif /* LOG_HPP */
