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
	InitAudioDevice();

	Window window(800, 600, "Bullet Hell");

	float speed_slider_val = 50.0f;
	int spawn_points = 5;
	int last_spawn_points = spawn_points;
	


	Player player(200.0f, "res/Textures/Player.png");

	std::vector<std::unique_ptr<BulletSpawner>> spawners;

	//BulletSpawner spawner(0.2f, 10.0f, 6, 1.5f, Vector2(window.window_width/2, 100));

	//spawners.push_back(spawner);


	//spawner.StartShooting();



	bool spawn_mode = false;
	bool ui_disabled = false;
	bool sfx_enabled = true;

	int color_index = 0;


	Rectangle settings_rect = { 0, 0, 300, 300 };
	bool color_dropdown_open = false;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		

		ClearBackground(window.GetBgColor());

		//spawner.Update(window.window_width, window.window_height);

		for (auto& s : spawners)
		{
			s->Update(window.window_width, window.window_height);
			s->SetBulletSpeed(speed_slider_val);
			s->sfx_enabled = sfx_enabled;
		}

		if (spawn_points != last_spawn_points)
		{
			for (auto& s: spawners)
			{
				s->SetSpawnPoints(spawn_points);
			}
			last_spawn_points = spawn_points;

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
				spawners.emplace_back(std::make_unique<BulletSpawner>(0.2f, 10.0f, 6, 1.5f, mouse_pos));
				spawners.back()->StartShooting();

				switch (color_index)
				{
					case 0:
						spawners.back()->bullet_color = RED;
						break;
					case 1:
						spawners.back()->bullet_color = GREEN;
						break;
					case 2:
						spawners.back()->bullet_color = BLUE;
						break;
					default:
						std::cout << "[Warning!] index out of bound" << std::endl;
						break;


				}
			
			}
		}
			

		for (auto& s : spawners)
		{
			s->DrawBullets();
		}

		player.Draw();


		if (!ui_disabled)
		{
			GuiWindowBox(settings_rect, "Properties");

			GuiLabel({ 20, 40, 100, 20 }, "Bullet Velocity");
			GuiSlider({ 20, 60, 200, 20 }, "0", "1000", &speed_slider_val, 0.0f, 1000.0f);

			GuiCheckBox({ 20, 90, 20, 20 }, "Spawn Mode (Press V)", &spawn_mode);

			GuiLabel({ 20, 120, 100, 20 }, "Spawn points");
			GuiSpinner({ 20, 140, 200, 20 }, nullptr, &spawn_points, 1, 20, false);

			GuiCheckBox({ 20, 170, 20, 20 }, "SFX Enabled", &sfx_enabled);

			if (GuiDropdownBox({ 20, 200, 200, 20 }, "Red;Green;Blue", &color_index, color_dropdown_open))
			{
				color_dropdown_open = !color_dropdown_open;
			}



			GuiLabel({ 80, 280, 150, 20 }, "Press Y to toggle UI");
			
		}




		EndDrawing();

	}

	CloseAudioDevice();
	CloseWindow();

}