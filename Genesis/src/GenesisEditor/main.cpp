#include "GenesisCore/Core.h"
#include <iostream>

int main() {
    ge::Log("--- GENESIS EDITOR ---");
    ge::LogPlatformInfo();
    ge::Log("Editor initialized successfully.");
    ge::Log("(Editor UI and features would go here)");

    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
