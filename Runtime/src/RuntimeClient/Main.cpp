#include <GenesisClient/Client.hpp>
#include <GenesisCore/Core.hpp>
#include <GenesisServer/Server.hpp>
#include <RuntimeCore/Core.hpp>
#include <iostream>
#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
	ge::Core::init();
	ge::Client::init();
	ge::Server::init();
	rt::Core::init();

	SPDLOG_INFO("Hello, World!");

	std::cin.get();
}
