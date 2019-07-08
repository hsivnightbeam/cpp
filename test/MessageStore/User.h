#pragma once
#include <string>
#include <unordered_set>

struct User {
    int           id;
    std::string name;
    User (const std::string iName, const int iId = 0): id{iId}, name{iName}{ }
    bool operator ==(const User & obj) const {
        if (name == obj.name)
            return true;
        else
            return false;
        }
    };

namespace std
{
    template<>
    struct hash<User> {
        size_t operator()(const User & obj) const {
            return hash<std::string>()(obj.name);
        }
    };

    template<>
    struct hash<std::unordered_set<User>::const_iterator> {
    	size_t operator()(const std::unordered_set<User>::const_iterator &obj) const {
    		  return hash<int>()(obj->id);
    	}
    };
}
