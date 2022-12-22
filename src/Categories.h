//
// Created by Konrad on 16.12.2022.
//

#ifndef PASSWORDMANAGER_CATEGORIES_H
#define PASSWORDMANAGER_CATEGORIES_H


#include <string>
#include <map>
#include <iostream>

class Categories {
private:
    std::map<std::string, int> names;

public:
    Categories();

    void setNames(std::map<std::string, int> newNames);

    std::map<std::string, int> getNames();

    /**
     * @brief adding new category to list
     * @param name category name to add
     */
    void addName(const std::string &name);

    /**
     * @brief removes category from
     * @param name category name to remove
     */
    void removeName(const std::string &name);

    /**
     * @brief printing all categories in console
     */
    void printCategories();
};


#endif //PASSWORDMANAGER_CATEGORIES_H
