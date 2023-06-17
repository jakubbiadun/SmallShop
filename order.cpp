#include "order.h"
#include <iostream>
#include <string>
Order::Order(string product, int amount, float vat, double price, paymentMethod type, string &clientName, float value): product(product), amount(amount), vat(vat), price(price), type(type), clientName(clientName), value(value)
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

paymentMethod Order::getPaymentMethod()
{
    return type; // czemu plujesz bledem
}

string Order::getClientName()
{
    return clientName;
}

float Order::getValue()
{
    return value;
}

void Order::showOrders()
{
    cout << "Produkt:" << product << endl
         << "Ilość: " << amount << endl
         << "Wartość VAT: " << vat << endl
         << "Cena: " << price << endl
         << "Płatność: " << type;
}

void Order::setProduct(string &product)
{
    this->product=product;
}

void Order::setAmount(int amount)
{
    this->amount=amount;
}

void Order::setVat(float vat)
{
    this->vat=vat;
}

void Order::setPrice(double price)
{
    this->price=price;
}

void Order::setPaymentMethod(paymentMethod type)
{
    this->type=type;
}

void Order::setClientName(string &clientName)
{
    this->clientName=clientName;
}

void Order::setValue(float value)
{
    this->value=value;
}
