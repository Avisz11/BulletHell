#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>


#include "Window.h"
#include "Player.h"
#include "BulletSpawner.h"


int main()
{
	Window window(800, 600, "Bullet Hell");

	float speed_slider_val = 50.0f;
	


	Player player(200.0f, "res/Textures/Player.png");

	std::vector<BulletSpawner> spawners;

	//BulletSpawner spawner(0.2f, 10.0f, 6, 1.5f, Vector2(window.window_width/2, 100));

	//spawners.push_back(spawner);


	//spawner.StartShooting();



	bool spawn_mode = false;
	bool ui_disabled = false;


	Rectangle settings_rect = { 0, 0, 300, 200 };


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
			ui_disabled = !ui_disabled;
		}

		if (IsKeyPressed(KEY_V))
		{
			spawn_mode = !spawn_mode;
		}

		if (!CheckCollisionPointRec(GetMousePosition(), settings_rect))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && spawn_mode)
			{
				Vector2 mouse_pos = GetMousePosition();
				spawners.emplace_back(0.2f, 10.0f, 6, 1.5f, mouse_pos);
				spawners.back().StartShooting();
			}
		}
			

		for (auto& s : spawners)
		{
			s.DrawBullets();
			s.SetBulletSpeed(speed_slider_val);
		}

		player.Draw();


		if (!ui_disabled)
		{
			GuiWindowBox(settings_rect, "Properties");

			GuiLabel({ 20, 40, 100, 20 }, "Bullet Velocity");
			GuiSlider({ 20, 60, 200, 20 }, nullptr, "1000", &speed_slider_val, 0.0f, 1000.0f);

			GuiCheckBox({ 20, 90, 20, 20 }, "Spawn Mode (Press V)", &spawn_mode);

			GuiLabel({ 80, 180, 150, 20 }, "Press Y to toggle UI");
		}




		EndDrawing();

	}

}