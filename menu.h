#ifndef MENU_H
#define MENU_H
#include "client.h"
#include "order.h"
#include <string>
#include <vector>

using namespace std;

class Menu{
private:
    vector<Client> clients;
    vector<Order> orders;
    vector<string> productsFromFile();

    void display();
    void addClient();
    void editClient();
    void saveClientToBinaryFile();
    void saveClientToTextFile();
    void addOrder();
    void editOrder();
    void showOrders();
    void saveOrdersToTextFile();
    void saveOrdersToBinaryFile();
    void showProducts(const vector<string>& availableProducts);


public:
    void start();
};

#endif // MENU_H
