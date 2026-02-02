#include "BulletSpawner.h"
#include "Bullet.h"
#include <raymath.h>

BulletSpawner::BulletSpawner(float time_between_shots, float radius, int spawn_points, float rotation_speed)
{
	this->time_between_shots = time_between_shots;
	this->radius = radius;
	this->spawn_points = spawn_points;
	this->rotation_speed = rotation_speed;



	if (spawn_points > 0)
	{
		angle_interval = PI * 2.0f / spawn_points;
	}

}

void BulletSpawner::Shoot()
{
	for (int i = 0; i < spawn_points; i++)
	{
		float angle = angle_interval * i + rotation;

		Vector2 dir = { cosf(angle), sinf(angle) };

		Bullet bullet;
		
		bullet.position.x = position.x + dir.x * radius;
		bullet.position.y = position.y + dir.y * radius;

		bullet.dir = dir;

		bullets.push_back(bullet);

	}	
}

void BulletSpawner::Update()
{
	rotation += rotation_speed * GetFrameTime();

	for (auto &b : bullets)
	{
		b.Update();
	}



	if (can_shoot) {
		time_since_last_shot += GetFrameTime();

		if (time_since_last_shot >= time_between_shots)
		{
			Shoot();
			time_since_last_shot = 0.0f;
		}
	}
}

void BulletSpawner::StartShooting()
{
	can_shoot = true;
}

void BulletSpawner::StopShooting()
{
	can_shoot = false;
}
