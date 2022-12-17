//
// Created by Konrad on 15.12.2022.
//

#include "App.h"
#include "File.h"

void start(){
    Categories categories = *new Categories();
    Manager manager = *new Manager(&categories);
    readFromFile(&manager);
//    getFileAndPassword(&manager);
    mainMenu(&manager);
};

void getFileAndPassword(Manager* manager){
    string temp;
    std::cout << "Type password: " << endl;
    std::cin >> temp;
    manager->setPassword(temp);

    std::cout << "Path to file: " << endl;
    std::cin >> temp;
    manager->setFilePath(temp);
}

void mainMenu(Manager* manager){
    std::cout << "Choose option: " << std::endl;
    std::cout << "2. Print entries" << std::endl;
    std::cout << "3. Add to file" << std::endl;
    std::cout << "4. Edit entry" << std::endl;
    std::cout << "5. Remove from file" << std::endl;
    std::cout << "6. Add new category" << std::endl;
    std::cout << "7. Delete category" << std::endl;
    std::cout << "8. List categories" << std::endl;
    std::cout << "-1. Exit" << std::endl;
    handleOption(manager);
}

void handleOption(Manager* manager){
    int selectedOption;
    std::cin >> selectedOption;

    switch (selectedOption) {
        case 1:
            //TODO search

            break;
        case 2:
            //TODO sorting
            for(auto& entry: manager->getEntries()){
                entry.print();
            }
            break;
        case 3:
            manager->createNewEntryForm();
            break;
        case 4:
            manager->editEntryForm();
            break;
        case 5:
            manager->removeEntryForm();
            overrideFile(manager);
            break;
        case 6:
            newCategoryForm(manager->getCategories());
            break;
        case 7:
            deleteCategoryForm(manager->getCategories());
            break;
        case 8:
            manager->getCategories()->printCategories();
            break;
        case -1:
            exit(0);
        default:
            std::cout << "Invalid option" << std::endl;
            break;
    }
    mainMenu(manager);
}

