#include <fstream>
#include "Manager.h"

using namespace std;

void readFromFile(Manager* manager) {
    string control;
    string text;

    fstream LoadedFile("../data/sample.txt");

    getline (LoadedFile, control);
    if(control != "AbCd"){
        throw runtime_error("Error when decoding file");
    }

    while (getline (LoadedFile, text)) {
        if(text == "#START"){
            getline (LoadedFile, text);
            string name = text;

            getline (LoadedFile, text);
            string login = text;

            getline (LoadedFile, text);
            string password = text;

            getline (LoadedFile, text);
            string category = text;

            getline (LoadedFile, text);
            string type = text;

            getline (LoadedFile, text);
            string service = text;

            auto* entry = new Entry(name, login, password, category, type, service);
            entry->print();
            manager->pushToEntries(*entry);
        }
    }

    LoadedFile.close();
};

void saveToFile(Entry* entry){
    std::ofstream LoadedFile;
    LoadedFile.open("../data/sample.txt", std::ios::app);

    LoadedFile << entry->printForFile();

    LoadedFile.close();
}