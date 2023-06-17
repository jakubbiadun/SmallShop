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
    cin.ignore();
    getline(cin, address);
    cout << "Podaj płeć" << endl;
    cin >> gender;

    Client nClient(firstName, lastName, address, gender);
    clients.push_back(nClient);
    cout << "Nowy klient został dodany" << endl;
}

void Menu::editClient()
{
    unsigned long clientNumber = 0; // propozycja qt zamienic z inta na longa
    int i= 0;
    for(auto& client:clients){
        cout << "Klient " << i << ": " << client.getFirstName() << " " << client.getLastName() << endl;
        i++;
    }
    cout << "Podaj number klienta, ktorego dane chcesz zmienić" << endl;
    if(clientNumber > 0 && clientNumber < clients.size()){ // chyba dobre warunki
        string fn, ln, ad, g;
        cout << "Imie: " << endl;
        cin >> fn;
        cout << "Nazwisko: " << endl;
        cin >> ln;
        cout << "Adres: " << endl;
        cin.ignore();
        getline(cin, ad);
        cout << "Płeć: " << endl;
        cin >> g;
        clients[clientNumber].setFirstName(fn);
        clients[clientNumber].setLastName(ln);
        clients[clientNumber].setAddress(ad);
        clients[clientNumber].setGender(g);
        cout << "Dane zostaly zmodyfikowane" << endl;
    }
    else{
        cout << "Nieprawidłowy number" << endl;
    }
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
    vector<string> availableProducts = productsFromFile();
    string productName, clientName;
    int amount = 0;
    float vat = 0.0;
    double price = 0.0;
    paymentMethod type;
    // dopytac o bledy
    cout << "Klienic: " << endl;
    for(auto&client:clients){
        cout << client.getFirstName() << " " << client.getLastName() << endl;
    }
    cout << "Wprowadź imie i nazwisko klienta: ";
    cin.ignore();
    getline(cin, clientName);
    cout << "Dostepne produkty: " << endl;
    showProducts(availableProducts);
    cout << "Nazwa produktu: ";
    getline(cin,productName);
    cout << "Podaj ilosc: ";
    cin >> amount;
    cout << "Podaj VAT: ";
    cin >> vat;
    cout << "Podaj cene: ";
    cin >> price;
    cout << "Metoda zamowienia: ";
    // jak pobrac enum
    float value = price * amount * (1 + (vat/100));
    Order nOrder(productName, amount, vat, price, type, clientName, value);
    orders.push_back(nOrder);
    cout << "Nowe zamówienie zostało dodane" << endl;
}

void Menu::editOrder()
{
    unsigned long orderNumber;
    showOrders();
    cout << "Podaj numer zamowienia do edycji: ";
    cin >> orderNumber;
    if(orderNumber >=0 && orderNumber <orders.size()){
        string productName, clientName;
        int amount;
        double price;
        float vat;
    }
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
    ofstream file("orders.txt");
    if(file.is_open()){
        for(auto&order:orders){
            file << order.getProduct() << " " << order.getAmount() << " " << order.getVat() << " " << order.getPrice() << " " << order.getPaymentMethod() << endl;
        }
        file.close();
        cout << "Lista zamówień została zapisana do pliku tekstowego" << endl;
    }
    else{
        cout << "Podczas otwierania pliku nastąpił błąd" << endl;
    }
}

void Menu::saveOrdersToBinaryFile()
{
    ofstream file("orders.bin", ios::binary);
    if(file.is_open()){
        for(auto& Order:orders){
            file.write(reinterpret_cast<char*>(&orders), sizeof(Order));
        }
        file.close();
        cout << "Lista zamówień została zapisana do pliku binarnego" << endl;
    }
    else{
        cout << "Podczas otwierania pliku nastąpił błąd" << endl;
    }
}

void Menu::showProducts(const vector<string>& availableProducts)
{
    cout << "Dostępne produkty: " << endl;
    for(auto& product:availableProducts){
        cout << product << endl;
    }
}

vector<string> Menu::productsFromFile(){
    vector<string> products;
    ifstream file("products.txt");
    string product;
    if(file.is_open()){
        while(getline(file,product)){
            products.push_back(product);
        }
        file.close();
    }
    else{
        cout << "Podczas otwierania pliku nastąpił błąd" << endl;
    }
    return products;
}

void Menu::start()
{
    vector<string> availableProducts = productsFromFile();
    int action;
    do{
        display();
        cin >> action;
        switch(action){
        case 1:{
            addClient();
            break;
        }
        case 2:{
            saveClientToTextFile();
            break;
        }
        case 3:{
            saveClientToBinaryFile();
            break;
        }
        case 4:{
            addOrder();
            break;
        }
        case 5:{
            editOrder();
            break;
        }
        case 6:{
            showProducts(availableProducts);
            break;
        }
        case 7:{
            showOrders();
            break;
        }
        case 8:{
            saveOrdersToTextFile();
            break;
        }
        case 9:{
            saveOrdersToBinaryFile();
            break;
        }
        case 0:{
            cout << "Zamykanie programu" << endl;
            break;
        }
        default:
            cout << "Nieprawidlowa wartosc, sprobuj jeszcze raz" << endl;
        }
    cout << endl;
    }while(action!=0);
}


