//
// Created by mikey on 31/08/2020.
//

#pragma once
#include "logger.h"

#include <iostream>

namespace app {
    class ConsoleLogger : public Logger {
    public:
        ConsoleLogger() = default;
        virtual ~ConsoleLogger();
        virtual void log(std::string line) override;
    };
}
