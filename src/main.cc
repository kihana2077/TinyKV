#include<iostream>
#include<string>
#include<sstream>
#include"store.hpp"


// void GET(std::unordered_map<std::string,std::string>& db,std::string& key){
//     auto it = db.find(key);
//     if(it != db.end()){
//         std::cout<<it->second<<"\n";
//     }else{
//         std::cout<<"None."<<"\n";
//     }
// }

// void DEL(std::unordered_map<std::string,std::string>& db,std::string& key){
//     auto it = db.find(key);
//     if(it != db.end()){
//         db.erase(key);
//         std::cout<<"DEL done."<<"\n";
//     }else{
//         std::cout<<"Invalid Key!"<<"\n";
//     }
// }

// void SET(std::unordered_map<std::string,std::string>& db,std::string& key,std::string& value){
//     db[key] = value;
//     std::cout<<"SET done."<<"\n";
// }


int main(void)
{
    std::cout<<"KV is running"<<"\n";
    Store store;

    std::string line;
    while(getline(std::cin,line)){

        std::string command;
        std::string key;
        std::string value;

        if(line == "exit") 
            break;
        std::istringstream iss(line);
        
        if(!(iss >> command)) continue;
        if(command == "GET"){
            if(!(iss >> key)){
                std::cout<<"Parameter key is vacant!"<<"\n";
                continue;
            }
            if(iss >> value){
                std::cout<<"GET with an unexpected parameter!"<<"\n";
                continue;
            }
            auto result = store.get(key);
            std::cout<<*result<<"\n";
        }else if(command == "DEL"){
            if(!(iss >> key)){
                std::cout<<"Parameter key is vacant!"<<"\n";
                continue;
            }
            if(iss >> value){
                std::cout<<"DEL with an unexpected parameter!"<<"\n";
                continue;
            }
            store.del(key);
            std::cout<<"del done."<<"\n";
        }else if(command == "SET"){
            if(!(iss >> key)){
                std::cout<<"Parameter key is vacant!"<<"\n";
                continue;
            }
            if(!(iss >> value)){
                std::cout<<"Parameter value is vacant!"<<"\n";
                continue;
            }
            store.set(key,value);
            std::cout<<"set done."<<"\n";
        }else{
            std::cout<<"Invalid command!"<<"\n";
        }
    }

    return 0;
}
