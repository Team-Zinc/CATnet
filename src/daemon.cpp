#include <iostream>
#include <cstdlib>

#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>

#include "logging/include/log.hpp"
#include "participant/participant.hpp"
#include "registrar/registrar.hpp"

int main(int argc, char *argv[]) {
    // Tell the user to get help if they are clueless
    if (argc == 1) {
        std::cerr << "Please use the -h (--help) flag to get the usage." << std::endl;
        return EXIT_FAILURE;
    }

    // Construct the application
    CLI::App app{"CATnet Daemon (github.com/ZincSoft/CATnet)"};
    CLI::App& participant_subcom = *app.add_subcommand("participant", "for people who want to take advantage");
    CLI::App& registrar_subcom = *app.add_subcommand("registrar", "for people who want to give advantage");
    app.require_subcommand();

    // Add flags, options, and such
    spdlog::level::level_enum spdlog_level{spdlog::level::level_enum::warn};
    // Specify string to enum value mappings for spdlog level enum.
        
    app.add_option("-l,--level", spdlog_level, "Minimum log output level")
        ->transform(CLI::CheckedTransformer(Log::GetStrEnumConversionMap(), CLI::ignore_case));

    // Parse command line arguments. There is macro to do this,
    // CLI11_PARSE(cli_global, argc, argv), but that doesn't seem
    // like such a good idea, with avoiding macros and all.
    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError& e) {
        return app.exit(e);
    }

    // Init logging
    Log::Init(spdlog_level);

    // Call the correct code based on what subcommand is given.
    // Please note that once the participant/registrar clases
    // go out of scope, their destructor will be called.
    if (participant_subcom) {
        Participant participant;
        participant.run();

        return EXIT_SUCCESS;
    } else if (registrar_subcom) {
        Registrar registrar;
        registrar.run();
 
        return EXIT_SUCCESS;
    }

    // This should only be called if no subcommands are called (see above).
    std::cerr << "Unknown subcommand. Please use the -h (--help) flag to get the usage." << std::endl;

    return EXIT_FAILURE;
}
