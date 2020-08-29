//
// Created by mikey on 21/08/2020.
//

#pragma once

#include "constants.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace config {
    using namespace boost::property_tree;

    class DefaultConfig {
    private:
        ptree master_;
        ptree slave_;

        DefaultConfig();
        ~DefaultConfig() = default;
        DefaultConfig(const DefaultConfig&) = delete;
        DefaultConfig& operator=(const DefaultConfig&) = delete;
        void make_props();

    public:
        static DefaultConfig& get_instance();
        const ptree& master();
        const ptree& slave();
    };
}

