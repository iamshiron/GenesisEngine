#include "Server.hpp"

#include <GenesisCore/Logger.hpp>

namespace ge {
    Server::Server() {
        GE_Info("Genesis Server Initialized.");
    }

    Server::~Server() {
        GE_Info("Genesis Server Shutdown.");
    }

    void Server::Start() {
        GE_Info("Server is now listening for connections...");
    }
}
