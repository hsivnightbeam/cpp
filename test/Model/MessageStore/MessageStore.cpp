
#include "MessageStore.h"

void MessageStore::insert(const std::unordered_set<User>::iterator iFrom,
						 const std::unordered_set<User>::iterator iTo,
						 std::string iMsgBody) {
	auto message= make_shared<Message>(id, iFrom, iTo, iMsgBody);
	id++;
	userReceiveMsgsIndex[iTo].push_back(message);
	userSendMsgsIndex[iFrom].insert(message);
}
