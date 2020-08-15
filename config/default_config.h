//
// Created by mikey on 15/08/2020.
//

#ifndef ADFTPD_CONFIG_DEFAULT_CONFIG_H
#define ADFTPD_CONFIG_DEFAULT_CONFIG_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "defs.h"

namespace config {
    using namespace boost::property_tree;

    class default_config {
    private:
        ptree m_master;
        ptree m_slave;

        default_config() {
            make_props();
        }

        ~default_config() = default;
        default_config(const default_config&) = delete;
        default_config& operator=(const default_config&) = delete;

        void make_props() {
            json_parser::read_json(::config::defaults::master, m_master);
            json_parser::read_json(::config::defaults::slave, m_slave);
        }

    public:
        static default_config& get_instance() {
            static default_config(instance);
            return instance;
        }

        const ptree& master() {
            return m_master;
        }

        const ptree& slave() {
            return m_slave;
        }
    };
}

#endif //ADFTPD_CONFIG_DEFAULT_CONFIG_H
