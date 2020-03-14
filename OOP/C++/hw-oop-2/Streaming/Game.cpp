#include "Game.h"

Game::Game(){}

Game::Game(double timePlayed, string header, string author, double price){
    Game::Media(header, author, price);
    this->timePlayed = timePlayed;
}

double Game::PayPrice(){
    Media::PayPrice();
    return timePlayed * price;
}