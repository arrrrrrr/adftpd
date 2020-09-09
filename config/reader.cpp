//
// Created by mikey on 4/09/2020.
//

#include "reader.h"

namespace config {
    using namespace boost::property_tree;

    Reader::Reader() {
    }

    Reader::~Reader() {
    }

    void config::Reader::ReadJsonFile(std::string file, ptree& out_props) {
        std::ifstream file_stream;
        file_stream.open(file, std::ios::binary);

        if (!file_stream.is_open())
            throw ConfigException("Config file does not exist");

        // get the length of the file
        file_stream.seekg(0, file_stream.end);
        int length = file_stream.tellg();
        file_stream.seekg(0, file_stream.beg);

        // read the file contents into a buffer
        char *buf = new char[length+1];
        file_stream.read(buf, length);
        file_stream.close();
        buf[length] = '\0';

        ReadJsonFromCharBuffer(buf, length, out_props);
        delete[] buf;
    }

    void Reader::ReadJsonFromCharBuffer(const char *buffer, int length, ptree& out_props) {
        // convert the character buffer to an istream
        namespace bios = boost::iostreams;
        bios::stream<bios::array_source> buf_stream(buffer, length);

        json_parser::read_json(buf_stream, out_props);
    }
}
