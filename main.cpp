#include "config/config_factory.h"

#include <iostream>
#include <string>
#include <boost/program_options.hpp>

struct cli_opts {
    config::Mode mode;
    int verbosity;
    bool daemonize;
    bool test;
    bool log_to_file;
    std::string config_file;
    std::string log_file;

    cli_opts() {
        mode = config::Mode::kMaster;
        daemonize = false;
        test = false;
        log_to_file = false;
    }
};

int parse_options(int argc, char **argv, cli_opts& co) {
    namespace po = boost::program_options;

    /**
     * Setup argument parsing using boost
     */
    po::options_description desc("Options:");
    desc.add_options()
            ("help", "Option help")
            ("master", "Run the server in master mode. Only one master can run")
            ("slave", "Run the server in slave mode. Many slaves can run")
            ("daemonize", "Run in daemon mode")
            ("test", "Test the configuration file")
            ("config", po::value<std::string>(&(co.config_file))->default_value("./config.json"),
             "Path to the config file [Default: ./config.json]")
            ("log", po::value<std::string>(&(co.log_file))->default_value("./adftpd.log"),
             "Path to the log file")
            ("verbose", po::value<int>(&(co.verbosity))->default_value(0),
             "Logging verbosity")
            ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

    if (vm.count("master")) {
        co.mode = config::Mode::kMaster;
    }
    else if (vm.count("slave")) {
        co.mode = config::Mode::kSlave;
    }
    else {
        std::cout << "Master or slave option must be specified" << std::endl;
        return 1;
    }

    if (vm.count("daemonize")) {
        co.daemonize = true;
    }

    if (vm.count("test")) {
        co.test = true;
    }

    if (vm.count("log")) {
        co.log_to_file = true;
    }

    if (vm.count("verbose")) {
        int tmp_verbosity = vm["verbose"].as<int>();
        if (tmp_verbosity >= 0 && tmp_verbosity <= 2) {
            co.verbosity = tmp_verbosity;
        }
        else {
            std::cout << "Verbosity must be between 0 and 2" << std::endl;
            return 1;
        }
    }

    return 0;
}


int main(int argc, char **argv) {
    // parse the command line options
    cli_opts co;
    int res = parse_options(argc, argv, co);

    if (res > 0)
        return res;

    std::cout << "Mode: " << co.mode << std::endl;
    std::cout << "Verbosity: " << co.verbosity << std::endl;
    std::cout << "Daemonize: " << co.daemonize << std::endl;
    std::cout << "Config: " << co.config_file << std::endl;

    return 0;
}
