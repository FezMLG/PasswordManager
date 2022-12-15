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
    std::cout << "2. Load file" << std::endl;
    std::cout << "3. Add to file" << std::endl;
    handleOption(std::move(manager));
}

void handleOption(Manager manager){
    int selectedOption;
    std::cin >> selectedOption;

    switch (selectedOption) {
        case 1:
            //TODO search
            readFromFile(&manager);
            break;
        case 2:
            //TODO sorting
            readFromFile(&manager);
            break;
        case 3:
            manager.createNewEntry(&manager);
            break;
        case 4:
            //TODO edit password
            manager.createNewEntry(&manager);
            break;
        case 5:
            //TODO Delete password
            manager.createNewEntry(&manager);
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

