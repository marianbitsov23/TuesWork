#include "Book.h"

Book::Book(){}

Book::Book(string header, string auhtor, double price){
    Book::Media(header, author, price);
}

double Book::PayPrice(){
    Media::PayPrice();
}