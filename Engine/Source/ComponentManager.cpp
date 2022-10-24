#pragma once
#include "ComponentManager.h"

#include "ComponentArray.h"

#include <memory>
#include <Globals.h>

namespace PMgene::Core
{
	template <typename ComponentType>
	template <typename T>
	void ComponentManager<ComponentType>::RegisterComponent()
	{
		const char* typeName = typeid(T).name();

		//assert(mComponentTypes.find(typeName) == mComponentTypes.end() && "Registering component type more than once.");

		// Add this component type to the component type map
		componentTypes.insert({ typeName, nextComponentType });

		// Create a ComponentArray pointer and add it to the component arrays map
		componentArrays.insert({ typeName, std::make_shared<ComponentArray<T>>() });

		// Increment the value so that the next component registered will be different
		++nextComponentType;
	}

	template <typename ComponentType>
	template <typename T>
	ComponentType ComponentManager<ComponentType>::GetComponentType()
	{
		const char* typeName = typeid(T).name();

		//assert(mComponentTypes.find(typeName) != mComponentTypes.end() && "Component not registered before use.");

		// Return this component's type - used for creating signatures
		return componentTypes[typeName];
	}

	template <typename ComponentType>
	template <typename T>
	void ComponentManager<ComponentType>::AddComponent(Entity entity, T component)
	{
		// Add a component to the array for an entity
		GetComponentArray<T>()->InsertData(entity, component);
	}

	template <typename ComponentType>
	template <typename T>
	void ComponentManager<ComponentType>::RemoveComponent(Entity entity)
	{
		// Remove a component from the array for an entity
		GetComponentArray<T>()->RemoveData(entity);
	}

	template <typename ComponentType>
	template <typename T>
	T& ComponentManager<ComponentType>::GetComponent(Entity entity)
	{
		// Get a reference to a component from the array for an entity
		return GetComponentArray<T>()->GetData(entity);
	}

	template <typename ComponentType>
	void ComponentManager<ComponentType>::EntityDestroyed(Entity entity)
	{
		// Notify each component array that an entity has been destroyed
		// If it has a component for that entity, it will remove it
		for (auto const& pair : componentArrays)
		{
			auto const& component = pair;

			component->EntityDestroyed(entity);
		}
	}

	template <typename ComponentType>
	template <typename T>
	std::shared_ptr<ComponentArray<T>> ComponentManager<ComponentType>::GetComponentArray()
	{
		const char* typeName = typeid(T).name();

		//assert(mComponentTypes.find(typeName) != mComponentTypes.end() && "Component not registered before use.");

		return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
	}
}
