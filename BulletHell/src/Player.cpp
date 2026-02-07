#include "Player.h"
#include "raylib.h"
#include <iostream>
#include "raymath.h"

Player::Player(float speed, float radius)
{
	this->speed = speed;
	//this->image = LoadImage(path);
	this->radius = radius;
	//texture = LoadTextureFromImage(image);
	//UnloadImage(image);
}

void Player::Update(int screen_width, int screen_height)
{
	if (!alive)
	{
		return;
	}

	dir = { 0.0f, 0.0f };
	
	if (IsKeyDown(KEY_UP))
	{
		dir.y = -1.0f;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		dir.y = 1.0f;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		dir.x = -1.0f;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		dir.x = 1.0f;
	}

	dir = Vector2Normalize(dir);


	position.x += dir.x * speed * GetFrameTime();
	position.y += dir.y * speed * GetFrameTime();

	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x > screen_width - radius)
	{
		position.x = screen_width - radius;
	}

	if (position.y < 0)
	{
		position.y = 0;
	}
	else if (position.y > screen_height - radius)
	{
		position.y = screen_height - radius;
	}


}

void Player::Draw()
{
	if (!alive)
	{
		return;
	}
	DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, BLUE);
}

void Player::Die()
{
	if (immortal)
	{
		return;
	}
	alive = false;
}

