#pragma once

#include "Message.h"

#include <memory>
#include <queue>

namespace PMgene::Core
{
	class ISubscriber
	{
	public:
		virtual ~ISubscriber() = default;
		ISubscriber();

		void PushMessageToQueue(std::shared_ptr<Message> message);

		const std::vector<MessageGroups>& GetMessageGroupsSubscriptions();
		const std::vector<MessageCodes>& GetMessageCodesSubscriptions();

	protected:
		virtual void ProcessLastMessage(){}

		[[nodiscard]] std::shared_ptr<Message> GetNewestMessage();

		std::vector<MessageGroups> messageGroupsToSubscribe;
		std::vector<MessageCodes> messageCodesToSubscribe;
		

	private:

		std::queue<std::shared_ptr<Message>> messageQueue;

		

		
	};
}
