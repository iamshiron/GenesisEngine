#include "ClientApplication.hpp"

#include <GenesisCore/Logger.hpp>

namespace ge {
	ClientApplication::ClientApplication() {}

	ClientApplication::~ClientApplication() {}

	void ClientApplication::run() {
		Application::run();
		GE_Info("ClientApplication run");
	}
}
