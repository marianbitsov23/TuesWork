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

class StudentInfo{
    string name;
    vector<double> marks;

public:

    StudentInfo(){
        name = "";
        marks = {};
    }

    StudentInfo(string name, vector<double> marks){
        if(name.size() < 5){
            throw MyException("Invalid name");
        }
        if(marks.size() > 10){
            throw MyException("Collection is bigger than 10");
        }
        for(auto i : marks){
            if(i < 2 || i > 6){
                throw MyException("Invalid marks");
            }
        }
        this->name = name;
        this->marks = marks;
    }

    string getName(){
        return name;
    }

    vector<double> getMarks(){
        return marks;
    }

    void addMark(double new_mark){
        if(marks.size() >= 10){
            throw MyException("Already 10 in collection");
        }
        if(new_mark < 2 || new_mark > 6){
            throw MyException("Invalid marks");
        }      
        marks.push_back(new_mark);
    }

    double getAverage(){
        double sum = 0;
        for(auto i : marks){
            sum += i;
        }
        return sum/ marks.size();
    }

    string toString(){
        ostringstream out;
        out << name << ":" << ' ';
        for(auto i : marks){
            out << i << ' ';
        }
        out <<"[ " << getAverage() << " ]";
        string info = out.str();

        return info; 
    }
};

int main(){
    try{
        vector<double> grades = {3, 4, 6, 6, 5, 6};
        StudentInfo student("Mariyan Bitsov", grades);
        student.addMark(4);
        cout << student.toString() << endl;
    }catch(MyException e){
        e.print_error();
    }
    return 0;
}