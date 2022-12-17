//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_FILE_H
#define PASSWORDMANAGER_FILE_H

#pragma once

#include <iostream>
#include "Manager.h"
#include "Categories.h"

void createFile();

void readFromFile(Manager *manager);

void deleteFromFile(Manager *manager, const string &name);

string getControlSum(const string &file);

void overrideFile(Manager *manager);

void appendToFile(Entry *entry, Manager *manager);

void encryptFile(const std::string &inputFile, const std::string &outputFile, std::string key);

void decryptFile(const std::string &inputFile, const std::string &outputFile, std::string key);

#endif //PASSWORDMANAGER_FILE_H
