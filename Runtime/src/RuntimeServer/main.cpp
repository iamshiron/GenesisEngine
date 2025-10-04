#include "GenesisCore/Core.h"
#include "GenesisServer/Server.h"

int main() {
    ge::Log("RuntimeServer started");

    ge::Server server;
    server.Start();

    return 0;
}
