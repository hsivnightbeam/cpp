#include "UserStore.h"

int UserStore::addUser(const std::string &userName) {
    if (usersDb.find(User(userName)) == usersDb.end()) {       //
        usersDb.insert(User(userName, id));
        ++id;
        return 0;
    }
    return -1;
}

bool UserStore::exists(const std::string &userName) const {
    if (usersDb.find(User(userName, 0)) == usersDb.end()) {
        return false;
    }
    return true;
}

const std::unordered_set<User>::const_iterator  UserStore::find(const std::string &userName) const {
    return (usersDb.find(User(userName, 0)));
}
