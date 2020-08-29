//
// Created by mikey on 9/08/2020.
//

#pragma once

#include <string>
#include "default_config.h"

namespace config {
    using namespace boost::property_tree;

    class Reader {
    protected:
        std::string m_file;
        ptree m_props;

    public:
        Reader(std::string file) : m_file(file) {}
        virtual bool parse() = 0;

        ptree& get_properties() {
            return m_props;
        }

        virtual ~Reader() {}
    };
}
