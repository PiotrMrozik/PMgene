#pragma once
#include "RenderManager.h"

#include "CommunicationManager.h"


namespace PMgene::Core
{
	
	RenderManager::RenderManager(const std::shared_ptr<CommunicationManager>& communicationManagerInput):
		ISender(communicationManagerInput, "RenderManager")
	{
		SendMessage(std::make_shared<Message>(MG_INFO, MC_MANAGER_INITIALIZED, senderName));
	}
}
