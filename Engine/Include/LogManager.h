#pragma once

#include "ISubscriber.h"
#include "LogManagerMode.h"

#include <memory>
#include <string>


namespace PMgene::Core
{
	class LogManager : public ISubscriber
	{
	public:
		LogManager(LogManagerMode logManagerModeInput);

		void Update();

	private:
		void PrintLog(const std::shared_ptr<Message>& message) const;
		[[nodiscard]] std::string CreatePrefix(const std::shared_ptr<Message>& message) const;
		[[nodiscard]] std::string GetNoteFromMessageGroup(MessageGroup group) const;

		LogManagerMode logManagerMode;
	};
}
