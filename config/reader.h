//
// Created by mikey on 9/08/2020.
//

#pragma once

#include "config/constants.h"
#include "config/config_exception.h"

#include <string>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace config {
    using namespace boost::property_tree;

    class Reader {
    protected:
        ptree props_;

        void ReadJsonFile(std::string file, ptree& out_props);
        void ReadJsonFromCharBuffer(const char *buffer, int length, ptree& out_props);
    public:
        Reader();
        ~Reader();
        virtual ptree& Parse(std::string file) = 0;
    };
}
