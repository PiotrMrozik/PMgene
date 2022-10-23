#pragma once
#include <memory>
#include <string>

#include "Message.h"
#include "CommunicationManager/CommunicationManager.h"

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
