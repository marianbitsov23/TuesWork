#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
using namespace std;

class Game : public Media{
public:    
double timePlayed;

    Game();
    Game(double timePlayed, string header, string author, double price);

    double PayPrice();
};

#endif
