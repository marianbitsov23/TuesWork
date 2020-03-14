#include "Media.h"

Media::Media(){}

Media::Media(string header, string author, double price){
    this->header = header;
    this->author = author;
    this->price = price;
}

double Media::PayPrice(){
    cout << "Header: " << header << ", Author: " << author << ", Price: " << price << endl;
}