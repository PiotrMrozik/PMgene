#pragma once
#include "Globals.h"

namespace PMgene::Core
{
	class IComponentArray
	{
	public:
		IComponentArray();
		virtual ~IComponentArray();
		virtual void EntityDestroyed(Entity entity);
	};
	;
}
