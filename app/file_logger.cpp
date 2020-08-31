//
// Created by mikey on 31/08/2020.
//

#include "file_logger.h"

app::FileLogger::FileLogger(std::string filename) {
    OpenFileStream(filename);
}

void app::FileLogger::log(std::string line) {
    file_stream_ << line << std::endl;
}

app::FileLogger::~FileLogger() {
    file_stream_.close();
}

void app::FileLogger::OpenFileStream(std::string& filename) {
    file_stream_.open(filename, std::ios::out | std::ios::app);
    if (file_stream_.fail()) {
        std::string msg = "Failed to open log file: " + filename;
        throw FileException(msg.c_str());
    }
}
