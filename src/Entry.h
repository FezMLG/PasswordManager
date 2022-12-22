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

    /**
     * @brief Print entry to console
     */
    void print();

    /**
     * @brief Generate entry with formatting for saving in file
     * @return formatted string for file
     */
    string printForFile();

    string getName();

    string getLogin();

    string getPassword();

    string getCategory();

    string getType();

    string getService();

    /**
     * @brief generating random password
     * @param length length of the generated password
     * @return generated password
     */
    static string generatePassword(int &length);

    /**
     * @brief checking if password contains lowercase, uppercase, number, special char, length more than 8 and more than 16, and returning password strength on scale 0-6
     * @param passwordToCheck
     * @return password strength between 0-6, where 0 is weak and 6 is strong
     */
    static int checkPasswordStrength(const std::string &passwordToCheck);
};

#endif //PASSWORDMANAGER_ENTRY_H
