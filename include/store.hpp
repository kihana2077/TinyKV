#pragma once

#include<unordered_map>
#include<string>
#include<optional>

class Store{
    public:
        std::optional<std::string> get(const std::string& key) const;

        void del(const std::string& key) const;

        void set(const std::string& key,const std::string& value);
};