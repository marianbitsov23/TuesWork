#include "order.h"

Order::Order(){
    id = 0;
    user = User();
    Stock basic;
    orderedStocks.push_back(&basic);
    orderedQuantity = 0;
    status = "basicstatus";
}

Order::Order(int id, User user, vector<Stock*> orderedStocks, int orderedQuantity, string status){
    this->id = id;
    this->user= user;
    this->orderedStocks = orderedStocks;
    this->orderedQuantity = orderedQuantity;
    this->status = status;
}

void Order::AddStock(Stock* stock){
    for(auto i : orderedStocks){
        if(stock->name == i->name){
            orderedQuantity++;
            return;
        }
    }
    orderedStocks.push_back(stock);
    orderedQuantity++;
}

double Order::order_price(){
    double sum = 0;
    for(auto i : orderedStocks){
        sum += i->price;
    }
    sum *= orderedQuantity;
    return sum;
}

int Order::max_shipping(){
    int max = 0;
    for(auto i : orderedStocks){
        if(max < i->shippingDays){
            max = i->shippingDays;
        }
    }
    return max;
}

void Order::print_info(){
    cout << "Id: " << id << " User: " << user.username << endl;
    for(auto i : orderedStocks){
        i->print_info();
    }
    cout << " Ordered quantity: " << orderedQuantity << " Status: " << status << endl; 
}