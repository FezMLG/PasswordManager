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
public:
    Manager();

    void pushToEntries(const Entry& entry);
    vector<Entry> getEntries();
    void setEntries(vector<Entry> entries);
    void createNewEntry();
};


#endif //PASSWORDMANAGER_MANAGER_H
