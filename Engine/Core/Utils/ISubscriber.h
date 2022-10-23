#pragma once
#include <memory>
#include <queue>

#include "Message.h"

namespace PMgene::Core
{
	class ISubscriber
	{
	public:
		ISubscriber();
		std::shared_ptr<Message> GetNewestMessage();

		void GetMessage(std::shared_ptr<Message> message);

	private:
		std::queue<std::shared_ptr<Message>> messageQueue;
	};
}
