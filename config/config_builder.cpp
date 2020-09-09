//
// Created by mikey on 4/09/2020.
//

#include "config/config_builder.h"

namespace config {
    ConfigBuilder::ConfigBuilder() :
        config_file_(""), config_reader_(nullptr)
    {
    }

    ConfigBuilder::~ConfigBuilder() {

    }

    ConfigBuilder& ConfigBuilder::set_reader(Reader *config_reader) {
        config_reader_ = config_reader;
        return *this;
    }

    ConfigBuilder& ConfigBuilder::set_config(std::string& file) {
        config_file_ = file;
        return *this;
    }

    boost::property_tree::ptree ConfigBuilder::build() {
        return config_reader_->Parse(config_file_);
    }
}