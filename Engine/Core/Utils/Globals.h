#pragma once
#include <bitset>

namespace PMgene
{
	using ComponentType = std::uint8_t;
	constexpr ComponentType MAX_COMPONENTS = 4;

	using EntitySignature = std::bitset<MAX_COMPONENTS>;

	using Entity = std::uint32_t;
	constexpr unsigned int MAX_ENTITIES = 10;
}
