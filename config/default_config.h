//
// Created by mikey on 21/08/2020.
//

//
// Created by mikey on 15/08/2020.
//

#ifndef ADFTPD_CONFIG_DEFAULT_CONFIG_H
#define ADFTPD_CONFIG_DEFAULT_CONFIG_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace config {
    using namespace boost::property_tree;

    class default_config {
    private:
        ptree m_master;
        ptree m_slave;

        default_config();
        ~default_config() = default;
        default_config(const default_config&) = delete;
        default_config& operator=(const default_config&) = delete;
        void make_props();

    public:
        static default_config& get_instance();
        const ptree& master();
        const ptree& slave();
    };
}

#endif //ADFTPD_CONFIG_DEFAULT_CONFIG_H
