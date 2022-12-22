//
// Created by Konrad on 16.12.2022.
//

#include "Categories.h"

#include <utility>

Categories::Categories() {
    this->names = {};
}

void Categories::setNames(std::map<std::string, int> newNames) {
    this->names = std::move(newNames);
}

std::map<std::string, int> Categories::getNames() {
    return this->names;
}

void Categories::addName(const std::string &name) {
    this->names.insert({name, 1});
}

void Categories::removeName(const std::string &toDelete) {
    std::map<std::string, int> namesToStay;
    for (auto &name: this->getNames()) {
        if (name.first != toDelete) {
            namesToStay.insert({name.first, name.second});
        }
    }
    this->setNames(namesToStay);
}

void Categories::printCategories() {
    std::cout << "-------------CATEGORIES---------------" << std::endl;
    for (auto &entry: this->getNames()) {
        std::cout << entry.first << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
}
