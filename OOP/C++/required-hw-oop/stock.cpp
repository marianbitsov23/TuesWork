#include "stock.h"

Stock::Stock(){
    name = "basic";
    price = 0;
    quantity = 1;
    provider = Provider();
    shippingDays = 0;
}

Stock::Stock(string name, double price, double quantity, Provider provider, int shippingDays){
    this->name = name;
    this->price = price;
    this->quantity = quantity;
    this->provider = provider;
    this->shippingDays = shippingDays;
}

void Stock::print_info(){
    cout << "Name: " << name << " Price: " << price << " Provider: " << provider.name << " Quantity: " << quantity << " Shipping: " << shippingDays << endl;
}