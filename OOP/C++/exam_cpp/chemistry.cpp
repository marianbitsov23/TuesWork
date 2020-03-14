#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Exception{
    string error;
public:    
    Exception(string info){
        error = info;
    }

    void print_error(){
        cout << error << endl;
    }

};

class Result{
public:
    string formula;
    float original_capacity;
    float effiency;

    Result(string formula, float original_capacity, float effiency){
        this->formula = formula;
        this->original_capacity = original_capacity;
        this->effiency = effiency;
    }

    float getLoss(){
        return original_capacity * (1 - effiency);
    }

};

class ResultCatalogue{
    vector<Result> results;
public:

    ResultCatalogue(){
        results = {};
    }

    ResultCatalogue(vector<Result> results){
        this->results = results;
    }

    vector<Result> getResults(){
        return results;
    }

    void addResult(Result newResult){
        if(newResult.formula.size() == 0){
            throw Exception("Formula no name");
        }
        if(newResult.original_capacity < 0){
            throw Exception("Negative value");
        }
        if(newResult.effiency < 0 || newResult.effiency > 1){
            throw Exception("Invalid effiency value");
        }
        results.push_back(newResult);
    }

    void sortByLoss(){
    	if(results.size() == 0){
    		throw Exception("Catalogue is empty");
    	}
        for(int i = 0; i < results.size(); i++){
            for(int j = 0; j < results.size() - i - 1; j++){
                if(results[j].getLoss() > results[j + 1].getLoss()){
                    Result temp = results[j];
                    results[j] = results[j + 1];
                    results[j + 1] = temp;
                }
            }
        }
    }

    string toString(){
        ostringstream out;
        for(int i = 0; i < results.size(); i ++){
            out << "Formula:" << i + 1 << " ~ Size:" << results[i].getLoss() << " ~ Efficiency:" << results[i].effiency << "\n";
        }
        string info = out.str();
        return info;
    }


};

int main(){
    Result one("1", 10, 0.2);
    Result two("2", 20, 0.1);
    Result three("3", 40, 0.6);
    Result four ("2", 5, 0.2);
    vector<Result> results;
    results.push_back(one);
    results.push_back(two);
    results.push_back(three);
    try{
        ResultCatalogue catalogue(results);
        cout << catalogue.toString();
        catalogue.addResult(four);
        cout << "Adding 4th element....." << endl;
        cout << catalogue.toString();
    }catch(Exception ex){
        ex.print_error();
    }

    return 0;
}