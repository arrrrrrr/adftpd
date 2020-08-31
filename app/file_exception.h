//
// Created by mikey on 31/08/2020.
//

#pragma once
#include <exception>

namespace app {
    class FileException : public std::exception {
    private:
        const char *message_;

    public:
        FileException(const char *message);
        const char *what() const override;
    };
}



