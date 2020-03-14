#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Racer{

public:

    string name;
    int position;
    double speed;

    Racer(){
        name = "";
        position = 0;
        speed = 0;
    }

    Racer(string name, double speed){
        this->name = name;
        this->speed = speed;
        this->position = 0;
    }

    void printRacer(){
        cout << "Name: " << name << ", Position: " << position << ", Speed: " << speed << endl;
    }

    int moveForward(int end){
        
    }

};

class Race{
    vector< vector<Racer> > racers;
    Racer empty;
    vector<Racer> emptyracers;

    public:

    Race(){
        for(int i = 0; i < 3; i++){ 
            racers.push_back(emptyracers);
            for (int j = 0; j < 10; j++){  
               racers.at(i).push_back(empty);
            }
        }
    }

    void addRacer(Racer racer){
        racers.push_back(emptyracers);
        racers.at(racers.size() - 1).push_back(racer);
    }

    void startRace(){
        int counter = 0;
        int i = 0, j = 0, check;
        while(counter != 3){
            int best = 0;
            while(i < racers.size()){
                if(racers[i][j].speed > best){
                    best = racers[i][j].speed;
                    check = i;
                }
                i++;
            }
            counter++;
            racers[check][j].position = counter;
            cout << "Racer " << racers[check][j].name << " finished " << racers[check][j].position << "!" << endl;
            racers.erase(racers.begin() + check);
            i = 0;
        }
    }

};



int main(){
    Racer racer1("ivan", 3);
    Racer racer2("pesho", 5);
    Racer racer3("gosho", 10);

    Race race;

    race.addRacer(racer1);
    race.addRacer(racer2);
    race.addRacer(racer3);
    race.startRace();
}