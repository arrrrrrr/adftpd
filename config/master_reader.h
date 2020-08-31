//
// Created by mikey on 9/08/2020.
//

#pragma once

#include "config/reader.h"

namespace config {
    class MasterReader : public Reader {
    public:
        MasterReader(std::string file) : Reader(file) {}
        bool parse() override;

        ~MasterReader() override;
    };
}
