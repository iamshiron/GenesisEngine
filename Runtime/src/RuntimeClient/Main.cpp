#include <GenesisClient/EntryPoint.hpp>
#include <GenesisCore/Application.hpp>
#include <GenesisCore/Logger.cpp>

class RuntimeClient: public ge::Application {
public:
	RuntimeClient() { GE_Info("RuntimeClient init"); }
	virtual ~RuntimeClient() { GE_Info("RuntimeClient release"); }
};

ge::Application* ge::createApplication() { return new RuntimeClient(); }
