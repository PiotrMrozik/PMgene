#pragma once
#include "ISender.h"

#include <memory>
#include <string>

#include "Message.h"
#include "CommunicationManager/CommunicationManager.h"

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
