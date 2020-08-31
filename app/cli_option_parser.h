//
// Created by mikey on 30/08/2020.
//

#pragma once
#include "config/constants.h"

#include <string>
#include <iostream>
#include <exception>
#include <boost/program_options.hpp>

namespace app {
    class CliOptionException : public std::exception {
    private:
        const char *message_;

    public:
        CliOptionException(const char *message);
        const char *what() const override;
        ~CliOptionException() noexcept override;
    };

    class CliOptionParser {
    private:
        config::Mode mode_;
        int verbosity_;
        bool daemonize_;
        bool test_;
        std::string config_file_;

        void ParseOptions(int argc, char **argv);

    public:
        CliOptionParser(int argc, char **argv);
        config::Mode get_mode() const;
        int get_verbosity() const;
        bool get_daemonize() const;
        bool get_test_mode() const;
        std::string get_config_file() const;
    };
}
