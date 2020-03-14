#include "store.h"

class MyException{
    string error;
    public:
        MyException(string message){
            error = message;
        }

        void print_error(){
            cout << error << endl;
        }
};

Store::Store(){}

Store::Store(vector<User*> users, vector<Stock*> stocks, vector<Order*> orders){
    this->users = users;
    this->stocks = stocks;
    this->orders = orders;
}

void Store::add_user(User* user){
    for(auto i : users){
        if(i->id == user->id){
            throw MyException("There is an already existing user with that id!");
        }
    }
    users.push_back(user);
}

void Store::add_stock(Stock* stock){
    for(auto i : stocks){
        if(i->name == stock->name){
            i->quantity++;
        }
    }
    stocks.push_back(stock);
}

void Store::create_order(Order* order){
    for(auto i : stocks){
        if(i->quantity - order->orderedQuantity < 0){
            throw MyException("There is no more stocks left in the store!");
        }
        i->quantity -= order->orderedQuantity;
    }
    for(auto i : orders){
        if(i->id == order->id){
            throw MyException("There is an already existing order with that id!");
        }
        if(order->user.id == 0){
            throw MyException("Your tired to create and orderd for non existing user!");
        }
    }

    orders.push_back(order);
}

std::pair<double, int> Store::accept_order(unsigned int order_id){
    for(auto i : orders){
        if(i->id == order_id){
            cout << "Accepting order" << endl;
            i->status = "Confirmed";
            std::pair<double, int> pair(i->order_price(), i->max_shipping());
            cout << "id: "<< i->id << " username: " << i->user.username << " Status: "<< i->status << endl;
            return pair;
        }
    }
    throw MyException("There is no order with that order id!");
}

void Store::send_order(unsigned int order_id){
    bool sent = false;
    for(auto i : orders){
        if(i->id == order_id){
            if(i->status != "Confirmed"){
                throw MyException("This order has a different status(not Confirmed)!");
            }
            i->status = "Sent";
            sent = true;
        }
    }
    if(sent == false){
        throw MyException("There is no order with that order id!");
    }
}

vector<Order const*> Store::get_orders_by_user(unsigned int user_id) const{
    vector<Order const*> allOrders; 
    bool exists = false;
    for(auto i : orders){
        if(i->user.id == user_id){
            allOrders.push_back(i);
            exists = true;
        }
    }
    if(exists == false){
        throw MyException("There is no existing user with that id!");
    }
    return allOrders;
}

vector<Stock const*> Store::get_stocks_by_provider(Provider * provider) const{
    vector<Stock const*> allStocks;
    for(auto i : stocks){
        if(i->provider.name == provider->name){
            allStocks.push_back(i);
        }
    }
    return allStocks;
}

void Store::print_info(){
    cout << "Stocks info" << endl;
    for(auto i : stocks){
        i->print_info();
    }
    cout << endl;
    cout << "Orders info" << endl;
    for(auto i : orders){
        i->print_info();
    }
    cout << endl;
    cout << "Users info" << endl;
    for(auto i : users){
        i->print_info();
    }

    cout << "------------------" << endl;
}