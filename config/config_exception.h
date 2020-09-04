//
// Created by mikey on 4/09/2020.
//

#pragma once
#include <exception>

namespace config {
    class ConfigException : public std::exception {
    private:
        const char *message_;
    public:
        ConfigException(const char *message);
        const char * what() const override;
    };

}



