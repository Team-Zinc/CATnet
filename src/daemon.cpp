#ifdef _WIN32
#error Please note that CATNET is not supported on Windows. This is because we do not have a testing machine. // TODO: Add windows support
#endif /* _WIN32 */

#include <CLI/CLI.hpp>
#include <google/protobuf/stubs/common.h>
#include <sodium.h>

#ifdef __linux__
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/random.h>
#endif /* __linux__ */

#include <head_whisker_exchange.pb.h>
#include <log.hpp>
#include "participant/participant.hpp"
#include "registrar/registrar.hpp"

/// Application to hold everything
struct Application {
    Application() {
        // Do we have the correct protobuf version?
        GOOGLE_PROTOBUF_VERIFY_VERSION;

        // Is our entropy high enough?
#if defined(__linux__) && defined(RNDGETENTCNT)
        int fd;
        int c;

        if ((fd = open("/dev/random", O_RDONLY)) != -1) {
            if (ioctl(fd, RNDGETENTCNT, &c) == 0 && c < 160) {
                std::cerr << "This system currently doesn't have a high enough entropy level to quickly generate\n"
                    "random numbers of high quality. Installing rng-utils/tools, jitterentropy or haveged packages\n"
                    "may help with this. On Linux inside a VM, please cosider using virtio-rng\n\n"
                    "CATnet will stall until enough entropy has been collected. Please do random actions if\n"
                    "you wish to speed this process up!" << std::endl;
            }
            (void) close(fd);
        }
#endif

        // Initialize sodium
        if (sodium_init() < 0) {
            perror("Could not initialize LibSodium");
        }
    }

    // Run the main bulk of the program
    int run(int argc, char *argv[]) {
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
        CND_DAEMON_DEBUG("Staring....");
        if (participant_subcom) {
            Participant participant;
            participant.run();

            CND_DAEMON_DEBUG("Cleaning up generally unsavory bits....");
            participant.~Participant();

            return EXIT_SUCCESS;
        } else if (registrar_subcom) {
            Registrar registrar;
            registrar.run();

            CND_DAEMON_DEBUG("Cleaning up generally unsavory bits....");
            registrar.~Registrar();

            return EXIT_SUCCESS;
        }

        // This should only be called if no subcommands are called (see above).
        std::cerr << "Unknown subcommand. Please use the -h (--help) flag to get the usage." << std::endl;
    
        return EXIT_FAILURE;
    }

    /// Destroy all that needs to be destroyed
    ~Application() {
        google::protobuf::ShutdownProtobufLibrary();
    }
};

int main(int argc, char *argv[]) {
    Application application;
    application.run(argc, argv);
}

