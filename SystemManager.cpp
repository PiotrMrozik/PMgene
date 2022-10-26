#include "SystemManager.h"

namespace PMgene::Core
{
	SystemManager::SystemManager(
		const std::shared_ptr<CommunicationManager>& communicationManagerInput) :
		ISender(communicationManagerInput, "SystemManager")
	{
		messageCodesToSubscribe.emplace_back(MC_ENTITY_DESTROYED);
	}

	template <typename T>
	std::shared_ptr<T> SystemManager::RegisterSystem()
	{
		const char* typeName = typeid(T).name();

		//assert(mSystems.find(typeName) == mSystems.end() && "Registering system more than once.");

		auto system = std::make_shared<T>();
		systems.insert({typeName, system});
		return system;
	}

	template <typename T>
	void SystemManager::SetSignature(EntitySignature signature)
	{
		const char* typeName = typeid(T).name();

		//assert(mSystems.find(typeName) != mSystems.end() && "System used before registered.");

		signatures.insert({typeName, signature});
	}

	void SystemManager::EntityDestroyed(Entity entity)
	{
		for (const auto& pair : systems)
		{
			const auto& system = pair.second;


			system->entities.erase(entity);
		}
	}

	void SystemManager::EntitySignatureChanged(Entity entity, EntitySignature entitySignature)
	{
		for (const auto& pair : systems)
		{
			const auto& type = pair.first;
			const auto& system = pair.second;
			const auto& systemSignature = signatures[type];

			if ((entitySignature & systemSignature) == systemSignature)
			{
				system->entities.insert(entity);
			}
			else
			{
				system->entities.erase(entity);
			}
		}
	}

	void SystemManager::ProcessLastMessage()
	{
		const auto messageToProcess = GetNewestMessage();

		switch (messageToProcess->GetCode())
		{
		case MC_ENTITY_DESTROYED:
		{
			EntityDestroyed(reinterpret_cast<Entity>(messageToProcess->GetFirstArgument()));
			break;
		}
		default:;
		}
	}
}
