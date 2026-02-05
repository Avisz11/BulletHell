#include "BulletSpawner.h"
#include "Bullet.h"
#include <raymath.h>

BulletSpawner::BulletSpawner(float time_between_shots, float radius, int spawn_points, float rotation_speed, Vector2 position)
{
	bullet_sound = LoadSound("res/Sfx/Boom.wav");
	this->time_between_shots = time_between_shots;
	this->radius = radius;
	this->spawn_points = spawn_points;
	this->rotation_speed = rotation_speed;
	this->position = position;

	angle_interval = 0.0f;

}

BulletSpawner::~BulletSpawner()
{
	UnloadSound(bullet_sound);
}

void BulletSpawner::Shoot()

{

	if (spawn_points > 0)
	{
		angle_interval = PI * 2.0f / spawn_points;
	}

	for (int i = 0; i < spawn_points; i++)
	{
		float angle = angle_interval * i + rotation;

		Vector2 dir = { cosf(angle), sinf(angle) };

		Bullet bullet;
		
		bullet.position.x = position.x + dir.x * radius;
		bullet.position.y = position.y + dir.y * radius;

		bullet.dir = dir;

		bullet.speed = bullet_speed;

		bullets.push_back(bullet);

	}
	if(sfx_enabled)
		PlaySound(bullet_sound);

}

void BulletSpawner::Update(int screen_width, int screen_height)
{
	rotation += rotation_speed * GetFrameTime();

	for (auto it = bullets.begin(); it != bullets.end();)
	{
		Bullet& b = *it;

		if (b.position.x > screen_width + b.radius || b.position.x < -b.radius || b.position.y > screen_height + b.radius || b.position.y < -b.radius)
		{
			it = bullets.erase(it); //After b is ereased the iterator will be invalid so setting it to erase will point it to the next
			// so dont increment the iterator
		}
		else
		{
			b.Update();
			++it;
		}
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

void BulletSpawner::DrawBullets()
{
	for (auto& b : bullets)
	{
		b.Draw();
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

void BulletSpawner::SetBulletSpeed(float new_speed)
{
	bullet_speed = new_speed;
	for (auto& b : bullets)
	{
		b.speed = new_speed;
	}
}

void BulletSpawner::SetSpawnPoints(int points)
{
	spawn_points = points;
}
