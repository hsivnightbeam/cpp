#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Users.h"


#include <iostream>

using namespace std;


struct Message {
	//std::string from;
	 int msgId;
	 std::unordered_set<User>::const_iterator from;
	//std::string to;
	 std::unordered_set<User>::const_iterator to;
	std::string msg;
	std::unique_ptr<std::string> msgBody;
	Message(int iMsgId, std::unordered_set<User>::const_iterator iFrom, std::unordered_set<User>::const_iterator iTo,
			std::string &iMsgBody):
									msgId{iMsgId}, from{iFrom}, to{iTo}, msgBody{make_unique<std::string>(iMsgBody)}
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

class MessageStore
{
public:

	bool ProcessInput(); // returns true when finished
	void terminate();
	void insert(std::unordered_set<User>::const_iterator iFrom, std::unordered_set<User>::const_iterator iTo,
			std::string iMsgBody) {
			auto ins = messagesDb.insert(Message(id, iFrom, iTo, iMsgBody));
			id++;
			tos[iFrom].push_back(ins.first);
			//tos[ins]++;

	}
	MessageStore(): id(0) { }
private:
	int id;
	bool Exists(std::string u);
	//std::vector<std::string> users;
	Users users;
	std::vector<Message*> messages;
	std::unordered_set<Message> messagesDb;
	std::unordered_map<std::unordered_set<User>::const_iterator, std::vector<std::unordered_set<Message>::iterator>> tos;
};
