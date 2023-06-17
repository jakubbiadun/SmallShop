#include "client.h"
#include <iostream>

Client::Client(string fName, string lName, string address, string gender): firstName(fName), lastName(lName), address(address), gender(gender)
{

}

string Client::getFirstName()
{
    return firstName;
}

string Client::getLastName()
{
    return lastName;
}

string Client::getAddress()
{
    return address;
}

string Client::getGender()
{
    return gender;
}

void Client::showClientsData()
{
    cout << "Imie: " << firstName << endl
         << "Nazwisko: " << lastName << endl
         << "Adres dostawy: " << address << endl
         << "Płeć: " << gender << endl;
}

void Client::setFirstName(string &firstName)
{
    this->firstName=firstName;
}

void Client::setLastName(string &lastName)
{
    this->lastName=lastName;
}

void Client::setAddress(string &address)
{
    this->address=address;
}

void Client::setGender(string gender)
{
    this->gender=gender;
}
