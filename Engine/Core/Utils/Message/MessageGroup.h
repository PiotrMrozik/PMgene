#pragma once

namespace PMgene::Core
{
	typedef enum MessageGroups
	{
		INFO,
		COMMAND,
		WARNING,
		ERROR,

		MessageGroupCount
	}MessageGroup;

	inline const char* to_string(MessageGroup e)
	{
		switch (e)
		{
		case MessageGroup::INFO: return "INFO";
		case MessageGroup::COMMAND: return "COMMAND";
		case MessageGroup::WARNING: return "WARNING";
		case MessageGroup::ERROR: return "ERROR";
		case MessageGroup::MessageGroupCount: return "Count";
		default: return "unknown";
		}
	}
}
