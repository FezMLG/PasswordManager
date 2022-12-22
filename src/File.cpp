//
// Created by Konrad on 15.12.2022.
//

#include "File.h"

/**
 *  @brief control sum to check if file is decrypted properly
 *  @warning if changed, all previous files cannot be decrypted
 */
static string controlSum{"519f56b8-c7bc-428f-928f-06bd8243f82d"};

/**
 * @brief path to app data folder
 */
static fs::path dataFolderPath = fs::path{"../data"};

/**
 * @brief path to temporarily decrypted file
 * @warning only for usage by app
 */
static string decryptedFilePath = fs::path{"../data/temp/decrypted.txt"}.string();

/**
 * @brief path to temp file
 * @warning only for usage by app
 */
static string tempFilePath = fs::path{"../data/temp/temp.txt"}.string();

bool checkIfFileExists(const std::string &name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

string listAndSelectFile() {
    std::vector<fs::path> file_paths;

    for (const fs::directory_entry &entry: fs::directory_iterator(dataFolderPath)) {
        if (entry.is_regular_file()) {
            file_paths.push_back(entry.path());
        }
    }

    // Print the file paths
    int i = 0;
    for (const fs::path &path: file_paths) {
        std::cout << i << ": " << path.string() << std::endl;
        i++;
    }
    cout << "-1: Your own path" << endl;
    cout << "-------------" << endl << "Select file number: " << endl;
    int selectedFile;
    cin >> selectedFile;
    if (selectedFile == -1) {
        string userPath;
        cout << "Type your path: " << endl;
        cin >> userPath;
        if (!checkIfFileExists(userPath)) {
            cout << "File " << userPath << " does not exist" << endl;
            exit(1);
        }
        return fs::path{userPath}.string();
    }
    return file_paths[selectedFile].string();
}

void createFile(const string &name) {
    std::ofstream LoadedFile;
    LoadedFile.open(name, std::ios::app);

    LoadedFile << controlSum;

    LoadedFile.close();
}

void readFromFile(Manager *manager) {
    if (!checkIfFileExists(manager->getFilePath())) {
        createFile(decryptedFilePath);
        encryptFile(decryptedFilePath, manager->getFilePath(), manager->getPassword());
    }
    decryptFile(manager->getFilePath(), decryptedFilePath, manager->getPassword());


    string control;
    string text;

    fstream LoadedFile(decryptedFilePath);

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
    std::remove(decryptedFilePath.c_str());
};

string getAndCheckControlSum(const string &file) {
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
    decryptFile(manager->getFilePath(), decryptedFilePath, manager->getPassword());

    string control = getAndCheckControlSum(decryptedFilePath);
    string text;
    for (auto &entry: manager->getEntries()) {
        text.append(entry.printForFile());
    }

    std::ofstream LoadedFile(tempFilePath);

    LoadedFile << control << '\n';
    LoadedFile << text;

    LoadedFile.close();
    std::remove(decryptedFilePath.c_str());
    std::rename(tempFilePath.c_str(), decryptedFilePath.c_str());

    encryptFile(decryptedFilePath, manager->getFilePath(), manager->getPassword());
    std::remove(decryptedFilePath.c_str());
}

void appendToFile(Entry *entry, Manager *manager) {
    decryptFile(manager->getFilePath(), decryptedFilePath, manager->getPassword());

    std::ofstream LoadedFile;
    LoadedFile.open(decryptedFilePath, std::ios::app);

    LoadedFile << entry->printForFile();

    LoadedFile.close();

    std::remove(manager->getFilePath().c_str());
    encryptFile(decryptedFilePath, manager->getFilePath(), manager->getPassword());
    std::remove(decryptedFilePath.c_str());
}

void encryptFile(const std::string &inputFile, const std::string &outputFile, std::string key) {
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    int passLength = key.length();
    char c;
    int i = 0;
    while (in.get(c)) {
        if (i == passLength) i = 0;
        c ^= key[i];

        out.put(c);
        i++;
    }

    in.close();
    out.close();
}

void decryptFile(const std::string &inputFile, const std::string &outputFile, std::string key) {
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    int passLength = key.length();
    char c;
    int i = 0;
    while (in.get(c)) {
        if (i == passLength) i = 0;
        c ^= key[i];

        out.put(c);
        i++;
    }

    in.close();
    out.close();
}