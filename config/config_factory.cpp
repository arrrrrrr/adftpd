//
// Created by mikey on 29/08/2020.
//

#include "config_factory.h"

namespace config {
    ConfigFactory::ConfigFactory(config::Mode mode) :
            mode_(mode)
    {
    }

    Reader *ConfigFactory::MakeReader() {
        switch (mode_) {
            case config::Mode::kMaster:
                return new config::MasterReader();
            case config::Mode::kSlave:
                return new config::SlaveReader();
            default:
                throw ConfigException("Invalid mode");
        }
    }
}