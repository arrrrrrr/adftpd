//
// Created by mikey on 9/08/2020.
//

#include "master_reader.h"
namespace config {
    bool master_reader::parse() {
        const ptree& defs = default_config::get_instance().master();

        return true;
    }

    master_reader::~master_reader() {

    }
}