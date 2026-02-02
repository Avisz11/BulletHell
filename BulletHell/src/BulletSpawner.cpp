#include "BulletSpawner.h"
#include "Bullet.h"
#include <raymath.h>

BulletSpawner::BulletSpawner(float time_between_shots, float radius, int spawn_points)
{
	this->time_between_shots = time_between_shots;
	this->radius = radius;
	this->spawn_points = spawn_points;
	
	angle_interval = PI * 2.0f / spawn_points;
}

void BulletSpawner::Shoot()
{
	if (spawn_points <= 0)
	{
		return;
	}

	for (int i = 0; i < spawn_points; i++)
	{
		float angle = angle_interval * i;

		Vector2 dir = { cosf(angle), sinf(angle) };

		Bullet bullet;
		
		bullet.position.x = position.x + radius;
		bullet.position.y = position.y + radius;

		bullet.dir = dir;

		bullets.push_back(bullet);

	}	
}
