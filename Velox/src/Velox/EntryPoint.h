#pragma once

#ifdef VX_PLATFORM_WINDOWS

extern Velox::Application* Velox::CreateApplication();

int main(int argc, char** argv)
{
	Velox::Log::Init();
	VX_CORE_WARN("Engine logger initialised!");
	VX_INFO("Client logger initialised!");

	auto app = Velox::CreateApplication();
	app->Run();
	delete app;
}

#endif
