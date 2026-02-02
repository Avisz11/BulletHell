#include <iostream>
#include <raylib.h>
#include "Window.h"

int main()
{
	Window window(800, 600, "Bullet Hell");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(window.GetBgColor());
		EndDrawing();
	}

}