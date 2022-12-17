//
// Created by Konrad on 15.12.2022.
//

#include <fstream>
#include "File.h"

using namespace std;

static string controlSum = "519f56b8-c7bc-428f-928f-06bd8243f82d";

bool checkIfFileExists(const std::string &name) {
    ifstream f(name.c_str());
    return f.good();
}

void createFile(const std::string &name) {
    std::ofstream LoadedFile;
    LoadedFile.open(name, std::ios::app);

    LoadedFile << controlSum;

    LoadedFile.close();
}

void readFromFile(Manager *manager) {
    if (!checkIfFileExists(manager->getFilePath())) {
        createFile("../data/decrypt.txt");
        encryptFile("../data/decrypt.txt", manager->getFilePath(), manager->getPassword());
    }
    decryptFile(manager->getFilePath(), "../data/decrypt.txt", manager->getPassword());


    string control;
    string text;

    fstream LoadedFile("../data/decrypt.txt");

    getline(LoadedFile, control);
    if (control != controlSum) {
        cout << "Error when decoding file";
        exit(1);
    }

    while (getline(LoadedFile, text)) {
        if (text == "#START") {
            getline(LoadedFile, text);
            string name = text;

            getline(LoadedFile, text);
            string login = text;

            getline(LoadedFile, text);
            string password = text;

            getline(LoadedFile, text);
            string category = text;
            manager->getCategories()->addName(category);

            getline(LoadedFile, text);
            string type = text;

            getline(LoadedFile, text);
            string service = text;

            auto *entry = new Entry(name, login, password, category, type, service);
            manager->pushToEntries(*entry);
        }
    }

    LoadedFile.close();
    std::remove("../data/decrypt.txt");
};

void deleteFromFile(Manager *manager, const string &name) {
    vector<Entry> temp;
    for (auto &entry: manager->getEntries()) {
        if (entry.getName() != name) {
            temp.push_back(entry);
        }
    }
    manager->setEntries(temp);
};

string getControlSum(const string &file) {
    string control;
    fstream File(file);
    getline(File, control);
    if (control != controlSum) {
        throw runtime_error("Error when decoding file");
    }
    File.close();
    return control;
};

void overrideFile(Manager *manager) {
    decryptFile(manager->getFilePath(), "../data/decrypt.txt", manager->getPassword());

    const char *file = "../data/decrypt.txt";
    string control = getControlSum(file);
    string text;
    for (auto &entry: manager->getEntries()) {
        text.append(entry.printForFile());
    }

    std::ofstream LoadedFile("../data/temp.txt");

    LoadedFile << control << '\n';
    LoadedFile << text;

    LoadedFile.close();
    std::remove(file);
    std::rename("../data/temp.txt", file);

    encryptFile("../data/decrypt.txt", manager->getFilePath(), manager->getPassword());
    std::remove("../data/decrypt.txt");
}

void appendToFile(Entry *entry, Manager *manager) {
    decryptFile(manager->getFilePath(), "../data/decrypt.txt", manager->getPassword());

    std::ofstream LoadedFile;
    LoadedFile.open("../data/decrypt.txt", std::ios::app);

    LoadedFile << entry->printForFile();

    LoadedFile.close();

    std::remove(manager->getFilePath().c_str());
    encryptFile("../data/decrypt.txt", manager->getFilePath(), manager->getPassword());
    std::remove("../data/decrypt.txt");
}

// Function to encrypt a file
void encryptFile(const std::string &inputFile, const std::string &outputFile, std::string key) {
    // Open the input and output files
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    // Read the input file one byte at a time and encrypt each byte
    int passLength = key.length();
    char c;
    int i = 0;
    while (in.get(c)) {
        if (i == passLength) i = 0;
        // Encrypt the byte by XORing it with the key
        c ^= key[i];

        // Write the encrypted byte to the output file
        out.put(c);
        i++;
    }

    // Close the input and output files
    in.close();
    out.close();
}

// Function to decrypt a file
void decryptFile(const std::string &inputFile, const std::string &outputFile, std::string key) {
    // Open the input and output files
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    // Read the input file one byte at a time and encrypt each byte
    int passLength = key.length();
    char c;
    int i = 0;
    while (in.get(c)) {
        if (i == passLength) i = 0;
        // Encrypt the byte by XORing it with the key
        c ^= key[i];

        // Write the encrypted byte to the output file
        out.put(c);
        i++;
    }

    // Close the input and output files
    in.close();
    out.close();
}