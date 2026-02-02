#include <iostream>
#include <raylib.h>
#include "Window.h"
#include "Player.h"

int main()
{
	Window window(800, 600, "Bullet Hell");
	Player player(50.0f, "res/Textures/Player.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		player.MovePlayer();

		ClearBackground(window.GetBgColor());
		player.RenderPlayer();

		EndDrawing();
	}

}