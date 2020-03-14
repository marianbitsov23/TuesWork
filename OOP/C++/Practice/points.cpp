#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    string toString(){
        ostringstream out;

        out << "(" << x << "," << y << ")"; 

        string info = out.str(); 
        
        return info;
    }
};

class CollectionPoints{
private:
    vector<Point> points;

public:
    void readPoints(string points_in){
        istringstream in(points_in);
        char temp;
        int x, y;
        in >> temp >> x >> temp >> y;
        if(in.good()){
            cout << "It went gud! SMAAAAAAAART MOE" << endl;
            points.push_back(Point(x, y));
        }
        else{
            cout << "Something went bad" << endl;
        }

        if(in.eof()){
            cout << "This is the end!" << endl;
        }

    }

    string print_points(){
        ostringstream out;

        for(int i = 0; i < points.size(); i++){
            out << points[i].toString() << "\n";
        }

        string finale = out.str();

        return finale;
    }

};

int main(){
    Point p1 = Point(4, 2);
    Point p2 = Point(3, 2);
    CollectionPoints points1;
    points1.readPoints(p1.toString());
    points1.readPoints(p2.toString());
    cout << points1.print_points() << endl;

    return 0;
}