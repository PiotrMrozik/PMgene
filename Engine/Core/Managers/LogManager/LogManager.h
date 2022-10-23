#pragma once
#include <memory>
#include <string>

#include "ISubscriber.h"
#include "LogManagerMode.h"
#include "Message.h"
#include "MessageGroup.h"


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
