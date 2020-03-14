#include <iostream>
using namespace std;

class Point{
    double x;
    double y;
    public:
    Point(){};
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    double getX() const{
        return x;
    }

    void setX(double x){
        this->x = x;
    }

    double getY() const{
        return y;
    }

    void setY(double y){
        this->y = y;
    }

    Point& add(const Point p){
        x += p.getX();
        y += p.getY();
        return *this;
    }

    Point& sub(const Point p){
        x -= p.getX();
        y -= p.getY();
        return *this;
    }

    Point& mul(const int alpha){
        x *= alpha;
        y *= alpha;
        return *this;
    }

    Point operator+(const Point p){
        Point result = Point(x + p.getX(), y + p.getY());
        return result;
    }

    void operator*(const Point p){
        x *= p.getX();
        y *= p.getY();
    }

    
};

ostream& operator<<(ostream& out, const Point p){
    out << "point (" << p.getX() << " , " << p.getY() << ")" << endl;
    return out;
}

istream& operator>>(istream& in, Point result){
    string line;
    getline(in, line);
    return in;
}

Point operator-(const Point p1, const Point p2){
    Point result = Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
    return result;
}

Point operator-(const Point p){
    Point result = Point(-p.getX(), -p.getY());
    return result;
}

void printPoint(Point p){
    cout << "point (" << p.getX() << " , " << p.getY() << ")" << endl;
}

int main(){
    Point p1 = Point(1, 2);
    Point p2 = Point(2, 3);

    p1.add(p2).sub(p2).mul(2);

    Point p3 = p1 + p2;

    printPoint(p3);

    Point p4 = p1 - p2;

    printPoint(p4);

    Point p5 = Point(1, 3);
    p5 * p1;    

    printPoint(p5);

    cout << "p5: "<< p5 << "p4: "<<  p4;

    return 0;
}