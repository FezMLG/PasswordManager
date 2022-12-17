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

    void addName(const std::string &name);

    void removeName(const std::string &name);

    void printCategories();
};

void newCategoryForm(Categories *categories);

void deleteCategoryForm(Categories *categories);


#endif //PASSWORDMANAGER_CATEGORIES_H
