//
// Created by mikey on 9/08/2020.
//

#include "slave_reader.h"

namespace config {
    ptree& SlaveReader::parse() {
        ptree default_props, user_props;
        json_parser::read_json(config::slave_config, default_props);
        json_parser::read_json(config_, user_props);

        MergePropertyTrees(default_props, user_props);
        return props_;
    }
}
