#include "GenesisCore/Core.h"
#include "GenesisClient/Client.h"

int main() {
    ge::Log("RuntimeClient started");

    ge::Client client;
    client.ConnectToServer("127.0.0.1");

    return 0;
}
