#include "File.h"
#include "Entry.h"

using namespace std;

void loadFile() {
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

            Entry* entry = new Entry(name, login, password, category, type, service);
            entry->print();
        }
    }

    LoadedFile.close();
};
