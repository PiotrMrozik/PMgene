#pragma once
#include "ISubscriber.h"

#include "Message.h"


namespace PMgene::Core
{
	ISubscriber::ISubscriber() = default;

	std::shared_ptr<Message> ISubscriber::GetNewestMessage()
	{
		if (!messageQueue.empty())
		{
			std::shared_ptr<Message> messageToProcess = messageQueue.front();
			messageQueue.pop();
			return messageToProcess;
		}
		return nullptr;
	}

	void ISubscriber::GetMessage(std::shared_ptr<Message> message)
	{
		messageQueue.push(message);
	}
}
