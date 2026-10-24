#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;


void GET(std::unordered_map<std::string,std::string>& db,std::string& key){
    auto it = db.find(key);
    if(it != db.end()){
        std::cout<<it->second<<"\n";
    }else{
        std::cout<<"Invalid Key!"<<"\n";
    }
}

void DEL(std::unordered_map<std::string,std::string>& db,std::string& key){
    if(db.contains(key)){
        db.erase(key);
        std::cout<<"DEL done."<<"\n";
    }else{
        std::cout<<"Invalid Key!"<<"\n";
    }
}

void SET(std::unordered_map<std::string,std::string>& db,std::string& key,std::string& value){
    db[key] = value;
    std::cout<<"SET done."<<"\n";
}


int main(int argc, char const *argv[])
{
    cout<<"KV is running"<<"\n";
    std::unordered_map<std::string,std::string> db;

    db["name"] = "Alice";
    db["age"] = "20";
    db["language"] = "English";

    std::string line;
    std::string command;
    std::string key;
    std::string value;


    while(getline(std::cin,line)){
        if(line == "exit") 
            break;
        std::istringstream iss(line);
        
        if(!(iss >> command)) continue;
        if(command == "GET"){
            if(!(iss >> key)){
                std::cout<<"Parameter key is vacant!"<<"\n";
                continue;
            }
            GET(db,key);
        }else if(command == "DEL"){
            if(!(iss >> key)){
                std::cout<<"Parameter key is vacant!"<<"\n";
                continue;
            }
            DEL(db,key);
        }else if(command == "SET"){
            if(!(iss >> key)){
                std::cout<<"Parameter key is vacant!"<<"\n";
                continue;
            }
            if(!(iss >> value)){
                std::cout<<"Parameter value is vacant!"<<"\n";
                continue;
            }
            SET(db,key,value);
        }else{
            std::cout<<"Invalid command!"<<"\n";
        }
    }

    
    return 0;
}
