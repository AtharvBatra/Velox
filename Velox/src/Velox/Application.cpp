#include "Application.hpp"

#include "Velox/Events/ApplicationEvent.hpp"
#include "Velox/Log.hpp"

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
