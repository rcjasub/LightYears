#include "EntryPoint.hpp"
#include "framework/Application.hpp"

int main()
{
	ly::Application* app = GetApplication();
	app->Run();
	delete app;
}