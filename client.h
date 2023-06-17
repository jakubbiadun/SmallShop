#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
using namespace std;

class Client{
private:
        string firstName;
        string lastName;
        string address;
        string gender;
public:
    Client(string fName, string lNname, string address, string gender);

    string getFirstName();
    string getLastName();
    string getAddress();
    string getGender();

    void showClientsData();

    //do edycji danych klienta potrzeba czegos
    // do edycji klienta
    void setFirstName(string &firstName);
    void setLastName(string &lastName);
    void setAddress(string &address);
    void setGender(string gender);
};

#endif // CLIENT_H
