#pragma once
#include "ISender.h"

#include "Message.h"
#include "CommunicationManager.h"

#include <memory>
#include <string>

namespace PMgene::Core
{
	ISender::ISender(
		std::shared_ptr<CommunicationManager> communicationManagerInput,
		std::string name):
		communicationManager(communicationManagerInput),
		senderName(std::move(name))
	{
	}

	void ISender::SendMessage(std::shared_ptr<Message> message) const
	{
		communicationManager->PushMessage(std::move(message));
	}
}
