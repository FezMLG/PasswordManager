//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_ENTRY_H
#define PASSWORDMANAGER_ENTRY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Entry {
private:
    std::string name;
    std::string login;
    std::string password;
    std::string category;
    std::string type;
    std::string service;

public:
    Entry(const std::string &name, const std::string &login, const std::string &password, const std::string &category,
          const std::string &type, const std::string &service);

    void print();

    string printForFile();

    string getName();

    string getLogin();

    string getPassword();

    string getCategory();

    string getType();

    string getService();

    static string generatePassword(int &length);

    static int checkPasswordStrength(const std::string &passwordToCheck);
};

#endif //PASSWORDMANAGER_ENTRY_H
