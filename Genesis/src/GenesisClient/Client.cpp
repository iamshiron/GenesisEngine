#include "GenesisClient/Client.h"
#include "GenesisCore/Core.h"

namespace ge {
    Client::Client() {
        Log("Genesis Client Initialized.");
    }

    Client::~Client() {
        Log("Genesis Client Shutdown.");
    }

    void Client::ConnectToServer(const std::string& serverIp) {
        Log("Attempting to connect to server at: " + serverIp);
        Log("Connection successful! (simulated)");
    }
}
