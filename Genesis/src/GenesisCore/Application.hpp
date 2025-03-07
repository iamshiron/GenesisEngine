#pragma once
#include "Defines.hpp"

namespace ge {
	class Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}
