#pragma once

#include "CommunicationManager.h"

#include <unordered_set>

namespace PMgene::Core
{
	CommunicationManager::CommunicationManager()
	{
		for (int i = 0; i < static_cast<int>(MessageGroup::MessageGroupCount); i++)
		{
			std::vector<std::shared_ptr<ISubscriber>> groupSubscribers;
			messageGroupsSubscribers.emplace_back(groupSubscribers);
		}
		
		for (int i = 0; i < static_cast<int>(MessageCode::MessageCodesCount); i++)
		{
			std::vector<std::shared_ptr<ISubscriber>> codeSubscribers;
			messageCodesSubscribers.emplace_back(codeSubscribers);
		}
	}

	void CommunicationManager::MakeSubscriptions(const std::shared_ptr<ISubscriber>& subscriber)
	{
		for (const auto messageCode : subscriber->GetMessageCodesSubscriptions())
		{
			messageCodesSubscribers[static_cast<int>(messageCode)].emplace_back(subscriber);
		}

		for (const auto messageGroup : subscriber->GetMessageGroupsSubscriptions())
		{
			messageGroupsSubscribers[static_cast<int>(messageGroup)].emplace_back(subscriber);
		}
		
	}

	void CommunicationManager::SendNextMessageToSubscribers()
	{
		// Check if there is a message to send.
		if (!messageQueue.empty())
		{
			const std::shared_ptr<Message> messageToSend = messageQueue.front();
			messageQueue.pop();

			//Create set of unique subscribers to send messages. This prevent sending message to subscriber of group and code.
			std::unordered_set<std::shared_ptr<ISubscriber>> subscribers;

			// Get ID of collection from MessageGroup enum and then push to set of unique subscribers.
			const int groupID = messageToSend->GetGroup();
			for (const auto& subscriber : messageGroupsSubscribers[groupID])
			{
				subscribers.insert(subscriber);
			}
		
			// Get ID of collection from MessageCode enum and then push to set of unique subscribers.
			const int codeID = messageToSend->GetCode();
			for (const auto& subscriber : messageCodesSubscribers[codeID])
			{
				subscribers.insert(subscriber);
			}
		
			//Send message to all unique subscribers.
			for (const auto& subscriber : subscribers)
			{
				SendMessageToSubscriber(messageToSend, subscriber);
			}
		}
	}
	void CommunicationManager::SendMessageToSubscriber(std::shared_ptr<Message> message, const std::shared_ptr<ISubscriber>& subscriber)
	{
		subscriber->PushMessageToQueue(message);
	}
	void CommunicationManager::PushMessage(const std::shared_ptr<Message>& message)
	{
		messageQueue.push(message);
	}
}
