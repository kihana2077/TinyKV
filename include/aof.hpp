#pragma once

#include<string>
#include<fstream>

class Aof{
    public:
        explicit Aof(const std::string& path);
        bool append(const std::string& command);
    private:
        std::ofstream file;
};