//
// Created by mikey on 4/09/2020.
//
#pragma once
#include "config/common.h"
#include "utils/json.h"
#include "gtest/gtest.h"

#include <vector>

#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace {
    namespace bp = boost::property_tree;
    namespace bios = boost::iostreams;

    void read_json_from_buffer(const char *buf, int length, bp::ptree &props) {
        try {
            bios::stream<bios::array_source> buf_stream(buf, length);
            bp::json_parser::read_json(buf_stream, props);
        }
        catch (bp::json_parser_error &e) {
            std::cout << e.message() << std::endl;
        }
    }

    TEST(ConfigReader, ReadMasterDefaults) {
        bp::ptree props;
        read_json_from_buffer(config::master_config, std::strlen(config::master_config), props);

        auto info_name_str = props.get<std::string>("info.name");
        auto info_welcome_msg_str = props.get<std::string>("info.welcome_msg");

        EXPECT_EQ(info_name_str, "My adftpd server");
        EXPECT_EQ(info_welcome_msg_str, "Welcome");
    }

    TEST(ConfigReader, ReadSlaveDefaults) {
        bp::ptree props;
        read_json_from_buffer(config::slave_config, std::strlen(config::slave_config), props);

        auto info_name_str = props.get<std::string>("info.name");
        EXPECT_EQ(info_name_str, "slave1");

        auto core_bind_port = props.get<int>("core.bind.port");
        EXPECT_EQ(core_bind_port, 8910);

        auto core_bind_ipv4 = utils::ptree_array_as_vector<std::string>(props, "core.bind.ipv4.");
        EXPECT_EQ(core_bind_ipv4.at(0), "*");
        EXPECT_EQ(core_bind_ipv4.size(), 1);

        auto core_bind_ipv6 = utils::ptree_array_as_vector<std::string>(props, "core.bind.ipv6.");
        EXPECT_EQ(core_bind_ipv6.at(0), "*");
        EXPECT_EQ(core_bind_ipv6.size(), 1);

        bp::ptree logging_2 = props.get_child("logging.");

        int ctr = 0;
        for (bp::ptree::iterator element = logging_2.begin(); element != logging_2.end(); element++) {
            auto log_output = element->second.get<std::string>("output");
            auto log_enabled = element->second.get<bool>("enabled");

            if (ctr == 0) {
                EXPECT_EQ(log_output, "stdout");
                EXPECT_EQ(log_enabled, true);
            }
            else if (ctr == 1) {
                EXPECT_EQ(log_output, "./adftpd.log");
                EXPECT_EQ(log_enabled, true);
            }

            ctr++;
        }

        EXPECT_EQ(ctr, 2);
    }
}