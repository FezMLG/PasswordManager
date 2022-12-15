//
// Created by Konrad on 15.12.2022.
//

#include "App.h"

#include <utility>
#include "File.h"

void start(){
    Manager manager = *new Manager();
    mainMenu(manager);
};

void mainMenu(Manager manager){
    std::cout << "Choose option: " << std::endl;
    std::cout << "1. Load file" << std::endl;
    std::cout << "2. Add to file" << std::endl;
    handleOption(std::move(manager));
}

void handleOption(Manager manager){
    int selectedOption;
    std::cin >> selectedOption;

    switch (selectedOption) {
        case 1:
            readFromFile(&manager);
            break;
        case 2:
            manager.createNewEntry();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
            break;
    }
    mainMenu(manager);
}

