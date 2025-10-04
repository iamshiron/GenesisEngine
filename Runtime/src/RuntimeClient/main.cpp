#include <GenesisCore/Logger.hpp>
#include <GenesisClient/Client.hpp>

int main() {
    ge::Logger::init();

    GE_Info("Starting Genesis Client...");

    ge::Client client;
    client.connectToServer("127.0.0.1");

    return 0;
}
