//
// Created by mikey on 9/08/2020.
//

#ifndef ADFTPD_READER_H
#define ADFTPD_READER_H

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace config {
    using namespace boost::property_tree;

    class reader {
    protected:
        std::string m_file;
        ptree m_props;

    public:
        reader(std::string file) : m_file(file) {}
        virtual bool parse() = 0;
        ptree& get_properties() {
            return m_props;
        }
        virtual ~reader() {}
    };
}

#endif //ADFTPD_READER_H
