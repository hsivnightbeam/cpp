#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <ctime>
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

//This class defines a MessageStore class which holds messages, in two indexes:
//userReceiveMsgsIndex--> Index that lets us find the messages received by a user
//                        When we read the msgs received by a user we delete them from this index, and we also delete the message
//userSendMsgsIndex   --> We store only metadata regarding messages send.
//                        -->It's ordered: by it's key: users with lower id are first (compareUser struct)
//                        -->Also the values (the msgs send by each user) are ordered by recipient id, and timestamp (compareMessage struct)
class MessageStore
{
public:
	void insert(const std::unordered_set<User>::iterator iFrom, const std::unordered_set<User>::iterator iTo,
			std::string iMsgBody);
	std::unordered_map<std::unordered_set<User>::iterator, std::vector<std::shared_ptr<Message>>>  getUserReceiveMsgsIndex() { return userReceiveMsgsIndex; }
	std::map<std::unordered_set<User>::iterator,
			           std::set<std::shared_ptr<Message>, compareMessage>,
					   compareUser> getUserSendMsgsIndex() {return userSendMsgsIndex; }

private:
	static int id;
	std::unordered_map<std::unordered_set<User>::iterator, std::vector<std::shared_ptr<Message>>> userReceiveMsgsIndex;
	std::map<std::unordered_set<User>::iterator,
			           std::set<std::shared_ptr<Message>, compareMessage>,
					   compareUser>   userSendMsgsIndex;

};
