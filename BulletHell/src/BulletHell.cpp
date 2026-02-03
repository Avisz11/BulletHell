#include <iostream>
#include <raylib.h>
#include "Window.h"
#include "Player.h"
#include "BulletSpawner.h"

int main()
{
	Window window(800, 600, "Bullet Hell");



	Player player(200.0f, "res/Textures/Player.png");

	std::vector<BulletSpawner> spawners;

	//BulletSpawner spawner(0.2f, 10.0f, 6, 1.5f, Vector2(window.window_width/2, 100));

	//spawners.push_back(spawner);


	//spawner.StartShooting();



	bool spawn_mode = false;



	while (!WindowShouldClose())
	{
		BeginDrawing();
		

		ClearBackground(window.GetBgColor());

		//spawner.Update(window.window_width, window.window_height);

		for (auto& s : spawners)
		{
			s.Update(window.window_width, window.window_height);
		}


		player.Update(window.window_width, window.window_height);


		//Spawn mode logic

		if (IsKeyPressed(KEY_Y))
		{
			spawn_mode = !spawn_mode;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && spawn_mode)
		{
			Vector2 mouse_pos = GetMousePosition();
			spawners.emplace_back(0.2f, 10.0f, 6, 1.5f, mouse_pos);
			spawners.back().StartShooting();
		}



		EndDrawing();

	}

}