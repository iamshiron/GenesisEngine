#pragma once

#include <GenesisCore/Application.hpp>
#include <GenesisCore/Logger.hpp>

extern ge::ClientApplication* ge::createApplication();

int main(int argc, char** argv) {
	ge::Logger::init();

	ge::ClientApplication* app = ge::createApplication();
	app->run();
	delete app;
}
