#include <iostream>
#include <raylib.h>
#include "Window.h"
#include "Player.h"
#include "BulletSpawner.h"

int main()
{
	Window window(800, 600, "Bullet Hell");
	Player player(200.0f, "res/Textures/Player.png");
	BulletSpawner spawner(0.2f, 10.0f, 6, 1.5f, Vector2(window.window_width/2, 100));
	spawner.StartShooting();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		

		ClearBackground(window.GetBgColor());

		spawner.Update(window.window_width, window.window_height);

		player.Update(window.window_width, window.window_height);

		EndDrawing();

	}

}