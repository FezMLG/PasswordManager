//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_APP_H
#define PASSWORDMANAGER_APP_H

#include <iostream>
#include "Manager.h"
#include "Categories.h"

void start();
void getFileAndPassword(Manager* manager);
void mainMenu(Manager* manager, Categories* categories);
void handleOption(Manager* manager, Categories* categories);

#endif //PASSWORDMANAGER_APP_H
