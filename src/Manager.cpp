//
// Created by Konrad on 15.12.2022.
//

#include "Manager.h"
#include "File.h"

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

void Manager::createNewEntry() {
    string name, login, password, category, type, service;
    std::cout << "Name:" << std::endl;
    std::cin >> name;

    std::cout << "Login:" << std::endl;
    std::cin >> login;

    std::cout << "Password:" << std::endl;
    std::cin >> password;

    std::cout << "Category:" << std::endl;
    std::cin >> category;

    std::cout << "Type:" << std::endl;
    std::cin >> type;

    std::cout << "Service:" << std::endl;
    std::cin >> service;

    auto* entry = new Entry(name, login, password, category, type, service);
    entry->print();
    saveToFile(entry);
    this->pushToEntries(*entry);
}
