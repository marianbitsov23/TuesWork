#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Molecule{
    public:
        string name;

        Molecule(){
            name = "";
        }
        Molecule(string name){
            this->name = name;
        }

        virtual void act(vector<Molecule*>& all_molecules, int index) =0;
        virtual void print()=0;
        
};

class PullMolecule : public Molecule{
    public:
        PullMolecule(){
            name = "";
        }

        PullMolecule(string name){
            this->name = name;
        }

        void act(vector<Molecule*>& all_molecules, int index) {
            if(index > 0 && index < all_molecules.size()){
                swap(all_molecules[index -1], all_molecules[index + 1]);
            }
        }

        void print(){
            cout << " Thi is a |PULL|, Name :" << name << endl;
        }
};

class PushMolecule : public Molecule{
    public:
        PushMolecule(){
            name = "";
        }

        PushMolecule(string name){
            this->name = name;
        }

        void act(vector<Molecule*>& all_molecules, int index) {
            if(index > 1 && index < all_molecules.size() - 1){
                swap(all_molecules[index - 1], all_molecules[index - 2]);
                swap(all_molecules[index + 1], all_molecules[index + 2]);
            }
        }

        void print(){
            cout << " Thi is a |PUSH|, Name :" << name << endl;
        }
};

class ConsumeMolecule : public Molecule{
    public:
        int molecules_consumed = 0;

        ConsumeMolecule(){
            name = "";
        }

        ConsumeMolecule(string name){
            this->name = name;
        }

        void act(vector<Molecule*>& all_molecules, int index) {
            if(all_molecules.size() > 0 && index > 0 && index < all_molecules.size()){
                all_molecules.erase(all_molecules.begin() + index);
                molecules_consumed++;
            }
        }

        void print(){
            cout << " Thi is a |Consume|, Name :" << name << endl;
            cout << "molecules_consumed: " << molecules_consumed << endl;
        }    

};

void Reaction(vector<Molecule*> molecules){
    int index = 0;
    
    for(auto i : molecules){
        i->print();
    }

    cout << "------------------------" << endl;

    for(auto i : molecules){
        i->act(molecules, index);
        index++;
        i->print();
    }
}

int main(){

    PullMolecule mol1("Pull");
    PushMolecule mol2("Push");
    ConsumeMolecule mol3("Consume");

    vector<Molecule*> molecules;

    molecules.push_back(&mol1);
    molecules.push_back(&mol2);
    molecules.push_back(&mol3);
    molecules.push_back(&mol1);
    molecules.push_back(&mol2);
    molecules.push_back(&mol3);
    molecules.push_back(&mol1);
    molecules.push_back(&mol2);
    molecules.push_back(&mol3);


    Reaction(molecules);

    return 0;
}
