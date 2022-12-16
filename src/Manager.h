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
    Categories* categories;

public:
    Manager(Categories* categories1);

    void pushToEntries(const Entry& entry);
    vector<Entry> getEntries();
    void setEntries(vector<Entry> entries);
    void createNewEntry();
    void removeEntry();

    void setPassword(string newPassword);
    string getPassword();

    void setFilePath(string newPath);
    string getFilePath();

    void setCategories(Categories* pCategories);
    Categories* getCategories();

    vector<string> getNames();
};


#endif //PASSWORDMANAGER_MANAGER_H
