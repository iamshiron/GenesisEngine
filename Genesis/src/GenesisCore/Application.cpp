#include "Application.hpp"

#include "GenesisCore/Logger.hpp"

namespace ge {
	Application::Application() {}

	Application::~Application() {}

	void Application::run() { GE_Info("Application run"); }
}
