#include "provider.h"

Provider::Provider(){
    name = "basic";
    typeOfStock = "basic";
}

Provider::Provider(string name, string typeOfStock){
    this->name = name;
    this->typeOfStock = typeOfStock;
}

void Provider::print_info(){
    cout << " Name: " << name << " Type of stock: " << typeOfStock << endl;
}