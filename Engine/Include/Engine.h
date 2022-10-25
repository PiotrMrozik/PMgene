#pragma once
#include <memory>

#include "CommunicationManager.h"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "LogManager.h"
#include "PMath.h"

namespace PMgene
{

	class Engine
	{
	public:

		Engine();

		void Init();

		void PerformGameLoopIteration();

	private:

		void InitManagers();

		std::shared_ptr<Core::CommunicationManager> communicationManager;
		std::shared_ptr<Core::LogManager> loggerManager;
		std::shared_ptr<Core::EntityManager> entityManager;
		std::shared_ptr<Core::ComponentManager> componentManager;
	};
}
