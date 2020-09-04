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

    public:
        ConfigBuilder();
        ~ConfigBuilder();

        void set_reader(Reader *config_reader);
        ptree build();
    };
}