//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_MANAGER_H
#define PASSWORDMANAGER_MANAGER_H

#include <vector>
#include "Entry.h"
#include <utility>

using namespace std;

class Manager {
private:
    vector<Entry> entries;
    string password;
    string filePath;
public:
    Manager();

    void pushToEntries(const Entry& entry);
    vector<Entry> getEntries();
    void setEntries(vector<Entry> entries);
    void createNewEntry();
    void removeEntry();

    void setPassword(string newPassword);
    string getPassword();

    void setFilePath(string newPath);
    string getFilePath();


    vector<string> getNames();
};


#endif //PASSWORDMANAGER_MANAGER_H
