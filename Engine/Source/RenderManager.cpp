#pragma once
#include "RenderManager.h"

#include "CommunicationManager.h"


namespace PMgene::Core
{
	
	RenderManager::RenderManager(const std::shared_ptr<CommunicationManager>& communicationManagerInput):
		ISender(communicationManagerInput, "RenderManager")
	{
	}
}
