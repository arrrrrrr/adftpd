//
// Created by mikey on 4/09/2020.
//

#pragma once
#include "config/common.h"

namespace config {
    using namespace boost::property_tree;

    class ConfigBuilder {
    protected:
        Reader *config_reader_;
        std::string config_file_;

    public:
        ConfigBuilder();
        ~ConfigBuilder();

        ConfigBuilder& set_reader(Reader *config_reader);
        ConfigBuilder& set_config(std::string& file);
        ptree build();
    };
}