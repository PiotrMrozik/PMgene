#pragma once

#include "ISubscriber.h"

#include <memory>

namespace PMgene::Core
{
	class CommunicationManager
	{
	public:
		CommunicationManager();

		void SubscribeToGroup(const std::shared_ptr<ISubscriber>& subscriber, MessageGroup group);

		void SubscribeToCode(const std::shared_ptr<ISubscriber>& subscriber, MessageCode code);

		void SendNextMessageToSubscribers();

		void SendMessageToSubscriber(std::shared_ptr<Message> message, const std::shared_ptr<ISubscriber>& subscriber);

		void PushMessage(const std::shared_ptr<Message>& message);

	private:
		std::queue<std::shared_ptr<Message>> messageQueue;

		std::vector<std::vector<std::shared_ptr<ISubscriber>>> messageGroupsSubscribers;
		std::vector<std::vector<std::shared_ptr<ISubscriber>>> messageCodesSubscribers;

		
	};
}
