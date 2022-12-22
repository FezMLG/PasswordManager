//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_APP_H
#define PASSWORDMANAGER_APP_H

#include <iostream>
#include "Manager.h"

/**
 * @brief starting point for program
 */
void start();

/**
 * @brief manual encryption/decryption of file, to enable, change manualEncryptMode flag
 * @param manager
 */
void manualEncryption(Manager *manager);

/**
 * @brief getting file path and password from user
 * @param manager Manager class initialized in start point
 */
void getFileAndPassword(Manager *manager);

/**
 * @brief printing main manu to console
 * @param manager Manager class initialized in start point
 */
void mainMenu(Manager *manager);

/**
 * @brief handling option chosen from main menu by user
 * @param manager Manager class initialized in start point
 */
void handleOption(Manager *manager);

#endif //PASSWORDMANAGER_APP_H
