#include "GenesisServer/Server.h"
#include "GenesisCore/Core.h"

namespace ge {
    Server::Server() {
        Log("Genesis Server Initialized.");
    }

    Server::~Server() {
        Log("Genesis Server Shutdown.");
    }

    void Server::Start() {
        Log("Server is now listening for connections...");
        Log("(In a real implementation, this would enter a network loop)");
    }
}
