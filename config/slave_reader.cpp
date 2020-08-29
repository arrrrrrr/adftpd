//
// Created by mikey on 9/08/2020.
//

#include "slave_reader.h"

namespace config {
    bool SlaveReader::parse() {
        const ptree& defs = DefaultConfig::get_instance().slave();

        return true;
    }

    SlaveReader::~SlaveReader() {

    }
}
