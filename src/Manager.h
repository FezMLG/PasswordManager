//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_MANAGER_H
#define PASSWORDMANAGER_MANAGER_H

#include <vector>
#include "Entry.h"
#include "Categories.h"
#include <utility>
#include <functional>

using namespace std;

class Manager {
private:
    vector<Entry> entries;
    string password;
    string filePath;
    Categories *categories;

public:
    Manager(Categories *categories1);

    /**
     * @brief Add new password entry to entries
     * @param entry
     */
    void pushToEntries(const Entry &entry);

    vector<Entry> getEntries();

    void setEntries(vector<Entry> &entries);

    /**
     * @brief Showing form to create new Entry
     */
    void createNewEntryForm();

    /**
     * @brief Showing form to remove Entry from vector
     */
    void removeEntryForm();

    /**
     * @brief Form to select and edit entry with execution
     */
    void editEntryForm();

    /**
     * @brief Entries filtering
     * @param option
     * @param filteredEntries
     */
    void searchForEntryForm(int option, vector<Entry> *filteredEntries);

    /**
     * @brief Form to filter entries
     * @param newEntries
     */
    void searchForm(vector<Entry> newEntries);

    /**
     * @brief Returning Entry with given name
     * @param name of the Entry
     * @return Entry class
     */
    Entry getEntryWithName(const string &name);

    /**
     * @brief removing entry from vector
     * @param name
     */
    void removeEntry(const string &name);

    void setPassword(string &newPassword);

    string getPassword();

    void setFilePath(string &newPath);

    string getFilePath();

    void setCategories(Categories *pCategories);

    Categories *getCategories();

    /**
     * @brief Getting all Entries name
     * @return names
     */
    vector<string> getNames();

    /**
     * @brief Printing all Entries names to console
     */
    void printEntriesName();

    /**
     * @brief Form for deleting category with deleting category and all Entries with it
     */
    void deleteCategoryForm();

    /**
     * @brief Form for handling new password
     * @return password
     */
    static string passwordForm();

    /**
     * @brief sorts categories by selected params
     * @param sort function for sorting
     */
    void sortEntries(function<bool(Entry &a, Entry &b)> sort);

    /**
    * @brief sort categories form
    */
    void sortEntriesForm();
};

/**
 * @brief Form for getting new value for Entry or keeping existing and returning as new
 * @param valueName name of Entry attribute
 * @param oldValue old value of Entry attribute
 * @param newValue variable that holds new attribute
 * @return string with new attribute
 */
string getEditNewValueForm(const string &valueName, const string &oldValue, string newValue);

/**
 * @brief Form for creating new category
 * @param categories Categories class
 */
void newCategoryForm(Categories *categories);

#endif //PASSWORDMANAGER_MANAGER_H
