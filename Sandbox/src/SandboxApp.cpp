#include <Velox.h>

class Sandbox : public Velox::Application
{
public:
	Sandbox()
	{}
	~Sandbox()
	{}
};

Velox::Application* Velox::CreateApplication()
{
	return new Sandbox();
}
