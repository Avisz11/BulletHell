#pragma once
#include <raylib.h>
class Bullet
{
public:
	Vector2 dir = { 0.0f, 0.0f };
	float speed = 300.0f;
	Vector2 position = { 0.0f, 0.0f };

public:
	Bullet();
	void MoveBullet();
	void RenderBull

};

