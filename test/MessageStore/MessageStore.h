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


namespace std
{
	template<>
	struct hash<std::unordered_set<User>::const_iterator> {
		size_t operator()(const std::unordered_set<User>::const_iterator &obj) const {
		  	return hash<int>()(obj->id);
		}
	};
}

struct compareMessage {
	bool operator()(const std::unordered_set<Message>::iterator &first, const std::unordered_set<Message>::iterator &second) const {
		if(first->to->id != second->to->id ) {
			return (first->to->id < second->to->id);
		} else {
			return (first->timeStamp < second->timeStamp);
		}
	}
};

struct compareUser {
	bool operator()(const std::unordered_set<User>::const_iterator &first, const std::unordered_set<User>::const_iterator &second) const {
		return first->id < second->id;
	}
};

class MessageStore
{
public:

	bool ProcessInput(); // returns true when finished
	void terminate();
	void insert(const std::unordered_set<User>::const_iterator iFrom, const std::unordered_set<User>::const_iterator iTo,
			std::string iMsgBody) {
			auto ins = messagesDb.insert(Message(id, iFrom, iTo, iMsgBody));
			id++;
			userReceiveMsgsIndex[iTo].push_back(ins.first);
			userSendMsgsIndex[iFrom].insert(ins.first);
	}
	MessageStore(): id(0) { }

private:
	int id;
	UserStore users;
	std::vector<Message*> messages;
	std::unordered_set<Message> messagesDb;
	std::unordered_map<std::unordered_set<User>::const_iterator, std::vector<std::unordered_set<Message>::iterator>> userReceiveMsgsIndex;

	std::map<std::unordered_set<User>::const_iterator,
			           std::set<std::unordered_set<Message>::iterator, compareMessage>,
					   compareUser>   userSendMsgsIndex;

};
