#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyException{
    string error;
public:
    MyException(string error_code){
        error = error_code;
    }

    void print_error(){
        cout << error << endl;
    }
};

class Dog{
    short age;
    const string name;
public:
    Dog(int age, string dogName) : name(dogName), age(age){
        if(dogName.size() == 0){
            throw MyException("You entered invalid dog name");
        }
        if(age <= 0 || age > 16){
            throw MyException("You entered invalid dog age");
        }        
    }
    short getAge(){
        return age;
    }

    string getName(){
        return name;
    }

};

class Cat{
    short age;
    const string name;
public:
    Cat(int age, string catName) : name(catName), age(age){
        if(catName.size() == 0){
            throw MyException("You entered invalid cat name");
        }
        if(age <= 0 ||age > 30){
            throw MyException("You entered invalid cat age");
        }
    }
    short getAge(){
        return age;
    }

    string getName(){
        return name;
    }
};

class Shelter{

    static vector<Dog> dogs;
    static vector<Cat> cats;
    Shelter(){

    }
public:
    static void addAnimal(string type, string name, short age){
        if(type == "dog"){
            dogs.push_back(Dog(age, name));
        }
        else if(type == "cat"){
            cats.push_back(Cat(age, name));
        }
        else{
            throw MyException("You entered invalid type of animal");
        }
    }

    static void printShelter(){
        cout << "--------Dogs--------" << endl;
        for(auto i : dogs){
            cout << "Kuchenceto " << i.getName() << " e na "<< i.getAge() << endl;
        }
        cout << "--------Cats--------" << endl;
        for(auto i : cats){
            cout << "Kotenceto " << i.getName() << " e na "<< i.getAge() << endl;
        }
    }
};

vector <Dog> Shelter::dogs = {};
vector <Cat> Shelter::cats = {};

int main(){
    try{
        Shelter::addAnimal("dog", "Uvuvwevwevwe onyetenyevwe ugwemuhwem osas", 12);
        Shelter::addAnimal("dog", "Balto Martinez Kueres Porto Riko Mane", 9);
        Shelter::addAnimal("cat", "Pablo Diego José Francisco de Paula Juan Nepomuceno María de los Remedios Cipriano de la Santísima Trinidad Martyr Patricio Clito Ruiz y Picasso", 10);
        Shelter::addAnimal("cat", "Esteban julio ricardo monotoya de la rosa Ramirez", 7);
        Shelter::printShelter();
    }catch (MyException ex){
        ex.print_error();
    }
    return 0;
}
