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
			auto message= make_shared<Message>(id, iFrom, iTo, iMsgBody);
			id++;
			userReceiveMsgsIndex[iTo].push_back(message);
			userSendMsgsIndex[iFrom].insert(message);
	}
	MessageStore(): id(0) { }

private:
	int id;
	UserStore users;
	std::vector<Message*> messages;
	std::unordered_set<Message> messagesDb;
	std::unordered_map<std::unordered_set<User>::const_iterator, std::vector<std::shared_ptr<Message>>> userReceiveMsgsIndex;
	std::map<std::unordered_set<User>::const_iterator,
			           std::set<std::shared_ptr<Message>, compareMessage>,
					   compareUser>   userSendMsgsIndex;

};
