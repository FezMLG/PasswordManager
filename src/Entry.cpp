
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
    cout << name << endl;
    cout << login << endl;
    cout << password << endl;
    cout << category << endl;
    cout << type << endl;
    cout << service << endl;
}
