#include "Users.h"


int Users::addUser(const std::string &userName) {
    if (usersDb.find(User(userName, 0)) == usersDb.end()) {
        usersDb.insert(User(userName, 0));
        return 0;
    }
    return -1;
}

bool Users::exists(const std::string &userName) {
    if (usersDb.find(User(userName, 0)) == usersDb.end()) {
        return false;
    }
    return true;
}

const std::unordered_set<User>::iterator  Users::find(const std::string &userName) {
    return (usersDb.find(User(userName, 0)));
}
