#pragma once
#include <set>
#include "Globals.h"

namespace PMgene::Core
{
	class ISystem
	{
	public:
		void Update();

		std::set<Entity> entities;
	};
}
