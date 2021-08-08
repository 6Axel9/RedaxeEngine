#include <iostream>
#include <Redaxe.h>

class App : public RDX::Application
{
public:
	App() { std::cout << "Created App Succesfully"; }
	~App() {}
};

RDX::Application* RDX::CreateApp()
{
	return new App;
}