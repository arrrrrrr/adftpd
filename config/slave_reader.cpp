//
// Created by mikey on 9/08/2020.
//

#include "slave_reader.h"
namespace config {
    bool slave_reader::parse() {
        const ptree& defs = default_config::get_instance().slave();
    }

    slave_reader::~slave_reader() {

    }
}
