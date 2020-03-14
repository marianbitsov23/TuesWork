#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product{
    protected:
        string name;
        string producer;
        double price;
        double barcode;
        string description;
    
    public:
        Product();
        Product(string name, string producer, double price, double barcode, string description);
        void set_name(string name);
        string get_name();
        void set_producer(string producer);
        string get_producer();
        void set_price(double price);
        double get_price();
        void set_barcode(double barcode);
        double get_barcode();
        void set_description(string description);
        string get_description();
};

#endif