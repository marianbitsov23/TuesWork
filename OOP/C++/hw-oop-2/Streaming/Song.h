#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
using namespace std;

class Song : public Media{
public:
    double counterListened;
    
    Song();
    Song(double counterListened, string header, string auhtor, double price);

    double PayPrice();
};

#endif