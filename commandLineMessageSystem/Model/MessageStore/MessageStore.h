#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include "UserStore.h"
#include "Message.h"

#include <iostream>

using namespace std;

struct compareMessage {
	bool operator()(const std::shared_ptr<Message> &first, const std::shared_ptr<Message> &second) const {
		if(first->to->id != second->to->id ) {
			return (first->to->id < second->to->id);
		} else {
			return (first->timeStamp < second->timeStamp);
		}
	}
};

struct compareUser {
	bool operator()(const std::unordered_set<User>::iterator &first, const std::unordered_set<User>::iterator &second) const {
		return first->id < second->id;
	}
};

using vectMsg =  std::vector<std::shared_ptr<Message>>;
using setMsg  =  std::set<std::shared_ptr<Message>, compareMessage>;
using hasMaphUserReciMsg = std::unordered_map<hashSetUser::iterator, vectMsg>;
using mapUserSentMsg  = std::map<hashSetUser::iterator, setMsg, compareUser>;
//This class defines a MessageStore class which holds messages, in two indexes:
//userReceiveMsgsIndex--> Index that lets us find the messages received by a user
//                        When we read the msgs received by a user we delete them from this index, and we also delete the message
//userSendMsgsIndex   --> We store only metadata regarding messages send.
//                        -->It's ordered: by it's key: users with lower id are first (compareUser struct)
//                        -->Also the values (the msgs send by each user) are ordered by recipient id, and timestamp (compareMessage struct)
class MessageStore
{
public:
	void                   insert                 (const hashSetUser::iterator iFrom,
				                                   const hashSetUser::iterator iTo,
			                                       const std::string       &iMsgBody);
	      hasMaphUserReciMsg& getUserReceiveMsgsIndex()                                   {return userReceiveMsgsIndex; }
	const mapUserSentMsg&     getUserSendMsgsIndex   ()                                   {return userSendMsgsIndex; }

private:
	static int id;
	hasMaphUserReciMsg userReceiveMsgsIndex;
	mapUserSentMsg  userSendMsgsIndex;

};
