#ifndef CLIENT_H
#define CLIENT_H
#include <string>

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
};

#endif // CLIENT_H
