//
// Created by mikey on 4/09/2020.
//

#include "config_exception.h"
config::ConfigException::ConfigException(const char *message) :
        message_(message)
{
}

const char *config::ConfigException::what() const {
    return message_;
}

