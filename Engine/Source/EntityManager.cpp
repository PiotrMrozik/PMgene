#include "EntityManager.h"

//#include <memory>

//#include "Globals.h"
//#include "ISender.h"
//#include "CommunicationManager.h"

namespace PMgene::Core
{
	EntityManager::EntityManager(
		const std::shared_ptr<CommunicationManager>& communicationManagerInput):
		ISubscriber(), ISender(communicationManagerInput, "EntityManager")
	{
		// Initialize the queue with all possible entity IDs
		for (unsigned int id = 0; id < MAX_ENTITIES; ++id)
		{
			availableEntities.push(id);
		}

		messageCodesToSubscribe.emplace_back(MC_COMPONENT_ADDED_TO_ENTITY);

		SendMessage(std::make_shared<Message>(MG_INFO, MC_MANAGER_INITIALIZED, senderName));
	}

	Entity EntityManager::CreateEntity()
	{
		if (livingEntityCount >= MAX_ENTITIES)
		{
			SendMessage(std::make_shared<Message>(MG_ERROR, MC_ENTITY_MAX_LIMIT_REACHED, senderName));
			return -1;
		}

		// Take an ID from the front of the queue
		if (!availableEntities.empty())
		{
			const Entity entity = availableEntities.front();
			availableEntities.pop();
			++livingEntityCount;

			//Send Info about creation
			
			return entity;
		}
		return -1;
	}

	void EntityManager::DestroyEntity(const Entity entity)
	{
		signatures[entity].reset();

		// Put the destroyed ID at the back of the queue
		availableEntities.push(entity);
		--livingEntityCount;
		SendMessage(std::make_shared<Message>(MG_INFO, MC_ENTITY_DESTROYED, senderName, (Entity*)entity));
	}

	void EntityManager::SetSignature(const Entity entity, const EntitySignature signature)
	{
		// Put this entity's signature into the array
		signatures[entity] = signature;
	}

	EntitySignature EntityManager::GetSignature(Entity entity) const
	{
		// Get this entity's signature from the array
		return signatures[entity];
	}

	void EntityManager::ProcessLastMessage()
	{
		const auto messageToProcess = GetNewestMessage();

		switch (messageToProcess->GetCode())
		{
		case MC_COMPONENT_ADDED_TO_ENTITY:
			{
			//	const auto entity = reinterpret_cast<Entity>(messageToProcess->GetFirstArgument());
			//	const auto type = reinterpret_cast<ComponentType>(messageToProcess->GetSecondArgument());

			//	EntitySignature signature = GetSignature(entity);
			//	signature.set(type, true);
			//	SetSignature(entity, signature);

			//	SendMessage(std::make_shared<Message>(MG_INFO, MC_ENTITY_SIGNATURE_CHANGED, senderName, (Entity*)entity, &signature));

			}
		default: ;
		}
	}
}
