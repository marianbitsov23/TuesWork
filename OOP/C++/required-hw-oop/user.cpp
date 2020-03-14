#include "user.h"

User::User(){
    id = 0;
    username = "basic";
    password = "basicpassword";
}

User::User(unsigned int id, string username, string password){
    this->id = id;
    this->username = username;
    this->password = password;
}

void User::print_info(){
    cout << "Id: " << id << " Name: " << username << " Password: " << password << endl;
}