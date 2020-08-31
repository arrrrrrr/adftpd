//
// Created by mikey on 15/08/2020.
//
#include "default_config.h"

/**
 * Static definitions for the config namespace
 */
namespace config::defaults {

}

namespace config {
    using namespace boost::property_tree;

    DefaultConfig::DefaultConfig() {
        ReadDefaults();
    }

    void DefaultConfig::ReadDefaults() {
        json_parser::read_json(master_config, master_);
        json_parser::read_json(slave_config, slave_);
    }

    DefaultConfig& DefaultConfig::get_instance() {
        static DefaultConfig(instance);
        return instance;
    }

    const ptree& DefaultConfig::get_master_config() {
        return master_;
    }

    const ptree& DefaultConfig::get_slave_config() {
        return slave_;
    }
}

