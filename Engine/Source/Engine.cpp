#pragma once
#include "Engine.h"


namespace PMgene
{
	Engine::Engine()
	{
		Init();
	
	}

	void Engine::Init()
	{
		InitManagers();
	}

	void Engine::PerformGameLoopIteration()
	{

		//entityManager->CreateEntity();
		//communicationManager->SendNextMessageToSubscribers();
		//loggerManager->Update();

	}

	void Engine::InitManagers()
	{
		//Init CommunicationManager
		communicationManager = std::make_shared<Core::CommunicationManager>();

		//Init LoggerManager
		loggerManager = std::make_shared<Core::LogManager>(Core::LogManagerMode::CONSOLE);
		communicationManager->MakeSubscriptions(loggerManager);

		//Init EntityManager
		entityManager = std::make_shared<Core::EntityManager>(communicationManager);

		//Init ComponentManager
		componentManager = std::make_shared<Core::ComponentManager>(communicationManager);
		communicationManager->MakeSubscriptions(componentManager);
	}
}
