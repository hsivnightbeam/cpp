#pragma once
#include <string>
#include <vector>
#include "Users.h"

#include <iostream>

using namespace std;

class MessageStore
{
public:

	bool ProcessInput(); // returns true when finished
	void terminate();
private:

	bool Exists(std::string u);
	//std::vector<std::string> users;
	Users users;
	struct Message {
		//std::string from;
		 std::unordered_set<User>::const_iterator from;
		//std::string to;
		 std::unordered_set<User>::const_iterator to;
		std::string msg;
	};
	std::vector<Message*> messages;
};
