//
// Created by mikey on 31/08/2020.
//

#pragma once
#include "app/logger.h"
#include "app/file_exception.h"

#include <string>
#include <iostream>
#include <fstream>

namespace app {
    class FileLogger : public Logger {
    private:
        std::ofstream file_stream_;
        void OpenFileStream(std::string& filename);

    public:
        FileLogger(std::string filename);
        virtual void log(std::string line);
        virtual ~FileLogger();
    };
}



