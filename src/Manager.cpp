//
// Created by Konrad on 15.12.2022.
//

#include <algorithm>
#include <utility>
#include <limits>
#include "Manager.h"
#include "File.h"

Manager::Manager(Categories* categories1) {
    this->entries = {};
    this->categories = categories1;
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

void Manager::removeEntryForm(){
    string name;
    std::cout << "Name of entry" << endl;
    std::cin >> name;

    this->removeEntry(name);
}

void Manager::removeEntry(string name){
    vector<Entry> temp;
    for (auto& entry : this->getEntries()){
        if(entry.getName() != name){
            temp.push_back(entry);
        }
    }
    this->setEntries(temp);
}

void Manager::createNewEntryForm() {
    string name, login, password, category, type, service;

    do{
        std::cout << "Name:" << std::endl;
        std::cin >> name;
    }while(std::any_of(this->getNames().begin(), this->getNames().end(), [&name](const string& i){return i==name;}));

    std::cout << "Login:" << std::endl;
    std::cin >> login;

    std::cout << "Password:" << std::endl;
    std::cin >> password;

    categories->printCategories();
    do{
        std::cout << "Category:" << std::endl;
        std::cin >> category;
    }while(!categories->getNames()[category]);


    std::cout << "Type:" << std::endl;
    std::cin >> type;

    std::cout << "Service:" << std::endl;
    std::cin >> service;

    auto* entry = new Entry(name, login, password, category, type, service);
    entry->print();
    appendToFile(entry, this);
    this->pushToEntries(*entry);
}

void Manager::setFilePath(string newPath) {
    this->filePath = std::move(newPath);
}

string Manager::getFilePath() {
    return this->filePath;
}

void Manager::setCategories(Categories *pCategories) {
    this->categories = pCategories;
}

Categories* Manager::getCategories() {
    return this->categories;
}

void Manager::editEntryForm() {
    cout << "Entries: " << endl;
    for(auto& entry: this->getEntries()){
        cout << entry.getName() << endl;
    }
    cout << "Type entry name to edit:" << endl;

    string nameToEdit;
    cin >> nameToEdit;

    Entry oldEntry = getEntryWithName(nameToEdit);
    this->removeEntry(nameToEdit);

    cout << "Press enter if you want to keep old value" << endl;

    string newName, newLogin, newPassword, newCategory, newType, newService;
    do{
        newName = getEditNewValueForm("Name", oldEntry.getName(), newName);
    }while(std::any_of(this->getNames().begin(), this->getNames().end(), [&newName](const string& i){return i == newName;}));

    newLogin = getEditNewValueForm("Login", oldEntry.getLogin(), newLogin);
    newPassword = getEditNewValueForm("Password", oldEntry.getPassword(), newPassword);

    categories->printCategories();
    do{
        newCategory = getEditNewValueForm("Category", oldEntry.getCategory(), newCategory);
    }while(!categories->getNames()[newCategory]);

    newType = getEditNewValueForm("Type", oldEntry.getType(), newType);
    newService= getEditNewValueForm("Service", oldEntry.getService(), newService);

    auto* entry = new Entry(newName, newLogin, newPassword, newCategory, newType, newService);
    entry->print();
    this->pushToEntries(*entry);
    overrideFile(this);
}

Entry Manager::getEntryWithName(const string &name) {
    for (auto &entry: this->getEntries()) {
        if (entry.getName() == name) {
            return entry;
        }
    }
    throw runtime_error("Error when getting entry");
};

string getEditNewValueForm(const string &valueName, const string &oldValue, string newValue) {
    std::cout << valueName << " [" << oldValue << "]: " << std::endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newValue);
    if (newValue.empty()) newValue = oldValue;
    return newValue;
};
