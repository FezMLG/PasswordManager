
#include "Entry.h"

Entry::Entry(const string &name, const string &login, const string &password,
             const string &category, const string &type, const string &service) {
    this->name = name;
    this->login = login;
    this->password = password;
    this->category = category;
    this->type = type;
    this->service = service;
}

void Entry::print() {
    cout << "----------- " << name << " -----------" << endl;
    cout << login << endl;
    cout << password << endl;
    cout << category << endl;
    cout << type << endl;
    cout << service << endl;
    cout << "------------------------------" << endl;
}

string Entry::getName() {
    return name;
}

string Entry::printForFile() {
    return "\n#START\n"
           + name + '\n' + login + '\n' + password + '\n'
           + category + '\n' + type + '\n' + service
           + "\n#END\n";
}

string Entry::getLogin() {
    return this->login;
}

string Entry::getPassword() {
    return this->password;
}

string Entry::getCategory() {
    return this->category;
}

string Entry::getType() {
    return this->type;
}

string Entry::getService() {
    return this->service;
}
