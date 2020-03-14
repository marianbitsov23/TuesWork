#include "client.h"
#include <iostream>
#include <string>
using namespace std;

Client::Client(){}

Client::Client(string name, string address, double expenses){
    this->name = name;
    this->address = address;
    this-> expenses = expenses;
}

void Client::set_name(string name){
    this->name = name;
}

string Client::get_name(){
    return name;
}

void Client::set_address(string address){
    this->address = address;
}

string Client::get_address(){
    return address;
}

void Client::set_expenses(double expenses){
    this->expenses = expenses;
}

double Client::get_expenses(){
    return expenses;
}

void Client::print_info(){
    cout << get_name() << endl;
    cout << get_address() << endl;
    cout << get_expenses() << endl;
}