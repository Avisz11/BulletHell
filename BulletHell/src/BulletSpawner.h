#pragma once
#include <Vector>
#include "Bullet.h"

class BulletSpawner
{

private:
	float rotation = 0.0f;
	float time_since_last_shot = 0.0f;
	bool can_shoot = false;

public:
	float time_between_shots;
	float radius;
	int spawn_points;
	float angle_interval;

	float rotation_speed;

	std::vector<Bullet> bullets;

	Vector2 position = { 400.0f, 300.0f };



public:
	BulletSpawner(float time_between_shots, float radius, int spawn_points, float rotation_speed);
	void Shoot();
	void Update();

	void StartShooting();
	void StopShooting();
};

