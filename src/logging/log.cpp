#include "include/log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace CatnetUtils {
	std::shared_ptr<spdlog::logger> Log::s_DaemonLogger;

	void Log::Init() {
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("catnet-daemon.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		s_DaemonLogger = std::make_shared<spdlog::logger>("DAEMON", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_DaemonLogger);
		s_DaemonLogger->set_level(spdlog::level::trace);
		s_DaemonLogger->flush_on(spdlog::level::trace);
	}

}
