#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <iostream>
#include <vector>
#include "user.h"
#include "stock.h"
using namespace std;

class Order{
    public:
        int id;
        User user;
        vector<Stock*> orderedStocks;
        int orderedQuantity;
        string status;

        Order();
        Order(int id, User user, vector<Stock*> orderedStocks, int orderedQuantity, string status);

        void AddStock(Stock* stock);
        double order_price();
        int max_shipping();
        void print_info();
};

#endif