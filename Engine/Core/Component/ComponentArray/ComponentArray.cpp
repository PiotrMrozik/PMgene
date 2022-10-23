#pragma once
#include "ComponentArray.h"

namespace PMgene::Core
{
	template <typename T>
	void ComponentArray<T>::InsertData(Entity entity, T component)
	{
		// Put new entry at end and update the maps
		size_t newIndex = size;
		entityToIndexMap[entity] = newIndex;
		indexToEntityMap[newIndex] = entity;
		componentArray[newIndex] = component;
		++size;
	}

	template <typename T>
	void ComponentArray<T>::RemoveData(Entity entity)
	{
		// Copy element at end into deleted element's place to maintain density
		size_t indexOfRemovedEntity = entityToIndexMap[entity];
		size_t indexOfLastElement = size - 1;
		componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

		// Update map to point to moved spot
		const Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
		entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
		indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

		entityToIndexMap.erase(entity);
		indexToEntityMap.erase(indexOfLastElement);

		--size;
	}

	template <typename T>
	T& ComponentArray<T>::GetData(Entity entity)
	{
		//assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "Retrieving non-existent component.");

		// Return a reference to the entity's component
		return componentArray[entityToIndexMap[entity]];
	}

	template <typename T>
	void ComponentArray<T>::EntityDestroyed(Entity entity)
	{
		if (entityToIndexMap.contains(entity))
		{
			// Remove the entity's component if it existed
			RemoveData(entity);
		}
	}
}
