#pragma once

#include "CommunicationManager.h"
#include "ISender.h"
#include "ISubscriber.h"

namespace PMgene::Core
{
	
	class RenderManager final : public ISubscriber, public ISender
	{
	public:
		RenderManager(const std::shared_ptr<CommunicationManager>& communicationManagerInput);

		

	private:
		
	};


}
