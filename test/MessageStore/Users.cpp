#include "Users.h"


int Users::addUser(const std::string &userName) {
    if (usersDb.find(User(userName)) == usersDb.end()) {       //
        usersDb.insert(User(userName, id));
        ++id;
        return 0;
    }
    return -1;
}

bool Users::exists(const std::string &userName) const {
    if (usersDb.find(User(userName, 0)) == usersDb.end()) {
        return false;
    }
    return true;
}

const std::unordered_set<User>::const_iterator  Users::find(const std::string &userName) const {
    return (usersDb.find(User(userName, 0)));
}
