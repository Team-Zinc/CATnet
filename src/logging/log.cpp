#include "include/log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace CatnetUtils {
	std::shared_ptr<spdlog::logger> Log::s_HeadLogger;
	std::shared_ptr<spdlog::logger> Log::s_WhiskerLogger;

	void Log::Init() {
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("cat.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		s_HeadLogger = std::make_shared<spdlog::logger>("HEAD", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_HeadLogger);
		s_HeadLogger->set_level(spdlog::level::trace);
		s_HeadLogger->flush_on(spdlog::level::trace);

		s_WhiskerLogger = std::make_shared<spdlog::logger>("WHISKER", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_WhiskerLogger);
		s_WhiskerLogger->set_level(spdlog::level::trace);
		s_WhiskerLogger->flush_on(spdlog::level::trace);
	}

}
