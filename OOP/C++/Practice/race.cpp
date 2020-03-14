#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class MyException{
    string error;
public:
    MyException(string error_name){
        error = error_name;
    }

    void print_error(){
        cout << error << endl;
    }
};

class Contestant{  
    string name;
    double speed;
public:
    double distance;
    Contestant(){
        name = "";
        speed = 0;
        distance = 0;
    }

    Contestant(string name, double speed){
        if(name.size() == 0){
            throw MyException("Name is empty");
        }
        if(speed <= 0){
            throw MyException("Wrong speed value");
        }
        this->name = name;
        this->speed = speed;
    }

    string getName(){
        return name;
    }

    double getSpeed(){
        return speed;
    }
    
    double getDistance(){
        return distance;
    }

    void calculateDistance(int iteration_count){
        distance = speed * iteration_count;
    }

};


class Race{
    vector<Contestant> contestants;

public:
    Race(){
        contestants = {};
    }

    Race(vector<Contestant> contestants){
        this->contestants = contestants;
    }

    vector<Contestant> getContestants(){
        return contestants;
    }

    void addContestant(Contestant new_contestant){
        contestants.push_back(new_contestant);
    }

    void resetContestants(){
        for(int i = 0; i < contestants.size(); i++){
            contestants[i].distance = 0;
        }
    }

    void simulateRace(int iterations){
        resetContestants();
        cout << "Start of race placements: " << endl << getConstestantStanding() << endl;
        for(int k = 0; k < iterations; k++){
            for(int j = 0; j < contestants.size(); j++){
                contestants[j].calculateDistance(iterations);
            }
            for(int i = 0; i < contestants.size(); i++){
                for(int j = 0; j < contestants.size() - i - 1; j++){
                    if(contestants[j].getDistance() < contestants[j + 1].getDistance()){
                        Contestant temp = contestants[j];
                        contestants[j] = contestants[j + 1];
                        contestants[j + 1] = temp;
                    }
                }
            }
            cout << "Lap" << k + 1 << " placements:" << endl << getConstestantStanding() << endl;
        }
        cout << "End of race placements: " << endl << getConstestantStanding() << endl;

        
    }

    string getConstestantStanding(){
        ostringstream out;
        for(auto i : contestants){
            out << i.getName() << ":" << ' ' << i.getDistance() << "(" << i.getSpeed() << ")" << "\n";
        }
        string info = out.str();
        
        return info;
    }

};

int main(){
    try{
        Contestant one("One", 55);
        Contestant two("Two", 65);
        Contestant three("Three", 35);
        Contestant four("Four", 85);
        Contestant five("Five", 100);
        vector<Contestant> list = {one, two, three, four};
        Race race(list);
        race.addContestant(five);
        race.simulateRace(5);
    }catch(MyException ex){
        ex.print_error();
    }
    return 0;
}