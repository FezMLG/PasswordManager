#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Entry {
private:
    std::string name;
    std::string login;
    std::string password;
    std::string category;
    std::string type;
    std::string service;

public:
    Entry(const std::string &name, const std::string &login, const std::string &password, const std::string &category,
          const std::string &type, const std::string &service);

    void print();
    string printForFile();
};