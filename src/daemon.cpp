#include <iostream>
#include <cstdlib>

#include <log.hpp>

int main(int argc, char *argv[]) {
    CatnetUtils::Log::Init();

    CND_INFO("This is the daemon speaking, please shut the fuck up.");

    return EXIT_SUCCESS;
}
