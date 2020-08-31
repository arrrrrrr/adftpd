//
// Created by mikey on 31/08/2020.
//

#pragma once
#include "app/common.h"

class Application {
private:
    app::CliOptionParser cli_options_;

public:
    Application(int argc, char **argv);
    ~Application();

    Application(Application&& app) = delete;
    Application(Application& app) = delete;
};



