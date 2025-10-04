#include "Client.hpp"

#include <GenesisCore/Logger.hpp>
#include "Defines.hpp"

namespace ge {
    Client::Client() {
        GE_Info("Genesis Client Initialized.");
    }

    Client::~Client() {
        GE_Info("Genesis Client Shutdown.");
    }

    void Client::connectToServer(const std::string& serverIp) {
        GE_Info("Attempting to connect to server at: " + serverIp);
        GE_Info("Connection successful! (simulated)");
    }
}
