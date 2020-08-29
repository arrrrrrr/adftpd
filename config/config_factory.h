//
// Created by mikey on 29/08/2020.
//

#pragma once
#include "constants.h"
#include "master_reader.h"
#include "slave_reader.h"

#include <exception>

namespace config {
    class ConfigException : std::exception {
    private:
        std::string msg_;
    public:
        ConfigException(std::string msg);
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


