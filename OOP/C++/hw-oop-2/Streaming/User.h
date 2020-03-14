#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include "Bill.h"
using namespace std;

class User{
public:    
    string name;
    string email;
    vector<string> usedMedia;
    Bill bill;

    User();
    User(string name, string email, vector<string> usedMedia, Bill bill);

};

#endif