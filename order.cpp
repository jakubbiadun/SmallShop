#include "order.h"
#include <iostream>
#include <string>
Order::Order(string product, int amount, float vat, double price, paymentMethod type): product(product), amount(amount), vat(vat), price(price), type(type)
{

}

string Order::getProduct()
{
    return product;
}

int Order::getAmount()
{
    return amount;
}

float Order::getVat()
{
    return vat;
}

double Order::getPrice()
{
    return price;
}

string Order::getPaymentMethod()
{
    return static_cast<paymentMethod>(type); // czemu plujesz bledem
}

void Order::showOrders()
{
    cout << "Produkt:" << product << endl
         << "Ilość: " << amount << endl
         << "Wartość VAT: " << vat << endl
         << "Cena: " << price << endl
         << "Płatność: " << type;
}
