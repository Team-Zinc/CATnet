#include "include/log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

std::shared_ptr<spdlog::logger> Log::s_DaemonLogger;

void Log::Init(spdlog::level::level_enum level) {
    std::vector<spdlog::sink_ptr> logSinks;
	logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("catnet-daemon.log", true));

	logSinks[0]->set_pattern("%^[%T] %n: %v%$");
	logSinks[1]->set_pattern("[%T] [%l] %n: %v");

	s_DaemonLogger = std::make_shared<spdlog::logger>("DAEMON", begin(logSinks), end(logSinks));
	spdlog::register_logger(s_DaemonLogger);
	s_DaemonLogger->set_level(level);
	s_DaemonLogger->flush_on(level);
}

std::map<std::string, spdlog::level::level_enum> Log::GetStrEnumConversionMap() {
    return {{"trace", spdlog::level::level_enum::trace},
        {"debug", spdlog::level::level_enum::debug},
        {"info", spdlog::level::level_enum::info},
        {"warn", spdlog::level::level_enum::warn},
        {"error", spdlog::level::level_enum::err},
        {"critical", spdlog::level::level_enum::critical},
        {"headless", spdlog::level::level_enum::off}
    };
}

