#pragma once
#include <string>
#include <ctime>
#include <memory>

//This class defines a Message class that saves:
//   --msgId
//   --to, and from detail
//   --msgBody
//   --timeStamp
struct Message {
	int                                      msgId;       //we use this field to have a simple hash on Message
	hashSetUser::const_iterator              from;
	hashSetUser::const_iterator              to;
	std::unique_ptr<std::string>             msgBody;
	std::time_t                              timeStamp;
	//Constructor
	Message(      int                         iMsgId,
		          hashSetUser::const_iterator iFrom,
			      hashSetUser::const_iterator iTo,
			const std::string             &iMsgBody)
		:msgId{iMsgId}, from{iFrom}, to{iTo}, msgBody{std::make_unique<std::string>(iMsgBody)}, timeStamp{std::time(nullptr)}
		 { }
    //operator ==: msg is same as other if id is same
	//this operator is required as we are saving User is an unordered_set
	bool operator ==(const Message & obj) const {
        return (msgId == obj.msgId);
    }
	Message (const Message&)            = delete; 
    Message& operator= (const Message&) = delete;
};


namespace std
{
	//hash function required as we are saving User is an unordered_set
    template<>
    struct hash<Message>
    {
        size_t operator()(const Message & obj) const{
            return hash<int>()(obj.msgId);
        }
    };
}
