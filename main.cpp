#include "config/config_factory.h"

#include <iostream>
#include <string>

#include "application.h"

int main(int argc, char **argv) {
    try {
        Application app(argc, argv);
    }
    catch (app::CliOptionException& e) {
        e.what();
        return 1;
    }

    return 0;
}
