#include "MessageServiceInterface.h"

bool MessageServiceInterface::ProcessInput() {
	bool ret = false;
	// clear screen
	for (int i = 0; i < 80; ++i) cout << endl;
	// show options
	cout << "Please select an option:" << endl;
	cout << "1. Create User" << endl;
	cout << "2. Send Message" << endl;
	cout << "3. Receive All Messages For User" << endl;
	cout << "4. Report all messages of all senders" << endl;
	cout << "5. Quit" << endl;
	std::string in;
	std::getline(std::cin, in);
	cout << endl;
	if (in == "1")
	{
		cout << "Please enter name: ";
		std::string str;
		std::getline(std::cin, str);
		cout << endl;
		if (msgServiceController.addUser(str) ==  -1)
		{
			cout << "ERROR: User already exists!" << endl;
		} else {
			cout << "User " << str << " added!" << endl;
		}
	} else if (in == "2"){
		cout << "From: ";
		std::string from;
		std::getline(std::cin, from);
		cout << endl;
		if (!msgServiceController.exists(from))
			cout <<"ERROR: User doesn't exist!" << endl;
		else {
			cout << "To: ";
			std::string to;
			std::getline(std::cin, to);
			cout << endl;
			if (!msgServiceController.exists(to))
				cout <<"ERROR: User doesn't exist!" << endl;
			else {
				cout << "Message: ";
				std::string msg;
				std::getline(std::cin, msg);
				cout << endl;
				cout << "Message Sent!" << endl;
				msgServiceController.insert(from, to, msg);
			}
		}
	} else if (in == "3") {
		cout << "Enter name of user to receive all messages for: " << endl;
		std::string user;
		std::getline(std::cin, user);
		cout << endl;
		if (msgServiceController.exists(user) == true)
		{
			cout << endl << "===== BEGIN MESSAGES =====" << endl;
			int num = 0;
			auto searchUserMessages = msgServiceController.getUserReceiveMsgsIndex().find(msgServiceController.find(user));
			if ( searchUserMessages != msgServiceController.getUserReceiveMsgsIndex().end()) {
				for (auto &el : searchUserMessages->second) {
					cout << "Message " << ++num << endl;
					cout << "From: " << el->from->name << endl;
					cout << "Content: " << *el->msgBody << endl << endl;
					el->msgBody.reset();                                                         //message have been read we clear them
				}
				msgServiceController.getUserReceiveMsgsIndex().erase(searchUserMessages);          //also remove the index not required
			}
			cout << endl << "===== END MESSAGES =====" << endl;
		} else
			cout <<"ERROR: User doesn't exist!" << endl;
	} else if (in == "4") {
		for (const auto &el : msgServiceController.getUserSendMsgsIndex()) {
			std::cout << "Sender " << el.first->name << std::endl;
			for (const auto &subEl : el.second) {
				std::cout << subEl->timeStamp << " " << subEl->to->name << std::endl;
			}
		}
	} else if (in == "5") {
		cout << "Quitting!" << endl;
		ret=true;
	} else
	{
		cout << "Invalid Option Selected" << endl;
	}
	cout << endl <<"Enter any key and press return to continue.....";
	std::string str;
	std::getline(std::cin, str);
	return ret;
}

void MessageServiceInterface::terminate()
{
	//for (unsigned int i = 0; i < messages.size(); ++i)
	//	delete messages[i];
}