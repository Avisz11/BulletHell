#pragma once
#include <raylib.h>
class Bullet
{

public:
	float radius = 5.0f;
	Vector2 dir = { 0.0f, 0.0f };
	float speed = 300.0f;
	Vector2 position = { 0.0f, 0.0f };
	

public:
	Bullet();
	void Update();
	void Draw(Color color);
	~Bullet();

};

