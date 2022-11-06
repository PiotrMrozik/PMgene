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
		communicationManager->SendNextMessageToSubscribers();
		loggerManager->Update();

		communicationManager->SendNextMessageToSubscribers();
		loggerManager->Update();

		auto entity = CreateEntity();
		communicationManager->SendNextMessageToSubscribers();
		loggerManager->Update();

		auto entity2 = CreateEntity();
		communicationManager->SendNextMessageToSubscribers();
		loggerManager->Update();

		entityManager->DestroyEntity(entity);
		communicationManager->SendNextMessageToSubscribers();
		loggerManager->Update();
		
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

		//Init SystemManager
		systemManager = std::make_shared<Core::SystemManager>(communicationManager);
		communicationManager->MakeSubscriptions(systemManager);

		//Init RenderManager
		renderManager = std::make_shared<Core::RenderManager>(communicationManager);
		communicationManager->MakeSubscriptions(renderManager);
	}


#pragma region ECS functions
	// ------ECS functions------

	Entity Engine::CreateEntity() const
	{
		const auto entity = entityManager->CreateEntity();
		communicationManager->PushMessage(std::make_shared<Core::Message>(Core::MG_INFO, Core::MC_ENTITY_CREATED, "EntityManager", (Entity*)entity));
		return entity;
	}

	void Engine::DestroyEntity(Entity entity)
	{
		entityManager->DestroyEntity(entity);

		componentManager->EntityDestroyed(entity);

		systemManager->EntityDestroyed(entity);
		communicationManager->PushMessage(std::make_shared<Core::Message>(Core::MG_INFO, Core::MC_ENTITY_DESTROYED, "EntityManager", (Entity*)entity));
	}

	template <typename T>
	void Engine::RegisterComponent()
	{
		componentManager->RegisterComponent<T>();
		communicationManager->PushMessage(std::make_shared<Core::Message>(Core::MG_INFO, Core::MC_COMPONENT_REGISTERED, "ComponentManager", (char*)typeid(T).name()));
	}

	template <typename T>
	void Engine::AddComponent(Entity entity, T component)
	{
		componentManager->AddComponent<T>(entity, component);

		auto signature = entityManager->GetSignature(entity);
		signature.set(componentManager->GetComponentType<T>(), true);
		entityManager->SetSignature(entity, signature);

		systemManager->EntitySignatureChanged(entity, signature);

		communicationManager->PushMessage(std::make_shared<Core::Message>(Core::MG_INFO, Core::MC_COMPONENT_ADDED_TO_ENTITY, "ComponentManager", (char*)typeid(T).name(), (Entity*)entity));

	}

	template <typename T>
	void Engine::RemoveComponent(Entity entity)
	{
		componentManager->RemoveComponent<T>(entity);

		auto signature = entityManager->GetSignature(entity);
		signature.set(componentManager->GetComponentType<T>(), false);
		entityManager->SetSignature(entity, signature);

		systemManager->EntitySignatureChanged(entity, signature);

		communicationManager->PushMessage(std::make_shared<Core::Message>(Core::MG_INFO, Core::MC_COMPONENT_REMOVED_FROM_ENTITY, "ComponentManager", (char*)typeid(T).name(), (Entity*)entity));

	}

	template <typename T>
	T& Engine::GetComponent(Entity entity)
	{
		return componentManager->GetComponent<T>(entity);
	}

	template <typename T>
	ComponentType Engine::GetComponentType()
	{
		return componentManager->GetComponentType<T>();
	}

	template <typename T>
	std::shared_ptr<T> Engine::RegisterSystem()
	{
		return systemManager->RegisterSystem<T>();
	}

	template <typename T>
	void Engine::SetSystemSignature(EntitySignature signature)
	{
		systemManager->SetSignature<T>(signature);
	}

	// ------ECS functions------
#pragma endregion

}
