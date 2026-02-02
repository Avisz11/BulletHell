#pragma once
#include <raylib.h>
class Bullet
{

private:
	float radius = 5.0f;

public:
	Vector2 dir = { 0.0f, 0.0f };
	float speed = 300.0f;
	Vector2 position = { 0.0f, 0.0f };

public:
	Bullet();
	void Update();

};

