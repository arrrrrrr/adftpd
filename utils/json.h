//
// Created by mikey on 9/09/2020.
//

#pragma once
#include <vector>
#include <string>
#include <boost/property_tree/ptree.hpp>

namespace utils {
    namespace bp = boost::property_tree;

    template <typename T>
    std::vector<T> ptree_array_as_vector(const bp::ptree& props, const bp::ptree::key_type& key) {
        std::vector<T> res;

        for (auto& item : props.get_child(key)) {
            res.push_back(item.second.get_value<T>());
        }

        return res;
    }

    std::vector<std::string> ptree_array_as_vector_s(const bp::ptree& props, const bp::ptree::key_type& key) {
        std::vector<std::string> res;

        for (auto& item : props.get_child(key)) {
            res.push_back(item.second.get_value<std::string>());
        }

        return res;
    }
}