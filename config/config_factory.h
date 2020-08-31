//
// Created by mikey on 29/08/2020.
//

#pragma once
#include "config/constants.h"
#include "config/master_reader.h"
#include "config/slave_reader.h"

#include <exception>

namespace config {
    class ConfigException : public std::exception {
    private:
        const char *message_;
    public:
        ConfigException(const char *message);
        const char * what() const override;
    };

    class ConfigFactory {
    private:
        config::Mode mode_;
    public:
        ConfigFactory(config::Mode mode);
        Reader *MakeReader(std::string config_file);
    };
}


