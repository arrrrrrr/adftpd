//
// Created by mikey on 9/08/2020.
//

#ifndef ADFTPD_SLAVE_READER_H
#define ADFTPD_SLAVE_READER_H
#include "reader.h"

namespace config {
    class slave_reader : public reader {
    public:
        slave_reader(std::string file) : reader(file) {}

        bool parse() override;
        ~slave_reader() override;
    };
}


#endif //ADFTPD_SLAVE_READER_H
