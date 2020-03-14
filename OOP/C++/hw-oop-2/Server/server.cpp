#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> users = {"Gosho" , "Lucho", "Martin"};

class Request{
public:
    string IP;
    string gateway;
    string extra;

    Request(){}

    Request(string IP, string gateway){
        this->IP = IP;
        this->gateway = gateway;
    }

    void addExtra(string extra){
        this->extra = extra;
    }
};


class Response{
public:
    int status;
    string text;

    Response(){}
    
    Response* handleRequest(Request* req){
        if(req->gateway[0] != '/'){
            cout << "error" << endl;
            return NULL;
        }
        else if(req->gateway.find(".html") != string::npos){
            string result;
            string htmlstart = "<html>";
            string htmlend = "</html>";
            for(int i = 1; req->gateway[i] != '.' ; i++){
                status = 200;
                result += req->gateway[i]; 
            }
            text = htmlstart + result + htmlend;
            return this;
        }
        else if(req->gateway.find("/api") != string::npos){
            if(req->gateway.find("/login") != string::npos){
                for(int i = 0; i < users.size(); i++){
                    if(req->extra == users[i]){
                        status = 200;
                        text = "OK";
                        return this;
                    }
                }
                status = 403;
                text = "Unauthorized";
                return this;
            }
            else if(req->gateway.find("/get_users") != string::npos){
                text = "[";
                for(auto i : users){
                    text += "," + i; 
                }
                text += "]";
                status = 1;
                return this;
            }
        }
    }

    void printResponse(){
        cout << text << endl << status << endl;
    }
};

Response routeRequest(Request* req){
    Response response;
    
    response.handleRequest(req);
    
    return response;
}

class Server{
    vector<Request> requests;

public:
    Server(){}
    Server(vector<Request> requests){
        this->requests = requests;
    }

    void handleAllRequests(){
        for(auto i : requests){
            Response response = routeRequest(&i);
            cout << response.text << endl << response.status << endl << endl;
        }
    }

};


int main(){
    Request req1("123:2143;", "/login.html");
    Request req2("4353655:89", "/home.html");
    Request req3("56789op", "/api/get_users");
    req3.addExtra("Gosho");

    vector<Request> requests;
    
    requests.push_back(req1);
    requests.push_back(req2);
    requests.push_back(req3);

    Server server(requests);
    server.handleAllRequests();


    return 0;
}
