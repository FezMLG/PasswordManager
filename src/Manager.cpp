//
// Created by Konrad on 15.12.2022.
//

#include <algorithm>
#include <utility>
#include "Manager.h"
#include "File.h"
#include "App.h"
#include "Utils.h"

Manager::Manager(Categories *categories1) {
    this->entries = {};
    this->categories = categories1;
}

void Manager::pushToEntries(const Entry &entry) {
    entries.push_back(entry);
}

void Manager::setPassword(string &newPassword) {
    this->password = newPassword;
}

string Manager::getPassword() {
    return this->password;
}

vector<Entry> Manager::getEntries() {
    return entries;
}

vector<string> Manager::getNames() {
    vector<string> names;
    for (Entry entry: entries) {
        names.push_back(entry.getName());
    }
    return names;
}

void Manager::setEntries(vector<Entry> &newEntries) {
    this->entries = newEntries;
}

void Manager::removeEntryForm() {
    string name;
    std::cout << "Name of entry" << endl;
    name = Utils::userInput();

    this->removeEntry(name);
}

void Manager::removeEntry(const string &name) {
    vector<Entry> temp;
    for (auto &entry: this->getEntries()) {
        if (entry.getName() != name) {
            temp.push_back(entry);
        }
    }
    this->setEntries(temp);
}

void Manager::createNewEntryForm() {
    string name, login, password, category, type, service;

    do {
        std::cout << "Name:" << std::endl;
        name = Utils::userInput();
    } while (std::any_of(this->getNames().begin(), this->getNames().end(),
                         [&name](const string &i) { return i == name; }));

    std::cout << "Login:" << std::endl;
    login = Utils::userInput();

    password = passwordForm();

    categories->printCategories();
    do {
        if (this->getCategories()->getNames().empty()) {
            newCategoryForm(this->getCategories());
        }
        string option;
        std::cout << "Category:" << std::endl;
        category = Utils::userInput();
        if (!categories->getNames()[category]) {
            std::cout << "This category does not exist, do you want to add new? y - yes, n - no" << std::endl;
            std::cin >> option;
            if (option == "y") {
                newCategoryForm(this->getCategories());
            }
        }
    } while (!categories->getNames()[category]);

    std::cout << "Type:" << std::endl;
    type = Utils::userInput();

    std::cout << "Service:" << std::endl;
    service = Utils::userInput();

    auto *entry = new Entry(name, login, password, category, type, service);
    entry->print();
    appendToFile(entry, this);
    this->pushToEntries(*entry);
}

void Manager::setFilePath(string &newPath) {
    this->filePath = newPath;
}

string Manager::getFilePath() {
    return this->filePath;
}

void Manager::setCategories(Categories *pCategories) {
    this->categories = pCategories;
}

Categories *Manager::getCategories() {
    return this->categories;
}

void Manager::editEntryForm() {
    cout << "Entries: " << endl;
    this->printEntriesName();
    cout << "Type entry name to edit:" << endl;

    string nameToEdit;
    nameToEdit = Utils::userInput();

    Entry oldEntry = getEntryWithName(nameToEdit);
    this->removeEntry(nameToEdit);

    cout << "Press enter if you want to keep old value" << endl;

    string newName, newLogin, newPassword, newCategory, newType, newService;
    do {
        newName = getEditNewValueForm("Name", oldEntry.getName(), newName);
    } while (std::any_of(this->getNames().begin(), this->getNames().end(),
                         [&newName](const string &i) { return i == newName; }));

    newLogin = getEditNewValueForm("Login", oldEntry.getLogin(), newLogin);

    newPassword = getEditNewValueForm("Password", oldEntry.getPassword(), newPassword);

    categories->printCategories();
    do {
        if (this->getCategories()->getNames().empty()) {
            newCategoryForm(this->getCategories());
        }
        string option;
        newCategory = getEditNewValueForm("Category", oldEntry.getCategory(), newCategory);
        if (!categories->getNames()[newCategory]) {
            std::cout << "This category does not exist, do you want to add new? y - yes, n - no" << std::endl;
            std::cin >> option;
            if (option == "y") {
                newCategoryForm(this->getCategories());
            }
        }
    } while (!categories->getNames()[newCategory]);

    newType = getEditNewValueForm("Type", oldEntry.getType(), newType);
    newService = getEditNewValueForm("Service", oldEntry.getService(), newService);

    auto *entry = new Entry(newName, newLogin, newPassword, newCategory, newType, newService);
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
}

void Manager::searchForm(vector<Entry> newEntries) {
    vector<Entry> filteredEntries = std::move(newEntries);
    int searchType;

    cout << "1. Add name search param" << endl;
    cout << "2. Add login search param" << endl;
    cout << "3. Add category search param" << endl;
    cout << "4. Add type search param" << endl;
    cout << "5. Add service search param" << endl;
    cout << "0. Search results" << endl;
    cout << "-1. Go to main menu" << endl;
    cin >> searchType;
    this->searchForEntryForm(searchType, &filteredEntries);
}

void Manager::searchForEntryForm(int option, vector<Entry> *filteredEntries) {
    string searchParam;
    vector<Entry> tempEntries{};

    switch (option) {
        case 1:
            cout << "Type name to search:" << endl;
            searchParam = Utils::userInput();
            for (auto &entry: *filteredEntries) {
                if (entry.getName().find(searchParam) != std::string::npos) {
                    tempEntries.push_back(entry);
                }
            }
            filteredEntries->swap(tempEntries);
            break;
        case 2:
            cout << "Type login to search:" << endl;
            searchParam = Utils::userInput();
            for (auto &entry: *filteredEntries) {
                if (entry.getLogin().find(searchParam) != std::string::npos) {
                    tempEntries.push_back(entry);
                }
            }
            filteredEntries->swap(tempEntries);
            break;
        case 3:
            categories->printCategories();
            cout << "Type category to search:" << endl;
            searchParam = Utils::userInput();
            for (auto &entry: *filteredEntries) {
                if (entry.getCategory().find(searchParam) != std::string::npos) {
                    tempEntries.push_back(entry);
                }
            }
            filteredEntries->swap(tempEntries);
            break;
        case 4:
            cout << "Type type to search:" << endl;
            searchParam = Utils::userInput();
            for (auto &entry: *filteredEntries) {
                if (entry.getType().find(searchParam) != std::string::npos) {
                    tempEntries.push_back(entry);
                }
            }
            filteredEntries->swap(tempEntries);
            break;
        case 5:
            cout << "Type service to search:" << endl;
            searchParam = Utils::userInput();
            for (auto &entry: *filteredEntries) {
                if (entry.getService().find(searchParam) != std::string::npos) {
                    tempEntries.push_back(entry);
                }
            }
            filteredEntries->swap(tempEntries);
            break;
        case 0:
            for (auto &entry: *filteredEntries) {
                entry.print();
            }
            break;
        case -1:
            mainMenu(this);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
    this->searchForm(*filteredEntries);
}

void Manager::printEntriesName() {
    for (auto &entry: this->getEntries()) {
        cout << entry.getName() << endl;
    }
}

string Manager::getEditNewValueForm(const string &valueName, const string &oldValue, string newValue) {
    string option;
    std::cout << valueName << " [" << oldValue << "]: y - to type new value, n - keep old value" << std::endl;
    std::cin >> option;
    if (option == "n") return oldValue;
    if (valueName == "Password") {
        std::cout << valueName << " [" << oldValue << "]: y - to type new value, n - keep old value" << std::endl;
        std::cin >> option;
        if (option != "n") {
            newValue = this->passwordForm();
        }
    }
    std::cout << "Type new value:" << std::endl;
    newValue = Utils::userInput();
    return newValue;
}

void Manager::deleteCategoryForm() {
    std::string categoryNameToRemove;
    this->getCategories()->printCategories();
    std::cout << "Category name to delete: " << std::endl;
    categoryNameToRemove = Utils::userInput();

    this->getCategories()->removeName(categoryNameToRemove);
    if (!this->getCategories()->getNames()[categoryNameToRemove]) {
        std::cout << "Successfully deleted category: " << categoryNameToRemove << std::endl;
        vector<Entry> entriesToStay{};
        for (auto &entry: this->getEntries()) {
            if (entry.getCategory() != categoryNameToRemove) {
                entriesToStay.push_back(entry);
            }
        }
        this->setEntries(entriesToStay);
        overrideFile(this);
        return;
    }
    std::cout << "Failed to delete category: " << categoryNameToRemove << std::endl;
    deleteCategoryForm();
}

string Manager::passwordForm() {
    int option;
    std::cout << "Password" << std::endl;
    std::cout << "1. Generate password" << std::endl;
    std::cout << "2. My password" << std::endl;
    std::cin >> option;

    int passwordLength = 16;
    int passwordStrength;
    bool useSmallAndBig = true;
    bool useSpecialChars = true;
    std::string newPassword;
    string temp;
    switch (option) {
        case 1:
            cout << "Number of characters" << endl;
            cin >> passwordLength;
            cout << "Use small and big characters? y - yes, n - no" << endl;
            cin >> temp;
            if (temp == "n") {
                useSmallAndBig = false;
            }
            cout << "Use special characters? y - yes, n - no" << endl;
            cin >> temp;
            if (temp == "n") {
                useSpecialChars = false;
            }
            newPassword = Entry::generatePassword(passwordLength, useSmallAndBig, useSpecialChars);
            cout << "Your password: " << newPassword << endl;
            break;
        case 2:
            do {
                std::cout << "Your password:" << std::endl;
                std::cin >> newPassword;
                passwordStrength = Entry::checkPasswordStrength(newPassword);
                for (auto &entry: this->getEntries()) {
                    if (entry.getPassword() == newPassword) {
                        cout << "You used that password before, are you sure you want to use it? y - yes, n - no"
                             << endl;
                        cin >> temp;
                        if (temp == "n") passwordStrength = 0;
                        break;
                    }
                }
                std::cout << "Your password strength: " << passwordStrength << std::endl;
                if (passwordStrength < 4) {
                    cout
                            << "Your password is too weak, make sure you have at least 8 characters, lower and upper case, number"
                            << endl;
                }
            } while (passwordStrength < 4);
            break;
        default:
            newPassword = Entry::generatePassword(passwordLength, true, true);
            cout << "Your password: " << newPassword << endl;
            break;
    }
    return newPassword;
}

std::vector<Entry> Manager::sortEntries(std::vector<Entry> entries, function<bool(Entry &a, Entry &b)> sort) {
    std::sort(entries.begin(), entries.end(), std::move(sort));
    return entries;
}

void Manager::sortEntriesForm(std::vector<Entry> entries) {
    int selected_option = 1;
    std::vector<Entry> entriesToSort = entries;

    while (true) {
        std::cout << "-----------SORTING-----------" << endl;
        std::cout << "Sort categories by:" << endl;
        std::cout << "1. Name" << endl;
        std::cout << "2. Login" << endl;
        std::cout << "3. Category" << endl;
        std::cout << "4. Type" << endl;
        std::cout << "5. Service" << endl;
        std::cout << "6. Print and save entries" << endl;
        std::cout << "-1. Go back to main manu" << endl;
        std::cin >> selected_option;

        switch (selected_option) {
            case 1:
                entriesToSort = this->sortEntries(entries, [](Entry &a, Entry &b) {
                    return a.getName() < b.getName();
                });
                break;
            case 2:
                entriesToSort = this->sortEntries(entries, [](Entry &a, Entry &b) {
                    return a.getLogin() < b.getLogin();
                });
                break;
            case 3:
                entriesToSort = this->sortEntries(entries, [](Entry &a, Entry &b) {
                    return a.getCategory() < b.getCategory();
                });
                break;
            case 4:
                entriesToSort = this->sortEntries(entries, [](Entry &a, Entry &b) {
                    return a.getType() < b.getType();
                });
                break;
            case 5:
                entriesToSort = this->sortEntries(entries, [](Entry &a, Entry &b) {
                    return a.getService() < b.getService();
                });
                break;
            case 6:
                this->setEntries(entriesToSort);
                for (auto &entry: entriesToSort) {
                    entry.print();
                }
                overrideFile(this);
                //intentionally no break here
            case -1:
                mainMenu(this);
                break;
            default:
                std::cout << "Wrong option" << std::endl;
                break;
        }
    }
}

void newCategoryForm(Categories *categories) {
    std::string name;
    std::cout << "Name for category:" << std::endl;
    name = Utils::userInput();

    categories->addName(name);
    if (categories->getNames()[name]) {
        std::cout << "Successfully added category: " << name << std::endl;
        return;
    }
    std::cout << "Failed to add category: " << name << std::endl;
    newCategoryForm(categories);
}

