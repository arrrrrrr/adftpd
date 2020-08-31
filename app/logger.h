//
// Created by mikey on 31/08/2020.
//

#pragma once
#include <string>

namespace app {
    class Logger {
    public:
        virtual void log(std::string line) = 0;
        virtual ~Logger();
    };
}




