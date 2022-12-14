#pragma once
#include <unordered_map>

#include "IComponentArray.h"

namespace PMgene::Core
{
	template<typename T>
	class ComponentArray : public IComponentArray
	{

	public:
		void InsertData(Entity entity, T component);
		void RemoveData(Entity entity);
		T& GetData(Entity entity);
		void EntityDestroyed(Entity entity) override;

	private:
		// The packed array of components (of generic type T),
		// set to a specified maximum amount, matching the maximum number
		// of entities allowed to exist simultaneously, so that each entity
		// has a unique spot.
		std::array<T, MAX_ENTITIES> componentArray;

		// Map from an entity ID to an array index.
		std::unordered_map<Entity, size_t> entityToIndexMap;

		// Map from an array index to an entity ID.
		std::unordered_map<size_t, Entity> indexToEntityMap;

		// Total size of valid entries in the array.
		size_t size = 0;
	};
;
}

