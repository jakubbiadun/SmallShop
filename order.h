#ifndef ORDER_H
#define ORDER_H
#include <string>

using namespace std;

enum paymentMethod {card, blik, paypal};

class Order{
private:
    string product;
    int amount;
    float vat;
    double price;
    paymentMethod type;

public:
    Order(string product, int amount, float vat, double price, paymentMethod type);
    string getProduct();
    int getAmount();
    float getVat();
    double getPrice();
    string getPaymentMethod();
    void showOrders();
};

#endif // ORDER_H
