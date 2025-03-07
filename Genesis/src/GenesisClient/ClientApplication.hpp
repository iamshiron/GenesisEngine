#pragma once
#include "Defines.hpp"

#include <GenesisCore/Application.hpp>

namespace ge {
	class ClientApplication: Application {
	public:
		ClientApplication();
		virtual ~ClientApplication();

		void run();
	};

	ClientApplication* createApplication();
}
