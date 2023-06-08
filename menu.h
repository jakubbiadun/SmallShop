#ifndef MENU_H
#define MENU_H
#include "client.h"
#include <string>
#include <vector>

using namespace std;

class Menu{
private:
    vector<Client> clients;

    void display();
    void addClient();
    void saveToBinary();
    void saveToFile();

public:
    Menu();
};

#endif // MENU_H