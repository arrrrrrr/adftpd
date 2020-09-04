//
// Created by mikey on 4/09/2020.
//

#pragma once

#include "app/common.h"
#include "gtest/gtest.h"

namespace {
    TEST(Logger, ConsoleLoggerLog) {
        app::ConsoleLogger logger;
        testing::internal::CaptureStdout();
        logger.log("ConsoleLoggerLog test");
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, std::string("ConsoleLoggerLog test\n"));
    }

    TEST(Logger, FileLoggerLog) {
        std::vector<std::string> log_lines = { "FileLoggerLog test", "This is a test log line" };
        std::string log_file("test.log");

        {
            app::FileLogger logger(log_file);
            logger.log(log_lines[0]);
            logger.log(log_lines[1]);
        }

        std::ifstream lf_stream;
        lf_stream.open(log_file);

        EXPECT_EQ(lf_stream.is_open(), true);

        std::string line1, line2;
        std::getline(lf_stream, line1);
        std::getline(lf_stream, line2);

        EXPECT_EQ(line1, log_lines[0]);
        EXPECT_EQ(line2, log_lines[1]);

        lf_stream.close();
        std::remove(log_file.c_str());
    }
}