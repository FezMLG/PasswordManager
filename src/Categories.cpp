//
// Created by Konrad on 16.12.2022.
//

#include "Categories.h"

#include <utility>

Categories::Categories() {
    this->names = {};
}

void Categories::setNames(std::map<std::string, int> newNames) {
    this->names = std::move(newNames);
}

std::map<std::string, int> Categories::getNames() {
    return this->names;
}

void Categories::addName(const std::string &name) {
    this->names.insert({name, 1});
}

void Categories::removeName(const std::string &toDelete) {
    //TODO deleting not working
    this->getNames().erase(toDelete);
}

void Categories::printCategories() {
    std::cout << "-------------CATEGORIES---------------" << std::endl;
    for (auto &entry: this->getNames()) {
        std::cout << entry.first << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
}

void newCategoryForm(Categories *categories) {
    std::string name;
    std::cout << "Name for category:" << std::endl;
    std::cin >> name;

    categories->addName(name);
    if (categories->getNames()[name]) {
        std::cout << "Successfully added category: " << name << std::endl;
        return;
    }
    std::cout << "Failed to add category: " << name << std::endl;
    newCategoryForm(categories);
}

void deleteCategoryForm(Categories *categories) {
    std::string name;
    categories->printCategories();
    std::cout << "Category name to delete: " << std::endl;
    std::cin >> name;

    categories->removeName(name);
    if (!categories->getNames()[name]) {
        std::cout << "Successfully deleted category: " << name << std::endl;
        return;
    }
    std::cout << "Failed to delete category: " << name << std::endl;
    deleteCategoryForm(categories);
}
