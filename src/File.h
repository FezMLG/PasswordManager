//
// Created by Konrad on 15.12.2022.
//

#ifndef PASSWORDMANAGER_FILE_H
#define PASSWORDMANAGER_FILE_H

#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include "Manager.h"
#include "Categories.h"

using namespace std;
namespace fs = std::filesystem;

/**
 * @brief checking if file exists
 * @param name path to the file
 * @return true if exists, false if not
 */
bool checkIfFileExists(const std::string &name);

/**
 * @brief printing list of files in data folder for user, or allowing to enter custom path
 * @return path to selected file
 */
string listAndSelectFile();

/**
 * @brief creating file
 * @param name path of file to create
 */
void createFile(const string &name);

/**
 * @brief read entries from file
 * @param manager Manager class from start point
 */
void readFromFile(Manager *manager);

/**
 * @brief Checking if file is decoded correctly
 * @param file path to file
 * @return control value from file
 */
string getAndCheckControlSum(const string &file);

/**
 * @brief overriding existing file
 * @param manager Manager class from entry point
 */
void overrideFile(Manager *manager);

/**
 * @brief append Entry to the end of the file
 * @param entry Entry to append
 * @param manager Manager class from entry point
 */
void appendToFile(Entry *entry, Manager *manager);

/**
 * @brief File encryption
 * @param inputFile path to decrypted file
 * @param outputFile path to file when encrypted
 * @param key encryption key
 */
void encryptFile(const std::string &inputFile, const std::string &outputFile, std::string key);

/**
 * @brief File decryption
 * @param inputFile path to encrypted file
 * @param outputFile path to file when decrypted
 * @param key encryption key
 */
void decryptFile(const std::string &inputFile, const std::string &outputFile, std::string key);

#endif //PASSWORDMANAGER_FILE_H
