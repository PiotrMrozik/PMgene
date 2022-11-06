#pragma once
#include <memory>

#include "CommunicationManager.h"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "LogManager.h"
#include "PMath.h"
#include "RenderManager.h"
#include "SystemManager.h"

// Link necessary d3d12 libraries.
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")


namespace PMgene
{

	class Engine
	{
	public:

		Engine();

		void Init();

		void PerformGameLoopIteration();

	private:

		void InitManagers();

		// Entity methods
		Entity CreateEntity() const;

		void DestroyEntity(Entity entity);


		// Component methods
		template<typename T>
		void RegisterComponent();

		template<typename T>
		void AddComponent(Entity entity, T component);

		template<typename T>
		void RemoveComponent(Entity entity);

		template<typename T>
		T& GetComponent(Entity entity);
		template<typename T>
		ComponentType GetComponentType();


		// System methods
		template<typename T>
		std::shared_ptr<T> RegisterSystem();

		template<typename T>
		void SetSystemSignature(EntitySignature signature);


		std::shared_ptr<Core::CommunicationManager> communicationManager;
		std::shared_ptr<Core::EntityManager> entityManager;
		std::shared_ptr<Core::ComponentManager> componentManager;
		std::shared_ptr<Core::SystemManager> systemManager;
		std::shared_ptr<Core::RenderManager> renderManager;

		std::shared_ptr<Core::LogManager> loggerManager;
	};

	
}
