#pragma once
#pragma warning( disable : 4996)
#include "LogManager.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>

#include "Message.h"


namespace PMgene::Core
{
	LogManager::LogManager(const LogManagerMode logManagerModeInput):
		logManagerMode(logManagerModeInput)
	{
		PrintLog(std::make_shared<Message>(INFO, MC_MANAGER_INITIALIZED, "LogManager"));
	}

	void LogManager::Update()
	{
		if (const std::shared_ptr<Message> messageToProcess = GetNewestMessage())
		{
			PrintLog(messageToProcess);
		}
	}

	void LogManager::PrintLog(const std::shared_ptr<Message>& message) const
	{
		std::string log;
		switch (message->GetCode())
		{
		case MC_ENTITY_CREATED:
			{
				log = CreatePrefix(message) + "Entity created by " + message->GetSenderName();
				break;
			}
		case MC_ENTITY_DESTROYED: break;
		case MC_COMPONENT_REGISTERED: break;
		case MC_COMPONENT_REMOVED: break;
		case MC_COMPONENT_ADDED_TO_ENTITY: break;
		case MC_SYSTEM_REGISTERED: break;
		case MC_SYSTEM_REMOVED: break;
		case MC_MANAGER_INITIALIZED:
			{
				log = CreatePrefix(message) + message->GetSenderName() + " initialized correctly.";

				break;
			}
		case MC_ENTITY_MAX_LIMIT_REACHED:
			{
				log = CreatePrefix(message) + message->GetSenderName() + " cannot create more entities!";
				break;
			}
		case MessageCodesCount:
			{
				log = CreatePrefix(message) + message->GetSenderName() + "Mistakenly send message with wrong code!";
				break;
			}
		}

		switch (logManagerMode)
		{
		case LogManagerMode::CONSOLE:
			{
				std::cout << log << std::endl;
				break;
			}
		case LogManagerMode::GUI:
			{
				break;
			}
		case LogManagerMode::ONSCREEN:
			{
				break;
			}
		}
	}

	std::string LogManager::CreatePrefix(const std::shared_ptr<Message>& message) const
	{
		const auto time = (message->GetTimeStamp());
		const auto local_time = localtime(&time);
		std::ostringstream oss;
		oss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");

		std::string prefix = oss.str() + GetNoteFromMessageGroup(message->GetGroup()) + " ";

		return prefix;
	}

	std::string LogManager::GetNoteFromMessageGroup(MessageGroup group) const
	{
		switch (group)
		{
		case INFO:
			{
				return " \x1B[32m[INFO]\033[0m";
			}
		case COMMAND:
			{
				return " \x1B[34m[COMMAND]\033[0m";
			}
		case WARNING:
			{
				return " \x1B[33m[WARNING]\033[0m";
			}
		case ERROR:
			{
				return " \x1B[31m[ERROR]\033[0m";
			}
		case MessageGroupCount:
			{
				return " \x1B[31m[ERROR]\033[0m";
			}
		}
		return "";
	}
}
