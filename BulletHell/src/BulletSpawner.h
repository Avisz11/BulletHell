#pragma once
#include <Vector>
#include "Bullet.h"

class BulletSpawner
{

public:
	float time_between_shots;
	float radius;
	int spawn_points;
	float angle_interval;
	std::vector<Bullet> bullets;

	Vector2 position = { 400.0f, 300.0f };



public:
	BulletSpawner(float time_between_shots, float radius, int spawn_points);
	void Shoot();
};

