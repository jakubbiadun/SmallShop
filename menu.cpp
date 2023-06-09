#include "menu.h"
#include <iostream>
#include <fstream>
void Menu::display()
{
    cout << "Menu:" << endl
         << "1 - Dodaj nowego klienta" << endl
         << "2 - Zapisz dane klientów do pliku tekstowego" << endl
         << "3 - Zapisz dane klientów do pliku binarnego" << endl
         << "4 - Dodaj zamówienia" << endl
         << "5 - Edytuj zamówienie" << endl
         << "6 - Pokaż listę dostępnych produktów" << endl
         << "7 - Pokaż listę zamówień" << endl
         << "8 - Zapisz listę zamówień do pliku binarnego" << endl
         << "9 - Zapisz listę zamówień do pliku tekstowego" << endl
         << "0 - Opuść program" << endl;
    cout << "Wybierz operację: " << endl;
}

void Menu::addClient()
{
    string firstName, lastName, address, gender;
    cout << "Podaj imię: " << endl;
    cin >> firstName;
    cout << "Podaj nazwisko: " << endl;
    cin >> lastName;
    cout << "Wprowadź adres dostawy: " << endl;
    getline(cin, address);
    cout << "Podaj płeć" << endl;
    cin >> gender;

    Client nClient(firstName, lastName, address, gender);
    clients.push_back(nClient);
    cout << "Nowy klient został dodany" << endl;
}

void Menu::saveClientToBinaryFile()
{
    ofstream file("clients.bin", ios::binary);
    if(file.is_open()){
        for(auto& client : clients){ // dopytac o to
            file.write(reinterpret_cast<char*>(&client), sizeof(Client)); // czy to tak powinno wygladac !?!?!?!?
        }
        file.close();
        cout << "Dane klientów zostałY zapisane do pliku binarnego" << endl;
    }
    else{
        cout << "Podczas otwierania pliku nastąpił błąd" << endl;
    }
}

void Menu::saveClientToTextFile()
{
    ofstream file("clients.txt");
    if(file.is_open()){
        for(auto& client : clients){ //dopytac o ta część,
            file << client.getFirstName() << " " << client.getLastName() << " " << client.getAddress() << " " << client.getGender() << endl;
        }
        file.close();
        cout << "Dane klientów zostały zapisane do pliku tekstowego" << endl;
    }
    else{
        cout << "Podczas otwierania pliku nastąpił błąd" << endl;
    }
}

void Menu::addOrder()
{
    string product;
    int amount;
    float vat;
    double price;
    paymentMethod type;
    // dopytac o bledy
    Order nOrder(product, amount, vat, price, type);
    orders.push_back(nOrder);
    cout << "Nowe zamówienie zostało dodane" << endl;
}

void Menu::editOrder()
{

}

void Menu::showOrders()
{
    cout << "Zamówienia: " << endl;
    for(auto&order : orders){
        order.showOrders();
        cout << endl;
    }
}

void Menu::saveOrdersToTextFile()
{

}

void Menu::saveOrdersToBinaryFile()
{

}

void Menu::showProducts()
{

}

void Menu::start()
{

}


