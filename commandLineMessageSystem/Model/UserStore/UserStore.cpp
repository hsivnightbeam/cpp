#include "UserStore.h"

int UserStore::addUser(const std::string &userName)
{
    if (!exists(userName)) {       //
        usersDb.insert(User(userName, id));
        ++id;
        return 0;
    }
    return -1;
}

bool UserStore::exists(const std::string &userName) const
{
    return (usersDb.find(User(userName, 0)) != usersDb.end());
}

const hashSetUser::iterator  UserStore::find(const std::string &userName)
{
    return (usersDb.find(User(userName, 0)));
}
