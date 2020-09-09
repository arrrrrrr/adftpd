//
// Created by mikey on 9/08/2020.
//

#include "slave_reader.h"

namespace config {
    ptree& SlaveReader::Parse(std::string file) {
        namespace bp = boost::property_tree;

        ptree user_props;

        try {
            ReadJsonFile(file, user_props);
            ReadJsonFromCharBuffer(config::slave_config, std::strlen(config::master_config), props_);
        }
        catch (bp::json_parser_error &e) {
            throw ConfigException(e.message().c_str());
        }

        return props_;
    }
}
