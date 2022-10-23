#pragma once
#include <string>
#include "MessageCodes.h"
#include "MessageGroup.h"

namespace PMgene::Core
{
	class Message
	{
	public:
		Message(MessageGroup inputGroup, MessageCode inputCode, std::string sender);

		[[nodiscard]] MessageGroup GetGroup() const;

		[[nodiscard]] MessageCodes GetCode() const;

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
