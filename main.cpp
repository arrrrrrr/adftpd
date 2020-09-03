#include "config/config_factory.h"

#include <iostream>
#include <string>

#include "application.h"

int main(int argc, char **argv) {
    Application app;
    return app.Run(argc, argv);
}
