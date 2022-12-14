#pragma once

#include "Globals.h"
#include "ComponentArray.h"

#include <memory>
#include <unordered_map>

#include "ISender.h"
#include "ISubscriber.h"

namespace PMgene::Core
{
	
	class ComponentManager final : public ISubscriber, public ISender
	{
	public:
		ComponentManager(const std::shared_ptr<CommunicationManager>& communicationManagerInput);

		~ComponentManager() override;

		template <typename T>
		void RegisterComponent();

		template <typename T>
		ComponentType GetComponentType();

		template <typename T>
		T& GetComponent(Entity entity);

		void EntityDestroyed(Entity entity);

	private:
		// Map from type string pointer to a component type
		std::unordered_map<const char*, ComponentType> componentTypes{};

		// Map from type string pointer to a component array
		std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays{};

		// The component type to be assigned to the next registered component - starting at 0
		ComponentType nextComponentType{};

		void ProcessLastMessage() override;

		template <typename T>
		void AddComponent(Entity entity, T component);

		template <typename T>
		void RemoveComponent(Entity entity);

		

		template <typename T>
		std::shared_ptr<ComponentArray<T>> GetComponentArray();		
	};


}
