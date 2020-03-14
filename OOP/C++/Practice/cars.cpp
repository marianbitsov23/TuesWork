#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class SmallSize{};
class ModelNoName{};
class SmallBrandName{};
class ModelAlreadyIn{};
class IndexTooBig{};

class CarCatalogue{
private: 
    string producer;
    vector<string> models;
    

public:   

    CarCatalogue(){
        producer = "";
        models = {};
    }

    CarCatalogue(string brand, vector<string> starter){
        if(starter.size() < 5){
            throw SmallSize();
        }
        if(brand.length() < 5){
            throw SmallBrandName();
        }
        producer = brand;
        models = starter;
    }

    string getBrand(){
        return producer;
    }

    vector<string> getModels(){
        return models;
    }

    int hasModel(string model_name){   
        for(int i = 0; i < models.size(); i++){
            if(models[i] == model_name){
                return 1;
            }
        }
        return 0;
    }

    void addModel(string model_name){
        if(model_name.empty()){
            throw ModelNoName();
        }
        if(hasModel(model_name) == 1){
            throw ModelAlreadyIn();
        }
        models.push_back(model_name);
    }

    string toString(){
        ostringstream out;

        out << "<" << producer << ">" << "\n";
        for(int i = 0; i < models.size(); i++){
            out << "  <" << models[i] << ">" << "\n";
        }

        string info = out.str();

        return info;

    }

    void removeModelAt(int index){
        if(index > models.size()){
            throw IndexTooBig();
        }
        models.erase(models.begin() + index);
    }

    void replaceModealAt(int index, string model_name){
        if(index > models.size()){
            throw IndexTooBig();
        }
        if(model_name.empty()){
            throw ModelNoName();
        }
        if(hasModel(model_name) == 1){
            throw ModelAlreadyIn();
        }
        models[index] = model_name;

    }

};

int main(){

    CarCatalogue catalogue;
    try{
        string brand = "Volkswagen";
        vector<string> model;

        model.push_back("Caddy");
        model.push_back("Caravele");
        model.push_back("Touareg");
        model.push_back("Sirocco");
        model.push_back("Golf");
        model.push_back("Arteon");

        catalogue = CarCatalogue(brand, model);
    
    }catch(SmallSize ex){
        cout << "Collection size too small!" << endl;
    }catch(ModelNoName ex){
        cout << "Model with no name!" << endl;
    }catch(SmallBrandName ex){
        cout << "Small brand name!" << endl;
    }

    catalogue.getBrand();

    try{
        catalogue.addModel("Sirocco");  
    }catch(ModelAlreadyIn ex){
        cout << "This model already contains in colection!" << endl;
    }catch(ModelNoName ex){
        cout << "This model has no name!" << endl;
    }

    cout << catalogue.toString() << endl;

    try{
        catalogue.removeModelAt(4);
    }catch(IndexTooBig ex){
        cout << "Not found index!" << endl;
    }

    try {
        catalogue.replaceModealAt(0, "Qko mi e");
    }catch(IndexTooBig ex){
        cout << "Not found index!" << endl;
    }catch(ModelAlreadyIn ex){
        cout << "This model already contains in colection!" << endl;
    }catch(ModelNoName ex){
        cout << "This model has no name!" << endl;
    }

    cout << catalogue.toString() << endl;

    return 0;

}