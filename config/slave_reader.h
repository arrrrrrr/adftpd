//
// Created by mikey on 9/08/2020.
//

#pragma once

#include "config/reader.h"

namespace config {
    class SlaveReader : public Reader {
    private:

    public:
        SlaveReader(const char *config) : Reader(config) {}
        ptree& parse() override;
    };
}
