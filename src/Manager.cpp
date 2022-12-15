//
// Created by Konrad on 15.12.2022.
//

#include <algorithm>
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

vector<string> Manager::getNames() {
    vector<string> names;
    for(Entry entry : entries){
        names.push_back(entry.getName());
    }
    return names;
}

void Manager::setEntries(vector<Entry> newEntries) {
    this->entries = std::move(newEntries);
}

void Manager::createNewEntry(Manager* manager) {
    string name, login, password, category, type, service;

    do{
        std::cout << "Name:" << std::endl;
        std::cin >> name;
    }while(std::any_of(manager->getNames().begin(), manager->getNames().end(), [&name](const string& i){return i==name;}));

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
