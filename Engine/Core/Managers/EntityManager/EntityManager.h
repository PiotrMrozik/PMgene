#pragma once
#include <array>

#include "CommunicationManager/CommunicationManager.h"
#include "Globals.h"
#include "ISender.h"
#include "ISubscriber.h"


namespace PMgene::Core
{

	class EntityManager : public ISender, public ISubscriber
	{
	public:
		explicit EntityManager(const std::shared_ptr<CommunicationManager>& communicationManagerInput);

		Entity CreateEntity();
		void DestroyEntity(Entity entity);
		void SetSignature(Entity entity, EntitySignature signature);
		[[nodiscard]] EntitySignature GetSignature(Entity entity) const;

	private:
		// Queue of unused entity IDs
		std::queue<Entity> availableEntities{};

		// Array of signatures where the index corresponds to the entity ID
		std::array<EntitySignature, MAX_ENTITIES> signatures{};

		// Total living entities - used to keep limits on how many exist
		uint32_t livingEntityCount{};
	};

}
