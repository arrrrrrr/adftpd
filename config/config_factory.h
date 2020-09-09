//
// Created by mikey on 29/08/2020.
//

#pragma once
#include "config/common.h"

namespace config {
    class ConfigFactory {
    private:
        config::Mode mode_;
    public:
        ConfigFactory(config::Mode mode);
        Reader *MakeReader();
    };
}


