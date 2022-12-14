//
// Created by Konrad on 15.12.2022.
//

#include "App.h"
#include "File.h"

void start(){
    mainMenu();
    handleOption();
};

void mainMenu(){
    std::cout << "Choose option: " << std::endl;
    std::cout << "1. Load file" << std::endl;
    std::cout << "2. Add to file" << std::endl;
}

void handleOption(){
    int selectedOption;
    std::cin >> selectedOption;

    switch (selectedOption) {
        case 1:
            loadFile();
            break;
        case 2:
            break;
    }
}

