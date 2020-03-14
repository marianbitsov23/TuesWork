#include "tech.h"

Tech::Tech(){
    Stock();
    typeOfTech = "basic";
    price = 0;
    quantity = 0;
}

Tech::Tech(string name, double price, double quantity, Provider provider, int shippingDays, string typeOfTech, int warranty, double weight){
    this->name = name;
    this->price = price;
    this->quantity = quantity;
    this->provider = provider;
    this->shippingDays = shippingDays;
    this->typeOfTech = typeOfTech;
    this->warranty = warranty;
    this->weight = weight;
}

Tech::Tech(string typeOfTech, int warranty, double weight){
    this->typeOfTech = typeOfTech;
    this->warranty = warranty;
    this->weight = weight;
}

void Tech::print_info(){
    cout << "Name: " << name << " Price: " << price << " Provider: " << provider.name << " Quantity: " << quantity << " Shipping: " << shippingDays;
    cout << " Type: " << typeOfTech << " Warranty: " << warranty << " Weight: " << weight << endl;
}