#include <GenesisClient/Client.hpp>
#include <GenesisCore/Core.hpp>
#include <GenesisServer/Server.hpp>
#include <RuntimeCore/Core.hpp>

int main(int argc, char** argv) {
	ge::Core::init();
	ge::Server::init();
	ge::Client::init();
	rt::Core::init();
}
