#pragma once

namespace PMgene::Core
{
	typedef enum MessageCodes
	{

		MC_ENTITY_CREATED				,
		MC_ENTITY_DESTROYED				,
		MC_ENTITY_MAX_LIMIT_REACHED	,

		MC_COMPONENT_REGISTERED			,
		MC_COMPONENT_REMOVED			,
		MC_COMPONENT_ADDED_TO_ENTITY	,

		MC_SYSTEM_REGISTERED			,
		MC_SYSTEM_REMOVED				,

		MC_MANAGER_INITIALIZED			,

		MessageCodesCount
		

	}MessageCode;


}
