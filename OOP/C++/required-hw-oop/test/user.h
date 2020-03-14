#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;

class User{
    public:
        unsigned int id;
        string username;
        string password;

        User();
        User(unsigned int id, string username, string passsword);

        void print_info();
};

#endif