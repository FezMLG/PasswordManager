#pragma once

#include <iostream>
#include "Manager.h"
#include "Categories.h"

void createFile();

void readFromFile(Manager* manager);

void deleteFromFile(Manager* manager, const string& name);

string getControlSum(const string& file);

void overrideFile(Manager* manager);

void appendToFile(Entry* entry);


