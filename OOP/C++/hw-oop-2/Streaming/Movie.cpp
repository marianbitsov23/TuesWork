#include "Movie.h"

Movie::Movie(){}

Movie::Movie(double lenght, double watched, string header, string auhtor, double price){
    Movie::Media(header, author, price);
    this->lenght = lenght;
    this->watched = watched;
}

double Movie::PayPrice(){
    Media::PayPrice();
    return watched * price;
}