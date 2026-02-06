#include "Window.h"
#include "raylib.h"

Window::Window(int window_width, int window_height, const char* window_name)
{
	this->window_width = window_width;
	this->window_height = window_height;


	InitWindow(this->window_width, this->window_height, window_name);

}

Window::Window()
{
	this->window_width = 800;
	this->window_height = 600;
	InitWindow(this->window_width, this->window_height, "Bullet Hell");
}

Window::~Window()
{
	CloseWindow();
}


