#pragma once

#include "Velox/Core.hpp"
#include "Velox/Events/Event.hpp"

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

