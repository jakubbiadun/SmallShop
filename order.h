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
    string clientName;
    float value;

public:
    Order(string product, int amount, float vat, double price, paymentMethod type, string &clientName, float value);
    string getProduct();
    int getAmount();
    float getVat();
    double getPrice();
    paymentMethod getPaymentMethod();
    string getClientName();
    float getValue();
    void showOrders();

    //do edycji
    void setProduct(string &product);
    void setAmount(int amount);
    void setVat(float vat);
    void setPrice(double price);
    void setPaymentMethod(paymentMethod type);
    void setClientName(string &clientName);
    void setValue(float value);
};

#endif // ORDER_H
