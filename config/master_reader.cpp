//
// Created by mikey on 9/08/2020.
//

#include "master_reader.h"
namespace config {
    bool MasterReader::parse() {
        const ptree& defs = DefaultConfig::get_instance().get_master_config();

        return true;
    }

    MasterReader::~MasterReader() {

    }
}