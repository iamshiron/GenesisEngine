#include <GenesisCore/Logger.hpp>

#include <GenesisServer/Server.hpp>

int main() {
    GE_Info("RuntimeServer started");

    ge::Server server;
    server.Start();

    return 0;
}
