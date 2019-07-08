#pragma once
#include "UserStore.h"
#include "MessageStore.h"

//Controller receives input, (optionally validates) and then passes the input to the model
class MessageServiceController {
public:
    //Members related to users member
    int                                             addUser(const std::string &userName)         { return users.addUser(userName); }
    bool                                            exists (const std::string &userName)  const  { return users.exists(userName); }
    const std::unordered_set<User>::iterator        find   (const std::string &userName)         { return users.find(userName); }
    void insert(const std::string &iFrom,
                const std::string &iTo,
			    std::string &iMsgBody) {
        messages.insert(users.find(iFrom), users.find(iTo), iMsgBody);
    }

    //Members related to messages member
    std::unordered_map<std::unordered_set<User>::iterator, std::vector<std::shared_ptr<Message>>>  getUserReceiveMsgsIndex() { return messages.getUserReceiveMsgsIndex(); }
    std::map<std::unordered_set<User>::iterator,
                       std::set<std::shared_ptr<Message>, compareMessage>,
                       compareUser> getUserSendMsgsIndex() {return messages.getUserSendMsgsIndex(); }

private:
    UserStore users;
    MessageStore messages;
};
