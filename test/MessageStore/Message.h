#pragma once
#include <string>
#include <memory>

struct Message {
	int msgId;
	std::unordered_set<User>::const_iterator from;
	std::unordered_set<User>::const_iterator to;
	std::unique_ptr<std::string>             msgBody;
	std::time_t                              timeStamp;

	Message(int iMsgId, std::unordered_set<User>::const_iterator iFrom,
			std::unordered_set<User>::const_iterator iTo,
			std::string &iMsgBody)
		:msgId{iMsgId}, from{iFrom}, to{iTo}, msgBody{std::make_unique<std::string>(iMsgBody)}, timeStamp{std::time(nullptr)}
		{ }
	bool operator ==(const Message & obj) const {
        return (msgId == obj.msgId);
    }
};


namespace std
{
    template<>
    struct hash<Message>
    {
        size_t operator()(const Message & obj) const{
            return hash<int>()(obj.msgId);
        }
    };
}
