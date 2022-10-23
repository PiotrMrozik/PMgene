#pragma once
#include <chrono>
#include "Message.h"

namespace PMgene::Core
{
	Message::Message(const MessageGroup inputGroup, const MessageCode inputCode, std::string sender):
		group(inputGroup),
		code(inputCode),
		senderName(std::move(sender))
	{
		timeStamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	}

	MessageGroup Message::GetGroup() const
	{
		return group;
	}

	MessageCodes Message::GetCode() const
	{
		return code;
	}

	time_t Message::GetTimeStamp() const
	{
		return timeStamp;
	}

	const std::string& Message::GetSenderName() const
	{
		return senderName;
	}
}
