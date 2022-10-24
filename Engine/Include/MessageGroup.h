#pragma once

namespace PMgene::Core
{
	typedef enum MessageGroups
	{
		MG_INFO,
		MG_COMMAND,
		MG_WARNING,
		MG_ERROR,

		MessageGroupCount
	}MessageGroup;

	inline const char* to_string(MessageGroup e)
	{
		switch (e)
		{
		case MG_INFO: return "MG_INFO";
		case MG_COMMAND: return "MG_COMMAND";
		case MG_WARNING: return "MG_WARNING";
		case MG_ERROR: return "MG_ERROR";
		case MessageGroupCount: return "MessageGroupCount";
		}
		return nullptr;
	}
}
