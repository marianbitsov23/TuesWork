#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Brackets{
    vector<char> all_brackets;
    vector<int> type_brackets;
    bool equal;
    int open_br = 0;
    int close_br = 0;
    
    public:

    string read_line(){
        string str;
        getline(cin, str);
        return str;
    }

    void countBrackets(string str){

        for(int i  = 0; str[i] != '\0'; i++){
            if(str[i] == '('){
                open_br++;
                all_brackets.push_back(str[i]);
                type_brackets.push_back(1);
            }
            else if(str[i] == ')'){
                close_br++;
                all_brackets.push_back(str[i]);
                type_brackets.push_back(2);
            }
        }
        
    };

    void print_scheme(){
        for(int i = 0; i < all_brackets.size(); i++){
            cout << all_brackets[i] << "->";
            if(type_brackets[i] == 1){
                cout << "opening" << endl;
            } 
            else if(type_brackets[i] == 2){
                cout << "closing" << endl;
            }
        }
        cout << endl;
    }
    //(()())
    //012345
    bool checkBrackets(string str){
        int k = 0;
        int i = 0;

        if(open_br == close_br){
            while(i < all_brackets.size()){
                if(type_brackets[i] == 1){
                    while(k < all_brackets.size()){
                        if(type_brackets[k] == 2){
                            type_brackets.erase(type_brackets.begin() + k);
                            cout << type_brackets[k] << endl; 
                            break;
                        }
                        k++;
                    }
                    if(k == all_brackets.size()){
                        return false;
                    }
                    type_brackets.erase(type_brackets.begin() + i);
                    i++;
                }
                else{
                    return false;
                }
                
            }
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Brackets brackets;
    string str_in = brackets.read_line();
    brackets.countBrackets(str_in);
    brackets.print_scheme();
    cout << brackets.checkBrackets(str_in) << endl;
    return 0;
}