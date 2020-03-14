#include "Service.h"

Service::Service(){}

Service::Service(vector<User> users, vector<string> media){
    this->users = users;
    this->media = media;
}

vector<User> Service::getUsers(){
    for(int i = 0; i < users.size(); i++){
        cout << "Name: " << users[i].name << " Email: "<< users[i].email << endl;
    }
    return users;
}

Bill Service::getUserBill(int whom){
    return users[whom - 1].bill;
}

bool Service::getPayment(){
    for(int i = 0; i < users.size(); i++){
        users[i].bill.status = 1;
    }
}

string Service::searchMedia(string needle){
    for(auto i : media){
        if(i == needle){
            return needle;
        }
    }
    return "We don't off this media!";
}