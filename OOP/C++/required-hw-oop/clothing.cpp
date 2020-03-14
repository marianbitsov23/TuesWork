#include "clothing.h"

Clothing::Clothing(){
    Stock();
    color = "basicwhite";
    size = 0;
    material = "basic";
}

Clothing::Clothing(string name, double price, double quantity, Provider provider, int shippingDays, string color, double size, string material){
    this->name = name;
    this->price = price;
    this->quantity = quantity;
    this->provider = provider;
    this->shippingDays = shippingDays;
    this->color = color;
    this->size = size;
    this->material = material;
}

Clothing::Clothing(string color, double size, string material){
    this->color = color;
    this->size = size;
    this->material = material;
}

void Clothing::print_info(){
    cout << "Name: " << name << " Price: " << price << " Provider: " << provider.name << " Quantity: " << quantity << " Shipping: " << shippingDays;
    cout << " Color: " << color << " Size: " << size << " Material: " << material << endl;
}