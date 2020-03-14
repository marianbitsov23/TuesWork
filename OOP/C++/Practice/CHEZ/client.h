#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
using namespace std;

class Client{
    protected:
        string name;
        string address;
        double expenses;
    public:
        Client();
        Client(string name, string address, double expenses);
        void set_name(string name);
        string get_name();
        void set_address(string address);
        string get_address();
        void set_expenses(double expenses);
        double get_expenses();
        void print_info();
};

#endif