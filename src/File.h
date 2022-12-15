#pragma once

#include <iostream>
#include "Manager.h"

void createFile();

void readFromFile(Manager* manager);

void saveToFile(Entry* entry);

void deleteFromFile();