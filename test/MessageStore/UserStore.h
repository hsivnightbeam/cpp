#pragma once
#include "User.h"
#include <unordered_set>

class UserStore {
public:
    static int id;
    int                                             addUser(const std::string &userName);
    bool                                            exists(const std::string &userName) const;
    const std::unordered_set<User>::const_iterator  find(const std::string &userName)   const;
private:
    std::unordered_set<User> usersDb;
};
