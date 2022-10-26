#pragma once

#include "ISubscriber.h"

#include <memory>

namespace PMgene::Core
{
	class CommunicationManager
	{
	public:

		CommunicationManager();

		void MakeSubscriptions(const std::shared_ptr<ISubscriber>& subscriber);

		void SendNextMessageToSubscribers();


		void SendMessageToSubscriber(std::shared_ptr<Message> message, const std::shared_ptr<ISubscriber>& subscriber);

		void PushMessage(const std::shared_ptr<Message>& message);

	private:

		std::queue<std::shared_ptr<Message>> messageQueue;

		std::vector<std::vector<std::shared_ptr<ISubscriber>>> messageGroupsSubscribers;
		std::vector<std::vector<std::shared_ptr<ISubscriber>>> messageCodesSubscribers;

		
	};
}
