
#include <random>
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

string Entry::generatePassword(int &length, bool useSmallAndBig, bool useSpecialChars) {
    std::string password;
    std::string characters = R"(abcdefghijklmnopqrstuvwxyz0123456789)";
    std::string big_characters = R"(ABCDEFGHIJKLMNOPQRSTUVWXYZ)";
    std::string special_characters = R"(!@#$%^&*()-_=+[{]}\|;:'",.<>/?)";

    if (useSmallAndBig) characters.append(big_characters);
    if (useSpecialChars) characters.append(special_characters);

    // Random number generator
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, characters.size() - 1);

    for (int i = 0; i < length; i++) {
        password += characters[dist(rng)];
    }

    return password;
}

int Entry::checkPasswordStrength(const std::string &passwordToCheck) {
    int strength = 0;

    // Check the length of the password
    if (passwordToCheck.length() >= 8)
        strength++;
    if (passwordToCheck.length() >= 12)
        strength++;

    // Check for uppercase and lowercase letters
    bool hasUppercase = false;
    bool hasLowercase = false;
    for (char c: passwordToCheck) {
        if (isupper(c))
            hasUppercase = true;
        if (islower(c))
            hasLowercase = true;
    }
    if (hasUppercase && hasLowercase)
        strength++;

    // Check for numbers
    bool hasNumber = false;
    for (char c: passwordToCheck) {
        if (isdigit(c)) {
            hasNumber = true;
            break;
        }
    }
    if (hasNumber)
        strength++;

    // Check for special characters
    bool hasSpecialChar = false;
    for (char c: passwordToCheck) {
        if (!isalnum(c)) {
            hasSpecialChar = true;
            break;
        }
    }
    if (hasSpecialChar)
        strength++;

    return strength;
}
