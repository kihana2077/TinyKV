#include"aof.hpp"

Aof::Aof(const std::string& path){
    file.open(path,std::ios::out | std::ios::app);
}

bool Aof::append(const std::string& command){
    if(!file.is_open()){
        return false;
    }
    file << command<<"\n";
    return static_cast<bool>(file);
}