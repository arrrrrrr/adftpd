//
// Created by mikey on 4/09/2020.
//

#include "config/config_builder.h"

config::ConfigBuilder::ConfigBuilder() {

}

config::ConfigBuilder::~ConfigBuilder() {

}

void config::ConfigBuilder::set_reader(config::Reader *config_reader) {
    config_reader_ = config_reader;
}

boost::property_tree::ptree config::ConfigBuilder::build() {
    return config_reader_->parse();
}
