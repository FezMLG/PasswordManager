//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_MANAGER_H
#define PASSWORDMANAGER_MANAGER_H

#include <vector>
#include "Entry.h"
#include "Categories.h"
#include <utility>

using namespace std;

class Manager {
private:
    vector<Entry> entries;
    string password;
    string filePath;
    Categories *categories;

public:
    Manager(Categories *categories1);

    void pushToEntries(const Entry &entry);

    vector<Entry> getEntries();

    void setEntries(vector<Entry> entries);

    void createNewEntryForm();

    void removeEntryForm();

    void editEntryForm();

    void searchForEntryForm(int option, vector<Entry> *filteredEntries);

    void searchForm(vector<Entry> newEntries);

    Entry getEntryWithName(const string &name);

    void removeEntry(string name);

    void setPassword(string newPassword);

    string getPassword();

    void setFilePath(string newPath);

    string getFilePath();

    void setCategories(Categories *pCategories);

    Categories *getCategories();

    vector<string> getNames();
};

string getEditNewValueForm(const string &valueName, const string &oldValue, string newValue);

#endif //PASSWORDMANAGER_MANAGER_H
