//
// Created by Konrad on 15.12.2022.
//

#include "Manager.h"

Manager::Manager() {
    this->entries = {};
}

void Manager::pushToEntries(const Entry &entry) {
    entries.push_back(entry);
}

vector<Entry> Manager::getEntries() {
    return entries;
}

void Manager::setEntries(vector<Entry> newEntries) {
    this->entries = std::move(newEntries);
}
