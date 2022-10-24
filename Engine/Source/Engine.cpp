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
	//	//Init CommunicationManager
		communicationManager = std::make_shared<Core::CommunicationManager>();

	//	//Init LoggerManager
		loggerManager = std::make_shared<Core::LogManager>(Core::LogManagerMode::CONSOLE);
		communicationManager->SubscribeToGroup(loggerManager, Core::MessageGroup::MG_INFO);
		communicationManager->SubscribeToGroup(loggerManager, Core::MessageGroup::MG_WARNING);
		communicationManager->SubscribeToGroup(loggerManager, Core::MessageGroup::MG_ERROR);

	//	//Init EntityManager
		entityManager = std::make_shared<Core::EntityManager>(communicationManager);
		communicationManager->SubscribeToGroup(entityManager, Core::MessageGroup::MG_INFO);
	}
}

//void InitializeEngine();

//// Link necessary d3d12 libraries.
//#pragma comment(lib,"d3dcompiler.lib")
//#pragma comment(lib, "D3D12.lib")
//#pragma comment(lib, "dxgi.lib")
////#include <d3d12.h>

