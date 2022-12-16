//
// Created by Konrad on 15.12.2022.
//

#include <algorithm>
#include <utility>
#include "Manager.h"
#include "File.h"

Manager::Manager() {
    this->entries = {};
}

void Manager::pushToEntries(const Entry &entry) {
    entries.push_back(entry);
}

void Manager::setPassword(string newPassword) {
    this->password = std::move(newPassword);
}

string Manager::getPassword() {
    return this->password;
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

void Manager::removeEntry(){
    string name;
    std::cout << "Name of entry" << endl;
    std::cin >> name;

    vector<Entry> temp;
    for (auto& entry : this->getEntries()){
        if(entry.getName() != name){
            temp.push_back(entry);
        }
    }
    this->setEntries(temp);
}

void Manager::createNewEntry() {
    string name, login, password, category, type, service;

    do{
        std::cout << "Name:" << std::endl;
        std::cin >> name;
    }while(std::any_of(this->getNames().begin(), this->getNames().end(), [&name](const string& i){return i==name;}));

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
    appendToFile(entry);
    this->pushToEntries(*entry);
}

void Manager::setFilePath(string newPath) {
    this->filePath = std::move(newPath);
}

string Manager::getFilePath() {
    return this->filePath;
}
