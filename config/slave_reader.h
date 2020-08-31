//
// Created by mikey on 9/08/2020.
//

#pragma once

#include "config/reader.h"

namespace config {
    class SlaveReader : public Reader {
    public:
        SlaveReader(std::string file) : Reader(file) {}

        bool parse() override;
        ~SlaveReader() override;
    };
}
