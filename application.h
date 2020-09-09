//
// Created by mikey on 31/08/2020.
//

#pragma once
#include "app/common.h"
#include "config/common.h"

class Application {
private:
public:
    Application(Application&& app) = delete;
    Application(Application& app) = delete;

    Application();
    ~Application();

    int Run(int argc, char **argv);
};



