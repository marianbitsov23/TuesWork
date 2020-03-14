#include <iostream>
using namespace std;

class Point{
public:
    class Line {
        int length;
    public:
        Line(int length){
            this-> length = length;
        }

        void set_lenght(int lenght){
            this -> length;
        }
    };
private:
    double x;
    double y;
    Line l = Line(1);
    const char name = 'a';
    static int count;
public:
    Point(double x, double y, char name) : name(name), x(x), y(y){
        count++;
    }

    Point(double x, double y) : name('c'){
        this->x = x;
        this->y = y;
        count++;
    }

    double getX() const{
        return x;
    }

    Point& setX(double x){
        this->x = x;
        return *this;
    }

    double getY() const{
        return y;
    }

    void setY(double y){
        this->y = y;
    }

    void print() const{
        cout << name << " x:" << x << ", y:" << y << endl;
    }

    static int getCount(){
        return count;
    }


};

void change(Point a, Point& b){
    a.setX(8);
    b.setX(9);
}

int Point::count = 0;

int main(){
    Point a(3, 2);
    Point b(4, 5);
    change(a, b);   
    a.print();
    b.print();

    const Point c(8, 9);
    c.print();

    Point::Line l(5);

    Point d = Point(1, 2, 'Q');
    d.print();

    cout << "Count: " <<Point::getCount() << endl;

    Point e(2, 4, 'e');
    e.setX(8).setY(3);  
    e.print();
    return 0;
}