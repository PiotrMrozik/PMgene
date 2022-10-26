#pragma once
#include "ComponentManager.h"

#include "ComponentArray.h"

#include <memory>
#include <Globals.h>

namespace PMgene::Core
{
	ComponentManager::ComponentManager(
		const std::shared_ptr<CommunicationManager>& communicationManagerInput) :
		ISender(communicationManagerInput, "ComponentManager")
	{
		messageCodesToSubscribe.emplace_back(MC_ENTITY_DESTROYED);
	}

	ComponentManager::~ComponentManager()
	{
	}

	void ComponentManager::ProcessLastMessage()
	{
		const auto messageToProcess = GetNewestMessage();

		switch (messageToProcess->GetCode())
		{
		case MC_ENTITY_DESTROYED: 
		{
			//EntityDestroyed();
			break;
		}
		default: ;
		}
	}

	void ComponentManager::EntityDestroyed(Entity entity)
	{
		// Notify each component array that an entity has been destroyed
		// If it has a component for that entity, it will remove it
		for (const auto& pair : componentArrays)
		{
			const auto& component = pair.second;
			component->EntityDestroyed(entity);
			//component->EntityDestroyed(entity);
		}
	}

	template <typename T>
	void ComponentManager::RegisterComponent()
	{
		const char* typeName = typeid(T).name();

		//assert(mComponentTypes.find(typeName) == mComponentTypes.end() && "Registering component type more than once.");

		// Add this component type to the component type map
		componentTypes.insert({typeName, nextComponentType});

		// Create a ComponentArray pointer and add it to the component arrays map
		componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

		// Increment the value so that the next component registered will be different
		++nextComponentType;
	}

	template <typename T>
	ComponentType ComponentManager::GetComponentType()
	{
		const char* typeName = typeid(T).name();

		//assert(mComponentTypes.find(typeName) != mComponentTypes.end() && "Component not registered before use.");

		// Return this component's type - used for creating signatures
		return componentTypes[typeName];
	}

	template <typename T>
	void ComponentManager::AddComponent(Entity entity, T component)
	{
		// Add a component to the array for an entity
		GetComponentArray<T>()->InsertData(entity, component);
	}

	template <typename T>
	void ComponentManager::RemoveComponent(Entity entity)
	{
		// Remove a component from the array for an entity
		GetComponentArray<T>()->RemoveData(entity);
	}

	template <typename T>
	T& ComponentManager::GetComponent(Entity entity)
	{
		// Get a reference to a component from the array for an entity
		return GetComponentArray<T>()->GetData(entity);
	}

	template <typename T>
	std::shared_ptr<ComponentArray<T>> ComponentManager::GetComponentArray()
	{
		const char* typeName = typeid(T).name();

		//assert(mComponentTypes.find(typeName) != mComponentTypes.end() && "Component not registered before use.");

		return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
	}
}
