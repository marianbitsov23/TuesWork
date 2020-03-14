#include "stock.h"
#include "tech.h"
#include "provider.h"
#include "user.h"
#include "order.h"
#include "store.h"
#include "clothing.h"
#include <iostream>
#include <vector>

int main(){
    User user1 = User(1, "biko", "123");
    User user2 = User(2, "kiro", "321");
    User user3 = User(3, "sami", "123");

    Provider provider1 = Provider("georgi", "clothing");
    Provider provider2 = Provider("martin", "tech");
    Provider provider3 = Provider("videnov", "tech");

    Tech tech1 = Tech("Lenovo Legion", 1000, 10, provider2, 5, "black", 5, 4.2);
    Tech tech2 = Tech("Finlux", 100, 5, provider1, 2, "white", 3, 100);
    Tech tech3 = Tech("Huawei", 1500, 50, provider3, 10, "black", 2, 0.1);

    Clothing clothing1 = Clothing("Gucci", 500, 20, provider1, 1, "red", 2, "bamboo");
    Clothing clothing2 = Clothing("Addidas", 50, 100, provider2, 1, "black", 4, "cotton");
    Clothing clothing3 = Clothing("Basheva merch", 15, 1000, provider3, 1, "black", 3, "cotton");

    vector<Stock*> stocks;

    stocks.push_back(&tech1);
    stocks.push_back(&tech2);
    stocks.push_back(&tech3);
    stocks.push_back(&clothing1);
    stocks.push_back(&clothing2);
    stocks.push_back(&clothing3);

    Order order1 = Order(1, user1, stocks, 2, "New");

    stocks.pop_back();
    stocks.pop_back();

    Order order2 = Order(2, user2, stocks, 2, "New");

    stocks.pop_back();

    Order order3 = Order(3, user3, stocks, 2, "New");

    vector<User*> users;

    users.push_back(&user1);

    vector<Order*> orders;

    orders.push_back(&order1);

    Store store = Store(users, stocks, orders);

    store.print_info();

    store.add_user(&user2);

    cout << "-----------ADDING USER-----------" << endl;

    store.print_info();

    store.add_stock(&tech2);

    cout << "-----------ADDING STOCK-----------" << endl;

    store.print_info();

    store.create_order(&order2);

    cout << "-----------CREATING ORDER-----------" << endl;

    store.print_info();

    cout << store.accept_order(2).first << " $ - " << store.accept_order(2).second << " days" << endl;

    cout << "-----------ACCEPTING ORDER-----------" << endl;

    store.print_info();   

    store.send_order(2);

    cout << "-----------SEND ORDER-----------" << endl;

    store.print_info();

    return 0;

}