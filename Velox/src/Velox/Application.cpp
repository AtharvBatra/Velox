#include "Application.h"

#include "Velox/Events/ApplicationEvent.h"
#include "Velox/Log.h"

namespace Velox {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		VX_TRACE(e);

		while (true);
	}

}
