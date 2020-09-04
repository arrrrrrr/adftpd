//
// Created by mikey on 9/08/2020.
//

#pragma once

#include "config/constants.h"
#include "config/config_exception.h"

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace config {
    using namespace boost::property_tree;

    class Reader {
    protected:
        const char *config_;
        ptree props_;

        void MergePropertyTrees(ptree& default_props, ptree& user_props);

    public:
        Reader(const char *config);
        ~Reader();
        virtual ptree& parse() = 0;
    };
}
