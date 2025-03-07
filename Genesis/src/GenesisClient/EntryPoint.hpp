#pragma once

#include <GenesisCore/Application.hpp>
#include <GenesisCore/Logger.hpp>

extern ge::Application* ge::createApplication();

int main(int argc, char** argv) {
	ge::Logger::init();

	ge::Application* app = ge::createApplication();
	app->run();
	delete app;
}
