//
// Created by mikey on 9/08/2020.
//

#pragma once

#include "config/reader.h"

namespace config {
    class MasterReader : public Reader {
    private:

    public:
        MasterReader(const char *config) : Reader(config) {}
        ptree& parse() override;
    };
}
