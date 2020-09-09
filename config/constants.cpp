//
// Created by mikey on 29/08/2020.
//

#include "constants.h"

namespace config {
    const char *master_config = u8R"(
        {
            "info": {
                "name": "My adftpd server",
                "welcome_msg": "Welcome"
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
                        "48000-50000"
                    ]
                },
                "max_connections": 30
            },
            "database": {
                "server": {
                    "ip": "0.0.0.0",
                    "port": 5300
                },
                "name": "adftpd"
            },
            "logging": [
                {
                    "output": "console",
                    "enabled": true
                },
                {
                    "output": "file",
                    "enabled": true,
                    "target": "./adftpd.log"
                }
            ]
        })";

    const char *slave_config =
            u8R"(
        {
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
                }
            },
            "logging": [
                {
                    "output": "console",
                    "enabled": true
                },
                {
                    "output": "file",
                    "enabled": true,
                    "target": "./adftpd.log"
                }
            ]
        }
        )";
}