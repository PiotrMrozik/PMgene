#pragma once

#include "Message.h"

#include <chrono>

namespace PMgene::Core
{


	Message::Message(MessageGroup inputGroup, MessageCode inputCode, std::string sender):
		group(inputGroup),
		code(inputCode),
		senderName(std::move(sender))
	{
		timeStamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	}

	
	Message::Message(MessageGroup inputGroup, MessageCode inputCode, std::string sender, void* argument) :
		group(inputGroup),
		code(inputCode),
		senderName(std::move(sender)),
		firstArgument(argument)
	{
		timeStamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	}

	
	Message::Message(MessageGroup inputGroup, MessageCode inputCode, std::string sender, void* argument1, void* argument2) :
		group(inputGroup),
		code(inputCode),
		senderName(std::move(sender)),
		firstArgument(argument1),
		secondArgument(argument2)
	{
		timeStamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	}

	
	MessageGroup Message::GetGroup() const
	{
		return group;
	}

	
	MessageCode Message::GetCode() const
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

	
	void* Message::GetFirstArgument()
	{
		return firstArgument;
	}

	
	void* Message::GetSecondArgument()
	{
		return secondArgument;
	}
}
