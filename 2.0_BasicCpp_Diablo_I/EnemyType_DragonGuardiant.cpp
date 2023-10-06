#include "EnemyType_DragonGuardiant.h"
#include "Player.h"

namespace diablo_I
{
	DragonGuardiant::DragonGuardiant()
	{
		hp = 400;
		specialAbilityDamage = 20;
		attackDamage = 10;
		enemyWeakness = Enemy_Tag::ENEMY_WEAKNESS_DRAGON_GUARDIANT;
		enemyType = Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT;
	}

	void DragonGuardiant::EnemyGetDamage(const uint16_t& someDamage)
	{
		Enemy::EnemyGetDamage(someDamage);
	}
	void DragonGuardiant::SpecialAttack(Player* aPlayer)
	{

	}
}