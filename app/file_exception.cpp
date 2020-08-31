//
// Created by mikey on 31/08/2020.
//

#include "file_exception.h"

const char *app::FileException::what() const {
    return message_;
}

app::FileException::FileException(const char *message) :
    message_(message)
{
}
