#include <iostream>
using namespace std;

class Rectangle{
public:
    int x, y;
    int width, height;
    Rectangle(int x, int y, int width, int height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    
    Rectangle& operator+=(int value){
        this->x += value;
        this->y += value;
        this->width += value;
        this->width += value;
        return *this; 
    }

    void print_rectangle(){
        cout << "x:" << x << ", y:" << y << "\nwidth:" << width << ", height:" << height << endl;
    }
};

Rectangle operator+(const Rectangle rectangle, int value){
    Rectangle result = Rectangle(rectangle.x + value, rectangle.y + value, rectangle.height + value, rectangle.height + value);
    return result;
}

Rectangle operator+(const Rectangle r1, const Rectangle r2){
    int r1x = 0, r1y = 0, r1height = 0, r1width = 0;
    int r2x = 0, r2y = 0, r2height = 0, r2width = 0;
    int width, height;
    r1x = r1.x;
    r1y = r1.y;
    r2x = r2.x;
    r2y = r2.y;
    r1width = r1.x + r1.width;
    r1height = r1.y + r2.height;
    r2width = r2.x + r2.width;
    r2height = r2.y + r2.height;
    r1x = min(r1x, r2x);
    r1y = min(r1y, r2y);
    width = max(r1width, r2width) - r1x;
    height = max(r1height, r2height) - r1y;
    Rectangle result = Rectangle(r1x, r1y, width, height);
    return result; 
}

int main(){
    Rectangle r1 = Rectangle(1, 2, 3, 4);
    r1 + 1;
    r1.print_rectangle();
    Rectangle r2 = Rectangle(2, 3, 2, 2);
    Rectangle r3 = Rectangle(3, 4, 2, 2);

    Rectangle r4 = r2 + r3;
    r4.print_rectangle();

    return 0;
}