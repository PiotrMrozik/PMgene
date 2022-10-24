#pragma once

#include "Message.h"
#include "CommunicationManager.h"

#include <memory>
#include <string>

namespace PMgene::Core
{
	class ISender
	{
	public:
		ISender(std::shared_ptr<CommunicationManager> communicationManagerInput, std::string name);
		void SendMessage(std::shared_ptr<Message> message) const;


	protected:
		std::shared_ptr<CommunicationManager> communicationManager;
		std::string senderName;
	};
}
