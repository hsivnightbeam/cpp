#pragma once
#include <string>
#include <unordered_set>

//This class defines a User class which has a unique Id, and unique name
struct User {
    int           id;
    std::string name;

    User (const std::string iName,
          const int iId = 0)
        :id{iId}, name{iName} { }

    //operator ==: msg is same as other if name is same: this is as per initial design
    //we could have compare instead id, and then we would allow to user's to have the same name
    //this operator is required as we are saving User is an unordered_set
    bool operator ==(const User & obj) const {
        return (name == obj.name);
    }
};


namespace std
{
    //hash function required as we are saving User is an unordered_set
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
