#pragma once
#include <string>
#include <unordered_set>

struct User {
    int           id;
    std::string name;
    User (const std::string iName,
          const int iId = 0)
        : id{iId}, name{iName} { }
    bool operator ==(const User & obj) const {
        return (name == obj.name);
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
    struct hash<std::unordered_set<User>::iterator> {
    	size_t operator()(const std::unordered_set<User>::iterator &obj) const {
    		  return hash<int>()(obj->id);
    	}
    };
}
