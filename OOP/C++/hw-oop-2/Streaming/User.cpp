#include "User.h"

User::User(){}

User::User(string name, string email, vector<string> usedMedia, Bill bill){
    this->name = name;
    this->email = email;
    this->usedMedia = usedMedia;
    this->bill = bill;
}