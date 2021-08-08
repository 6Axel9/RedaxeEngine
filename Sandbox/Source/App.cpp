#include <iostream>
#include <Redaxe.h>

class App : public RDX::Application
{
public:
	App() { }
	~App() { }
public:
	RDX::Event OnStart;
	RDX::CustomEvent<int> OnStart2;
};

RDX::Application* RDX::CreateApp()
{
	App* sandbox = new App;
	sandbox->OnStart.AddListener([]() { std::cout << "Started1\n"; });
	sandbox->OnStart.AddListener([]() { std::cout << "Started1\n"; });
	sandbox->OnStart.AddListener([]() { std::cout << "Started1\n"; });
	sandbox->OnStart.AddListener([]() { std::cout << "Started1\n"; });
	sandbox->OnStart.AddListener([]() { std::cout << "Started1\n"; });

	sandbox->OnStart2.AddListener([](int value) { std::cout << "StartedWithParam" << value << "\n"; });
	sandbox->OnStart2.AddListener([](int value) { std::cout << "StartedWithParam" << value << "\n"; });
	sandbox->OnStart2.AddListener([](int value) { std::cout << "StartedWithParam" << value << "\n"; });

	sandbox->OnStart.Invoke();
	sandbox->OnStart2.Invoke(5);
	return sandbox;
}