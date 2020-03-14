#include "Distributor.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyException{
    string error_message;
    public:
        MyException();
        MyException(string error){
            error_message = error;
        }
        void print_error(){
            cout << error_message << endl;
        }
};

Distributor::Distributor(){}

Distributor::Distributor(string name, int truck_count, vector<Truck> trucks){
    this->name = name;
    this->truck_count = truck_count;
    this->trucks = trucks;
}

int Distributor::order(string material, int quantity){
    int trucks_needed = 0;
    if(material == "liquid"){
        for(auto i : trucks){
            if(quantity < i.capacity){
                trucks_needed++;
                i.used = true;
                return trucks_needed;
            }
            else{
                trucks_needed++;
            }
        }
        throw(MyException("All trucks are already used"));
    }
    else if(material == "hard"){
        for(auto i : trucks){
            if(quantity < i.capacity){
                trucks_needed++;
                i.used = 1;
                return trucks_needed;
            }
            else{
                trucks_needed++;
            }
        }
        throw(MyException("All trucks are already used"));
    }
}

void Distributor::print_receipt(){
    for(auto i: ordered_liquid_materials){
        cout << "Ordered liquid materials" << endl;
        cout << "name" << i.name << "type" << i.type << "price" << i.price << "count" << i.count << endl;
    }
    for(auto i: storage_liquid_materials){
        cout << "Storaged liquid materials" << endl;
        cout << "name" << i.name << "type" << i.type << "price" << i.price << "count" << i.count << endl;
    }
    for(auto i: ordered_hard_materials){
        cout << "Ordered hard materials" << endl;
        cout << "name" << i.name << "type" << i.type << "price" << i.price << "count" << i.volume << endl;
    }
    for(auto i: storage_hard_materials){
        cout << "Storage hard materials" << endl;
        cout << "name" << i.name << "type" << i.type << "price" << i.price << "count" << i.volume << endl;
    }    
}