#pragma once
#include <unordered_map>

#include "CommunicationManager.h"
#include "Globals.h"
#include "ISender.h"
#include "ISubscriber.h"
#include "ISystem.h"


namespace PMgene::Core
{
	class SystemManager : public ISubscriber, public ISender
	{
	public:
		SystemManager(const std::shared_ptr<CommunicationManager>& communicationManagerInput);

		template <typename T>
		std::shared_ptr<T> RegisterSystem();

		template <typename T>
		void SetSignature(EntitySignature signature);

		void EntityDestroyed(Entity entity);

		void EntitySignatureChanged(Entity entity, EntitySignature entitySignature);
		

	private:
		// Map from system type string pointer to a signature
		std::unordered_map<const char*, EntitySignature> signatures{};

		// Map from system type string pointer to a system pointer
		std::unordered_map<const char*, std::shared_ptr<ISystem>> systems{};

		void ProcessLastMessage() override;
	};
}
