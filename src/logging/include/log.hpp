#ifndef LOG_HPP
#define LOG_HPP

#include <memory>
#include <map>
#include <unordered_map>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

enum Logger {
    DAEMON,
    DAEMON_WORKER,
    DAEMON_PARTICIPANT_PE,
    DAEMON_PARTICIPANT_RE,
    DAEMON_REGISTRAR
};

/// \brief A singleton class that has getters and setters for shared spdlog logger pointers.
class Log {
public:
	/// \brief An init function that initializes spdlog sinks, sets patterns, and regisers everything.
	static void Init(spdlog::level::level_enum);

	/// \brief A getter function for the daemon logger.
	static std::shared_ptr<spdlog::logger>& GetLogger(Logger logger) { return s_Loggers.at(logger); }

    static std::map<std::string, spdlog::level::level_enum> GetStrEnumConversionMap();
private:
    inline static std::unordered_map<Logger, std::shared_ptr<spdlog::logger>> s_Loggers;
};

// TODO: I'm ashamed of this
#define CND_DAEMON_TRACE(...)              ::Log::GetLogger(::Logger::DAEMON)->trace(__VA_ARGS__)
#define CND_DAEMON_DEBUG(...)              ::Log::GetLogger(::Logger::DAEMON)->debug(__VA_ARGS__)
#define CND_DAEMON_INFO(...)               ::Log::GetLogger(::Logger::DAEMON)->info(__VA_ARGS__)
#define CND_DAEMON_WARN(...)               ::Log::GetLogger(::Logger::DAEMON)->warn(__VA_ARGS__)
#define CND_DAEMON_ERROR(...)              ::Log::GetLogger(::Logger::DAEMON)->error(__VA_ARGS__)
#define CND_DAEMON_CRITICAL(...)           ::Log::GetLogger(::Logger::DAEMON)->critical(__VA_ARGS__)

#define CND_WORKER_TRACE(...)              ::Log::GetLogger(::Logger::DAEMON_WORKER)->trace(__VA_ARGS__)
#define CND_WORKER_DEBUG(...)              ::Log::GetLogger(::Logger::DAEMON_WORKER)->debug(__VA_ARGS__)
#define CND_WORKER_INFO(...)               ::Log::GetLogger(::Logger::DAEMON_WORKER)->info(__VA_ARGS__)
#define CND_WORKER_WARN(...)               ::Log::GetLogger(::Logger::DAEMON_WORKER)->warn(__VA_ARGS__)
#define CND_WORKER_ERROR(...)              ::Log::GetLogger(::Logger::DAEMON_WORKER)->error(__VA_ARGS__)
#define CND_WORKER_CRITICAL(...)           ::Log::GetLogger(::Logger::DAEMON_WORKER)->critical(__VA_ARGS__)

#define CND_PARTICIPANT_PE_TRACE(...)      ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_PE)->trace(__VA_ARGS__)
#define CND_PARTICIPANT_PE_DEBUG(...)      ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_PE)->debug(__VA_ARGS__)
#define CND_PARTICIPANT_PE_INFO(...)       ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_PE)->info(__VA_ARGS__)
#define CND_PARTICIPANT_PE_WARN(...)       ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_PE)->warn(__VA_ARGS__)
#define CND_PARTICIPANT_PE_ERROR(...)      ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_PE)->error(__VA_ARGS__)
#define CND_PARTICIPANT_PE_CRITICAL(...)   ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_PE)->critical(__VA_ARGS__)

#define CND_PARTICIPANT_RE_TRACE(...)      ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_RE)->trace(__VA_ARGS__)
#define CND_PARTICIPANT_RE_DEBUG(...)      ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_RE)->debug(__VA_ARGS__)
#define CND_PARTICIPANT_RE_INFO(...)       ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_RE)->info(__VA_ARGS__)
#define CND_PARTICIPANT_RE_WARN(...)       ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_RE)->warn(__VA_ARGS__)
#define CND_PARTICIPANT_RE_ERROR(...)      ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_RE)->error(__VA_ARGS__)
#define CND_PARTICIPANT_RE_CRITICAL(...)   ::Log::GetLogger(::Logger::DAEMON_PARTICIPANT_RE)->critical(__VA_ARGS__)

#define CND_REGISTRAR_CRITICAL(...)        ::Log::GetLogger(::Logger::DAEMON_REGISTRAR)->critical(__VA_ARGS__)
#define CND_REGISTRAR_TRACE(...)           ::Log::GetLogger(::Logger::DAEMON_REGISTRAR)->trace(__VA_ARGS__)
#define CND_REGISTRAR_DEBUG(...)           ::Log::GetLogger(::Logger::DAEMON_REGISTRAR)->debug(__VA_ARGS__)
#define CND_REGISTRAR_INFO(...)            ::Log::GetLogger(::Logger::DAEMON_REGISTRAR)->info(__VA_ARGS__)
#define CND_REGISTRAR_WARN(...)            ::Log::GetLogger(::Logger::DAEMON_REGISTRAR)->warn(__VA_ARGS__)
#define CND_REGISTRAR_ERROR(...)           ::Log::GetLogger(::Logger::DAEMON_REGISTRAR)->error(__VA_ARGS__)
#define CND_REGISTRAR_CRITICAL(...)        ::Log::GetLogger(::Logger::DAEMON_REGISTRAR)->critical(__VA_ARGS__)


#endif /* LOG_HPP */
