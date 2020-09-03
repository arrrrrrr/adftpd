//
// Created by mikey on 29/08/2020.
//

#include "gtest/gtest.h"
#include "config/common.h"
#include "app/common.h"

namespace {
    TEST(CliOptions, DefaultsMaster) {
        int argc = 2;
        char *argv[] = { "program", "--master" };
        app::CliOptionParser parser(argc, static_cast<char **>(argv));
        EXPECT_EQ(parser.get_config_file(), std::string("./config.json"));
        EXPECT_EQ(parser.get_daemonize(), false);
        EXPECT_EQ(parser.get_mode(), config::kMaster);
        EXPECT_EQ(parser.get_test_mode(), false);
        EXPECT_EQ(parser.get_verbosity(), 0);
    }

    TEST(CliOptions, DefaultsSlave) {
        int argc = 2;
        char *argv[] = { "program", "--slave" };
        app::CliOptionParser parser(argc, static_cast<char **>(argv));
        EXPECT_EQ(parser.get_config_file(), std::string("./config.json"));
        EXPECT_EQ(parser.get_daemonize(), false);
        EXPECT_EQ(parser.get_mode(), config::kSlave);
        EXPECT_EQ(parser.get_test_mode(), false);
        EXPECT_EQ(parser.get_verbosity(), 0);
    }

    TEST(CliOptions, DaemonizeOption) {
        int argc = 3;
        char *argv[] = { "program", "--master", "--daemonize" };
        app::CliOptionParser parser(argc, static_cast<char **>(argv));
        EXPECT_EQ(parser.get_daemonize(), true);
    }

    TEST(CliOptions, TestOption) {
        int argc = 3;
        char *argv[] = { "program", "--master", "--test" };
        app::CliOptionParser parser(argc, static_cast<char **>(argv));
        EXPECT_EQ(parser.get_test_mode(), true);
    }

    TEST(CliOptions, VerbosityValidMin) {
        int argc = 4;
        char *argv[] = { "program", "--master", "--verbosity", "0" };
        app::CliOptionParser parser(argc, static_cast<char **>(argv));
        EXPECT_EQ(parser.get_verbosity(), 0);
    }

    TEST(CliOptions, VerbosityValidMax) {
        int argc = 4;
        char *argv[] = { "program", "--master", "--verbosity", "2" };
        app::CliOptionParser parser(argc, static_cast<char **>(argv));
        EXPECT_EQ(parser.get_verbosity(), 2);
    }

    TEST(CliOptions, VerbosityOutOfRangeException) {
        int argc = 4;
        char *argv[] = { "program", "--master", "--verbosity", "3" };
        EXPECT_THROW(app::CliOptionParser parser(argc, static_cast<char **>(argv)), app::CliOptionException);
    }
}

