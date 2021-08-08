#include <iostream>
#include <Redaxe.h>

class App : public rdx::Application
{
public:
	App() { }
	~App() { }
};

rdx::Application* rdx::CreateApp()
{
	App* sandbox = new App;
	return sandbox;
}