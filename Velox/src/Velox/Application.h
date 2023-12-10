#pragma once

#include "Core.h"

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

