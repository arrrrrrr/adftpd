//
// Created by mikey on 29/08/2020.
//

#include "config_factory.h"

namespace config {

    ConfigException::ConfigException(const char *message) :
        message_(message)
    {
    }

    const char *ConfigException::what() const {
        return message_;
    }

    ConfigFactory::ConfigFactory(config::Mode mode) :
        mode_(mode)
    {
    }

    Reader *ConfigFactory::MakeReader(std::string config_file) {
        switch (mode_) {
            case config::Mode::kMaster:
                return new config::MasterReader(config_file);
            case config::Mode::kSlave:
                return new config::SlaveReader(config_file);
            default:
                throw ConfigException("Invalid mode");
        }
    }
}