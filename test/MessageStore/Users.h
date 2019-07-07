#pragma once
#include <string>
#include <unordered_set>

struct User {
    int           id;
    std::string name;
    User (const std::string iName, const int iId): id{iId}, name{iName}{ }
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
    struct hash<User>
    {
      size_t
      operator()(const User & obj) const
      {
        return hash<std::string>()(obj.name);
      }
    };
}

class Users {
public:
    int  addUser(const std::string &userName);
    bool exists(const std::string &userName);
    const std::unordered_set<User>::iterator  find(const std::string &userName);
private:
    std::unordered_set<User> usersDb;

};
