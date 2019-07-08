#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <set>
#include <ctime>
#include <map>
#include "Users.h"


#include <iostream>

using namespace std;

struct Message;


struct Message {
	int msgId;
	std::unordered_set<User>::const_iterator from;
	std::unordered_set<User>::const_iterator to;
	std::unique_ptr<std::string>             msgBody;
	std::time_t                              timeStamp;

	Message(int iMsgId, std::unordered_set<User>::const_iterator iFrom, std::unordered_set<User>::const_iterator iTo, std::string &iMsgBody)
		:msgId{iMsgId}, from{iFrom}, to{iTo}, msgBody{make_unique<std::string>(iMsgBody)}, timeStamp{std::time(nullptr)}
		{ }
	bool operator ==(const Message & obj) const {
        if (msgId == obj.msgId)
            return true;
        else
            return false;
    }
};

	namespace std
	{
	  template<>
	    struct hash<Message>
	    {
	      size_t
	      operator()(const Message & obj) const
	      {
	        return hash<int>()(obj.msgId);
	      }
	    };

		template<>
		  struct hash<std::unordered_set<User>::const_iterator>
		  {
			size_t
			operator()(const std::unordered_set<User>::const_iterator &obj) const
			{
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
	bool Exists(std::string u);
	//std::vector<std::string> users;

	Users users;
	std::vector<Message*> messages;
	std::unordered_set<Message> messagesDb;
	std::unordered_map<std::unordered_set<User>::const_iterator, std::vector<std::unordered_set<Message>::iterator>> userReceiveMsgsIndex;

	std::map<std::unordered_set<User>::const_iterator,
			           std::set<std::unordered_set<Message>::iterator, compareMessage>,
					   compareUser>   userSendMsgsIndex;

};


/*

bool cmp(int a, int b) {
    return ...;
}
Then use it

std::set<int, decltype(&cmp)> s(&cmp);
std::function<bool (int, int)> numbers;
public:
     Foo () : numbers ([](int x, int y)
                       {
                           return x < y;
                       })
     {
     }*/
