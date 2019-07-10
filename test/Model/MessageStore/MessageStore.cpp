
#include "MessageStore.h"

void MessageStore::insert(const  setUser::iterator iFrom,
						  const  setUser::iterator iTo,
						  const  std::string       &iMsgBody)
{
	auto message = make_shared<Message>(id, iFrom, iTo, iMsgBody);
	id++;
	userReceiveMsgsIndex[iTo].push_back(message);
	userSendMsgsIndex[iFrom].insert(message);
}
