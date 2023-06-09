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

    void display();
    void addClient();
    void saveClientToBinaryFile();
    void saveClientToTextFile();
    void addOrder();
    void editOrder();
    void showOrders();
    void saveOrdersToTextFile();
    void saveOrdersToBinaryFile();
    void showProducts();


public:
    void start();
};

#endif // MENU_H
