#pragma once

#include <string>

namespace ge {
    class Client {
    public:
        Client();
        ~Client();
        void connectToServer(const std::string& serverIp);
    };
}
