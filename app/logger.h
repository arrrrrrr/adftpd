//
// Created by mikey on 31/08/2020.
//

#pragma once
#include <string>

namespace app {
    class Logger {
    public:
        Logger() = default;
        virtual ~Logger() {};
        virtual void log(std::string line) = 0;
    };
}
