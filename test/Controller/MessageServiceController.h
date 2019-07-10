#pragma once
#include "UserStore.h"
#include "MessageStore.h"

//Controller receives input, (optionally validates) and then passes the input to the model
class MessageServiceController {
public:
    //Members related to data member users
    int                                             addUser(const std::string &userName)         { return users.addUser(userName); }
    bool                                            exists (const std::string &userName)  const  { return users.exists(userName); }
    const setUser::iterator                         find   (const std::string &userName)         { return users.find(userName); }
    void                                            insert (const std::string &iFrom,
                                                            const std::string &iTo,
			                                                std::string &iMsgBody)               {messages.insert(users.find(iFrom), users.find(iTo), iMsgBody);}

    //Members related to data member messages
          hashUserReciMsg&  getUserReceiveMsgsIndex() { return messages.getUserReceiveMsgsIndex(); }
    const mapUserSentMsg&   getUserSendMsgsIndex   () { return messages.getUserSendMsgsIndex(); }

private:
    UserStore users;
    MessageStore messages;
};
