#pragma once
#include "EnemyType_DragonGuardiant.h"
#include "Player.h"
#include "Item.h"

namespace diablo_II 
{
	DragonGuardiant::DragonGuardiant() 
	{
		hp = 2000;
		specialAbilityDamage = 20;
		attackDamage = 50;
		enemyWeakness = Enemy_Tag::ENEMY_WEAKNESS_DRAGON_GUARDIANT;
		enemyType = Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT;
	}

	void DragonGuardiant::EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive) 
	{
		Enemy::EnemyGetDamage(someDamage, aRoomContainer, isPlayerSpelActive);
	}
	
	void DragonGuardiant::SpecialAttack(Player* aPlayer) 
	{
		//Special attack!
	}
}