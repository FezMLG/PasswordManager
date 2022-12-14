#include "File.h"

using namespace std;

void loadFile() {
    string text;
    fstream LoadedFile("../data/sample.txt");

    while (getline (LoadedFile, text)) {
        cout << text << endl;
    }

    LoadedFile.close();
};
