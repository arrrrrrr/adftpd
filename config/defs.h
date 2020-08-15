//
// Created by mikey on 15/08/2020.
//

#ifndef ADFTPD_CONFIG_DEFS_H
#define ADFTPD_CONFIG_DEFS_H

/**
 * Static definitions for the config namespace
 */
namespace config::defaults {
    const char *master =
            u8R"(
        {
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

#endif //ADFTPD_CONFIG_DEFS_H
