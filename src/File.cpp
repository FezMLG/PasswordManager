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
            manager->pushToEntries(*entry);
        }
    }

    LoadedFile.close();
};

void deleteFromFile(Manager* manager, const string& name){
    vector<Entry> temp;
    for (auto& entry : manager->getEntries()){
        if(entry.getName() != name){
            temp.push_back(entry);
        }
    }
    manager->setEntries(temp);
};

string getControlSum(string file){
    string control;
    fstream File(file);
    getline (File, control);
    if(control != "AbCd"){
        throw runtime_error("Error when decoding file");
    }
    File.close();
    return control;
};

void overrideFile(Manager* manager){
    const char *file = "../data/sample.txt";
    string control = getControlSum(file);
    string text;
    for(auto& entry : manager->getEntries()){
        text.append(entry.printForFile());
    }

    std::ofstream LoadedFile ("../data/temp.txt");

    LoadedFile << control << '\n';
    LoadedFile << text;

    LoadedFile.close();
    std::remove(file);
    std::rename("../data/temp.txt", file);
}

void appendToFile(Entry* entry){
    std::ofstream LoadedFile;
    LoadedFile.open("../data/sample.txt", std::ios::app);

    LoadedFile << entry->printForFile();

    LoadedFile.close();
}