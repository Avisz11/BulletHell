#include "Player.h"
#include <raylib.h>
#include <raymath.h>

Player::Player(float speed, const char* path)
{
	this->speed = speed;
	this->image = LoadImage(path);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
}

void Player::Update()
{
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

	DrawTexture(texture, static_cast<int>(position.x), static_cast<int>(position.y), WHITE);

}

