//
// Created by Konrad on 15.12.2022.
//

#include "App.h"

#include <utility>
#include "File.h"

void start(){
    Manager manager = *new Manager();
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
    std::cout << "5. Remove from file" << std::endl;
    handleOption(manager);
}

void handleOption(Manager* manager){
    int selectedOption;
    std::cin >> selectedOption;

    switch (selectedOption) {
        case 1:
            //TODO search
            readFromFile(manager);
            break;
        case 2:
            //TODO sorting
            for(auto& entry: manager->getEntries()){
                entry.print();
            }
            break;
        case 3:
            manager->createNewEntry();
            break;
        case 4:
            //TODO edit password
            manager->createNewEntry();
            break;
        case 5:
            manager->removeEntry();
            overrideFile(manager);
            break;
        case 6:
            //TODO Add category
            break;
        case 7:
            //TODO Delete category
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            break;
    }
    mainMenu(manager);
}

