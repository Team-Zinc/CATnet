#ifdef _WIN32
#error Please note that CATNET is not ready for Windows. This is because we do not have a testing machine. // TODO: Add windows support
#endif /* _WIN32 */

#include <iostream>

#include <CLI/CLI.hpp>

#include <head_whisker_exchange.pb.h>
#include <log.hpp>
#include "participant/participant.hpp"
#include "registrar/registrar.hpp"

int main(int argc, char *argv[]) {
    // Tell the user to get help if they are clueless
    if (argc == 1) {
        std::cerr << "Please use the -h (--help) flag to get the usage." << std::endl;
        return EXIT_FAILURE;
    }

    // Check if we have the right Google ProtoBuf version
    GOOGLE_PROTOBUF_VERIFY_VERSION;

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
        google::protobuf::ShutdownProtobufLibrary();

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

        CND_INFO("Cleaning up generally unsavory bits....");
        participant.~Participant();
        google::protobuf::ShutdownProtobufLibrary();

        return EXIT_SUCCESS;
    } else if (registrar_subcom) {
        Registrar registrar;
        registrar.run();

        CND_INFO("Cleaning up generally unsavory bits....");
        registrar.~Registrar();
        google::protobuf::ShutdownProtobufLibrary();

        return EXIT_SUCCESS;
    }

    // This should only be called if no subcommands are called (see above).
    std::cerr << "Unknown subcommand. Please use the -h (--help) flag to get the usage." << std::endl;
    
    google::protobuf::ShutdownProtobufLibrary();

    return EXIT_FAILURE;
}
