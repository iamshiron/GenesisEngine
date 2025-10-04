#pragma once

#include <string>

namespace ge {
    class Client {
    public:
        Client();
        ~Client();
        void ConnectToServer(const std::string& serverIp);
    };
}
