#ifndef STORE_H
#define STORE_H
#include <string>
#include <iostream>
#include <vector>
#include "user.h"
#include "tech.h"
#include "clothing.h"
#include "order.h"
using namespace std;

class Store{
    public:
        vector<User*> users;
        vector<Stock*> stocks;
        vector<Order*> orders;

        Store();
        Store(vector<User*> users, vector<Stock*> stocks, vector<Order*> orders);

        void add_user(User* user);
        void add_stock(Stock* stock);
        void create_order(Order* order);
        std::pair<double, int> accept_order(unsigned int order_id);
        void send_order(unsigned int order_id);
        vector<Order const*> get_orders_by_user(unsigned int user_id) const;
        vector<Stock const*> get_stocks_by_provider(Provider* provider) const;

        void print_info();

};

#endif