#include"store.hpp"
#include<iostream>

std::optional<std::string>
Store::get(const std::string& key) const{
    auto it = data.find(key);
    if(it == data.end()){
        return std::nullopt;
    }else{
        return it->second;
    }
}

void Store::del(const std::string& key){
    auto it = data.find(key);
    if(it == data.end()){
        std::cout<<"No such key exist!"<<"\n";
    }else{
        data.erase(key);
    }
}

void Store::set(const std::string& key,const std::string& value){
    data[key] = value;
}
