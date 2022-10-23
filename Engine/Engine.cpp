#pragma once
#include "Engine.h"

namespace PMgene
{
	Engine::Engine()
	{
	}

	void Engine::Init()
	{
	}
}

//void InitializeEngine();

//// Link necessary d3d12 libraries.
//#pragma comment(lib,"d3dcompiler.lib")
//#pragma comment(lib, "D3D12.lib")
//#pragma comment(lib, "dxgi.lib")
////#include <d3d12.h>
//
//#include "CommunicationManager/CommunicationManager.h"
//#include "EntityManager/EntityManager.h"
//#include "LogManager/LogManager.h"
//#include "ISubscriber.h"
//
//std::shared_ptr<PMgene::Core::CommunicationManager> gCommunicationManager;
//std::shared_ptr<PMgene::Core::LogManager> gLoggerManager;
//std::shared_ptr<PMgene::Core::EntityManager> gEntityManager;
//
////int main()
//{
//	gCommunicationManager = std::make_shared<PMgene::Core::CommunicationManager>();
//
//
//	//Init LoggerManager
//	gLoggerManager = std::make_shared<PMgene::Core::LogManager>(PMgene::Core::LogManagerMode::CONSOLE);
//	gCommunicationManager->SubscribeToGroup(gLoggerManager, PMgene::MessageGroup::INFO);
//	gCommunicationManager->SubscribeToGroup(gLoggerManager, PMgene::MessageGroup::WARNING);
//	gCommunicationManager->SubscribeToGroup(gLoggerManager, PMgene::MessageGroup::ERROR);
//
//	//Init EntityManager
//	gEntityManager = std::make_shared<PMgene::Core::EntityManager>(gCommunicationManager);
//	gCommunicationManager->SubscribeToGroup(gEntityManager, PMgene::MessageGroup::INFO);
//	
//
//	
//
//
//	bool loopState = false;
//
//
//	
//	while (loopState)
//	{
//		gEntityManager->CreateEntity();
//		gCommunicationManager->SendNextMessageToSubscribers();
//		gLoggerManager->Update();
//	}
//
//	return 0;
//}
//
//
void InitializeEngine()
{
}
