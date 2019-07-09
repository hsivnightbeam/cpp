#pragma once
#include "User.h"
#include <unordered_set>

//This class defines a UserStore class which holds its users in userDb
class UserStore {
public:
    using setUser = std::unordered_set<User>;
    static int id;

    //method that addsUser to db:
    //returns 0 if successfully added, -1 if not (e.g. already exists)
    int                                             addUser(const std::string &userName);

    //method that checks if a userName exists
    //returns true if it does, false if it doesn't
    bool                                            exists (const std::string &userName)  const;

    //method that returns iterator to the userName
    //returns usersDb::end() if it doesn't exist
    const setUser::iterator                         find   (const std::string &userName);
private:
    setUser usersDb;

};
