#include "include/log.hpp"
#include "spdlog/spdlog.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <vector>

void Log::Init(spdlog::level::level_enum level) {
     std::vector<spdlog::sink_ptr> logSinks;
	logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("catnet-daemon.log", true));

    logSinks[0]->set_pattern("%^ %-8l: [%t] [%T] %n: %v%$");
	logSinks[1]->set_pattern("%-8l: [%t] [%T] %n: %v");


    s_Loggers.insert({
        {Logger::DAEMON, std::make_shared<spdlog::logger>(spdlog::logger("DAEMON", begin(logSinks), end(logSinks)))},
        {Logger::DAEMON_WORKER, std::make_shared<spdlog::logger>(spdlog::logger("WORKER", begin(logSinks), end(logSinks)))},
        {Logger::DAEMON_REGISTRAR, std::make_shared<spdlog::logger>(spdlog::logger("REGISTRAR", begin(logSinks), end(logSinks)))},
        {Logger::DAEMON_PARTICIPANT_RE, std::make_shared<spdlog::logger>(spdlog::logger("PARTICIPANT (Registrar Exchange Thread)", begin(logSinks), end(logSinks)))},
        {Logger::DAEMON_PARTICIPANT_PE, std::make_shared<spdlog::logger>(spdlog::logger("PARTICIPANT (Participant Exchange Thread)", begin(logSinks), end(logSinks)))}
    });

    for (auto& kv : s_Loggers) {
        auto logger = kv.second;
        spdlog::register_logger(logger);
        logger->set_level(level);
        logger->flush_on(level);
    }
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

