//
// Created by mikey on 31/08/2020.
//

#include "application.h"

Application::Application()
{
}

Application::~Application()
{
}

int Application::Run(int argc, char **argv) {
    using namespace app;
    using namespace config;

    try {
        CliOptionParser cli_options(argc, argv);

    } catch (CliOptionException& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
