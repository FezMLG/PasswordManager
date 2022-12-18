//
// Created by Konrad on 15.12.2022.
//

#include "App.h"
#include "File.h"

bool decryptMode = false;

void start() {
    Categories categories = *new Categories();
    Manager manager = *new Manager(&categories);
    getFileAndPassword(&manager);
    if (decryptMode) {
        int mode;
        cout << "1. encrypt file" << endl;
        cout << "2. decrypt file" << endl;
        cin >> mode;
        switch (mode) {
            case 1:
                encryptFile("../data/decrypt.txt", manager.getFilePath(), manager.getPassword());
                break;
            case 2:
                decryptFile(manager.getFilePath(), "../data/decrypt.txt", manager.getPassword());
                break;
            default:
                cout << "Wrong value" << endl;
                break;
        }
        exit(0);
    }
    readFromFile(&manager);
    mainMenu(&manager);
};

void getFileAndPassword(Manager *manager) {
    string temp;

    temp = listAndSelectFile();
    manager->setFilePath(temp);

    std::cout << "Type password: " << endl;
    std::cin >> temp;
    manager->setPassword(temp);
}

void mainMenu(Manager *manager) {
    std::cout << "Choose option: " << std::endl;
    std::cout << "1. Search entries" << std::endl;
    std::cout << "2. Sort entries" << std::endl;
    std::cout << "3. Add to file" << std::endl;
    std::cout << "4. Edit entry" << std::endl;
    std::cout << "5. Remove from file" << std::endl;
    std::cout << "6. Add new category" << std::endl;
    std::cout << "7. Delete category" << std::endl;
    std::cout << "8. List categories" << std::endl;
    std::cout << "-1. Exit" << std::endl;
    handleOption(manager);
}

void handleOption(Manager *manager) {
    int selectedOption;
    std::cin >> selectedOption;

    switch (selectedOption) {
        case 1:
            //TODO search
            manager->searchForm(manager->getEntries());
            break;
        case 2:
            //TODO sorting
            for (auto &entry: manager->getEntries()) {
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

