#pragma once
#include "MessageCodes.h"
#include "MessageGroup.h"


#include <string>

namespace PMgene::Core
{
	class Message
	{
	public:
		Message(MessageGroup inputGroup, MessageCode inputCode, std::string sender);
		Message();

		[[nodiscard]] MessageGroup GetGroup() const;

		[[nodiscard]] MessageCode GetCode() const;

		[[nodiscard]] time_t GetTimeStamp() const;

		[[nodiscard]] const std::string& GetSenderName() const;

	private:
		MessageGroup group;
		MessageCode code;
		time_t timeStamp;
		std::string senderName;
	};

	//TODO template it bitch!

	//template<typename T>
	//class Message : public IMessage
	//{
	//	T messageType;
	//};
}
