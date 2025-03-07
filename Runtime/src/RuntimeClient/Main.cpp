#include <GenesisClient/ClientApplication.hpp>
#include <GenesisClient/EntryPoint.hpp>
#include <GenesisClient/event/KeyEvent.hpp>
#include <GenesisClient/event/MouseEvent.hpp>
#include <GenesisClient/event/WindowEvent.hpp>
#include <GenesisCore/Logger.cpp>

class RuntimeClient: public ge::ClientApplication {
public:
	RuntimeClient() {
		GE_Info("RuntimeClient init");

		ge::Event* e = new ge::MouseMovedEvent(24, 71);

		GE_Info(e->getName());
		delete e;
	}
	virtual ~RuntimeClient() { GE_Info("RuntimeClient release"); }
};

ge::ClientApplication* ge::createApplication() { return new RuntimeClient(); }
