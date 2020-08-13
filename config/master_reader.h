//
// Created by mikey on 9/08/2020.
//

#ifndef ADFTPD_MASTER_READER_H
#define ADFTPD_MASTER_READER_H

#include "reader.h"

namespace config {
    class master_reader : public reader {
    public:
        master_reader(std::string file) : reader(file) {}
        bool parse() override;

        ~master_reader() override;
    };
}


#endif //ADFTPD_MASTER_READER_H
