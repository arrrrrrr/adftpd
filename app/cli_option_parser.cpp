//
// Created by mikey on 30/08/2020.
//

#include "cli_option_parser.h"

app::CliOptionException::CliOptionException(const char *message) :
        message_(message)
{
}

app::CliOptionException::~CliOptionException() noexcept {
}

const char *app::CliOptionException::what() const {
    return message_;
}

void app::CliOptionParser::ParseOptions(int argc, char **argv) {
    namespace po = boost::program_options;

    /**
     * Setup argument parsing using boost
     */
    po::options_description desc("Options:");
    desc.add_options()
            ("help", "Option help")
            ("master", "Run the server in master mode. Only one get_master_config can run")
            ("slave", "Run the server in slave mode. Many slaves can run")
            ("daemonize", po::value<bool>(&(test_))->default_value(false),
             "Run in daemon mode")
            ("test", po::value<bool>(&(test_))->default_value(false),
             "Test the configuration file")
            ("config", po::value<std::string>(&(config_file_))->default_value("./config.json"),
             "Path to the config file [Default: ./config.json]")
            ("verbose", po::value<int>(&(verbosity_))->default_value(0),
             "Logging verbosity");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        throw CliOptionException("help");
    }

    if (vm.count("master")) {
        mode_ = config::Mode::kMaster;
    } else if (vm.count("slave")) {
        mode_ = config::Mode::kSlave;
    } else {
        throw CliOptionException("Master or slave option must be specified");
    }

    if (vm.count("daemonize")) {
        daemonize_ = true;
    }

    if (vm.count("test")) {
        test_ = true;
    }

    if (vm.count("verbose")) {
        int tmp_verbosity = vm["verbose"].as<int>();
        if (tmp_verbosity >= 0 && tmp_verbosity <= 2) {
            verbosity_ = tmp_verbosity;
        } else {
            throw CliOptionException("Verbosity must be between 0 and 2");
        }
    }
}

app::CliOptionParser::CliOptionParser(int argc, char **argv) :
    mode_(config::kMaster), daemonize_(false), test_(false)
{
}

config::Mode app::CliOptionParser::get_mode() const {
    return mode_;
}

int app::CliOptionParser::get_verbosity() const {
    return verbosity_;
}

bool app::CliOptionParser::get_daemonize() const {
    return daemonize_;
}

bool app::CliOptionParser::get_test_mode() const {
    return test_;
}

std::string app::CliOptionParser::get_config_file() const {
    return config_file_;
}


