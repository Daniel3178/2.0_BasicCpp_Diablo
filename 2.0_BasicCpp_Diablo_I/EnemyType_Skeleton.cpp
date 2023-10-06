#include "EnemyType_Skeleton.h"
#include "Player.h"

namespace diablo_I
{
	Skeleton::Skeleton()
	{
		attackDamage = 5;
		hp = 150;
		enemyWeakness = Enemy_Tag::ENEMY_WEAKNESS_SKELETON;
		enemyType = Enemy_Tag::ENEMY_TYPE_SKELETON;

	}

	void Skeleton::EnemyGetDamage(const uint16_t& someDamage)
	{
		Enemy::EnemyGetDamage(someDamage);
	}
}