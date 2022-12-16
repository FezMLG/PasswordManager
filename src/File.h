#pragma once

#include <iostream>
#include "Manager.h"

void createFile();

void readFromFile(Manager* manager);

void deleteFromFile(Manager* manager, string name);

string getControlSum(string file);

void overrideFile(Manager* manager);

void appendToFile(Entry* entry);


