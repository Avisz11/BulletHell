#include "Bullet.h"
#include "Bullet.h"

Bullet::Bullet()
{
}

void Bullet::Update()
{
	position.x += dir.x * speed * GetFrameTime();
	position.y += dir.y * speed * GetFrameTime();

	DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, RED);
}
