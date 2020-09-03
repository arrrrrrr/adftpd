//
// Created by mikey on 31/08/2020.
//

#include "console_logger.h"

app::ConsoleLogger::~ConsoleLogger() {
}

void app::ConsoleLogger::log(std::string line) {
    std::cout << line << std::endl;
}