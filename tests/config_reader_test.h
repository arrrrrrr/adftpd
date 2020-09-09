//
// Created by mikey on 4/09/2020.
//
#pragma once
#include "config/common.h"
#include "gtest/gtest.h"

#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace {
    namespace bp = boost::property_tree;
    namespace bios = boost::iostreams;

    void read_json_from_buffer(const char *buf, int length, bp::ptree &props) {
        bios::stream<bios::array_source> buf_stream(buf, length);
        bp::json_parser::read_json(buf_stream, props);
    }

    TEST(ConfigReader, ReadMasterDefaults) {
        bp::ptree props;

        try {
            read_json_from_buffer(config::master_config, std::strlen(config::master_config), props);
        }
        catch (bp::json_parser_error &e) {
            std::cout << e.message() << std::endl;
        }

        auto info_name_str = props.get<std::string>("info.name");
        auto info_welcome_msg_str = props.get<std::string>("info.welcome_msg");

        EXPECT_EQ(info_name_str, "My adftpd server");
        EXPECT_EQ(info_welcome_msg_str, "Welcome");
    }

    TEST(ConfigReader, ReadSlaveDefaults) {
        bp::ptree props;
        read_json_from_buffer(config::slave_config, std::strlen(config::slave_config), props);
    }
}