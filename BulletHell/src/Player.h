#pragma once
#include "raylib.h"

class Player
{
private:
	float speed = 25.0f;
	Image image;
	Vector2 dir = { 0.0f, 0.0f };
	int screen_width;
	int screen_height;
	Texture2D texture;

public:
	Vector2 position = { 400.0f, 300.0f };
	bool alive = true;
	bool immortal = false;
	float radius;


public:
	Player(float speed, const char* path, float radius);
	void Update(int screen_width, int screen_height);
	void Draw();
	void Die();

};

