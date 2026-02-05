#pragma once
#include <Vector>
#include "Bullet.h"

class BulletSpawner
{

private:
	float rotation = 0.0f;
	float time_since_last_shot = 0.0f;
	bool can_shoot = false;
	float bullet_speed = 300.0f;

	Sound bullet_sound;



public:
	float time_between_shots;
	float radius;
	int spawn_points;
	float angle_interval;
	
	bool sfx_enabled = true;

	float rotation_speed;

	std::vector<Bullet> bullets;

	Vector2 position = { 400.0f, 300.0f };



public:
	BulletSpawner(float time_between_shots, float radius, int spawn_points, float rotation_speed, Vector2 position);
	~BulletSpawner();

	void Shoot();
	void Update(int screen_width, int screen_height);
	void DrawBullets();

	void StartShooting();
	void StopShooting();

	void SetBulletSpeed(float speed);
	void SetSpawnPoints(int points);
};

