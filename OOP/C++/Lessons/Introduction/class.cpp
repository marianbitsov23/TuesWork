#include <iostream>
using namespace std;

class Point { 	
	private:
	int x = 4;
	int y;

	public:
	Point (int x_, int y_){
		this->x = x_;
		this->y = y_;
	};

	int getX(){
		return x;
	};

	int getY();

};

int Point::getY(){
	return y;
};

int main(){
	Point p = Point(9, 10);
	Point* p1 =  &p;
	cout << "X: " << p1->getX() << endl << "Y: " << p1->getY() << endl;
}