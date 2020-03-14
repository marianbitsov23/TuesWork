#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Media.h"
#include "Bill.h"
using namespace std;

class Service{
public:    
    vector<User> users;
    vector<string> media;

    Service();
    Service(vector<User> users, vector<string> media);

    vector<User> getUsers();
    Bill getUserBill(int whom);
    bool getPayment();
    string searchMedia(string needle);

};

#endif