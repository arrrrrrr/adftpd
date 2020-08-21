//
// Created by mikey on 15/08/2020.
//
#include "default_config.h"

/**
 * Static definitions for the config namespace
 */
namespace config::defaults {
    const char *master =
            u8R"(
        {You ne
            "info": {
                "name": "My adftpd server",
                "welcome_msg": "Welcome",
            },
            "core": {
                "bind": {
                    "ipv4": [
                        "*"
                    ],
                    "ipv6": [
                        "*"
                    ],
                    "port": 8910
                },
                "pasv": {
                    "ipv4": "0.0.0.0",
                    "ipv6": "::",
                    "port_range": [
                        "48000-50000",
                    ]
                },
                "max_connections": 30,
            },
            "database": {
                "server": {
                    "ip": "0.0.0.0",
                    "port": 5300
                },
                "name": "adftpd"
            }
        }
        )";

    const char *slave =
            u8R"(
            "info": {
                "name": "slave1"
            },
            "core": {
                "bind": {
                    "ipv4": [
                        "*"
                    ],
                    "ipv6": [
                        "*"
                    ],
                    "port": 8910
                },
            },
        )";
}

namespace config {
    using namespace boost::property_tree;

    default_config::default_config() {
        make_props();
    }

    void default_config::make_props() {
        json_parser::read_json(::config::defaults::master, m_master);
        json_parser::read_json(::config::defaults::slave, m_slave);
    }

    default_config& default_config::get_instance() {
        static default_config(instance);
        return instance;
    }

    const ptree& default_config::master() {
        return m_master;
    }

    const ptree& default_config::slave() {
        return m_slave;
    }
}

