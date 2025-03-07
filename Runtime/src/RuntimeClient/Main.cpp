#include <GenesisClient/Client.hpp>
#include <GenesisCore/Logger.hpp>
#include <GenesisServer/Server.hpp>
#include <RuntimeCore/Core.hpp>
#include <iostream>
#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
	ge::core::Logger::init();

	ge::Client::init();
	ge::Server::init();
	rt::Core::init();

	GE_Info("Info Log");
	GE_Warn("Warn Log");
	GE_Error("Error Log");
	GE_Fatal("Fatal Log");

	std::cin.get();
}
