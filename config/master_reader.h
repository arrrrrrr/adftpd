//
// Created by mikey on 9/08/2020.
//

#pragma once

#include "config/reader.h"

namespace config {
    class MasterReader : public Reader {
    private:

    public:
        MasterReader() : Reader() {}
        ptree& Parse(std::string file) override;
    };
}
