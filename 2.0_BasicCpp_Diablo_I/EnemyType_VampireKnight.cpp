#include "EnemyType_VampireKnight.h"
#include "Player.h"

namespace diablo_I
{
	VampireKnight::VampireKnight()
	{
		attackDamage = 8;
		hp = 200;
		enemyWeakness = Enemy_Tag::ENEMY_WEAKNESS_VAMPIRE_KNIGHT;
		enemyType = Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT;
		armor = 30;
	}

	void VampireKnight::EnemyGetDamage(const uint16_t& someDamage)
	{
		Enemy::EnemyGetDamage(someDamage);
	}
}