#pragma once

#include "Velox/Core.h"
#include "Velox/Events/Event.h"

namespace Velox {
	
	class VELOX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}

