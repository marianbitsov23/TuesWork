#include "Song.h"

Song::Song(){}

Song::Song(double counterListened, string header, string auhtor, double price){
    Song::Media(header, author, price);
    this->counterListened = counterListened;
}

double Song::PayPrice(){
    Media::PayPrice();
    return counterListened * price;
}