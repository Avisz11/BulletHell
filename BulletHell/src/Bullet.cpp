#include "Bullet.h"
#include "Bullet.h"

Bullet::Bullet()
{
}

void Bullet::MoveBullet()
{
	position.x += dir.x * speed * GetFrameTime();
	position.x += dir.y * speed * GetFrameTime();
}
