#pragma once
#include "EnemyType_Skeleton.h"
#include "Player.h"
#include "Item.h"

namespace diablo_II 
{
	Skeleton::Skeleton()
	{
	  attackDamage = 5;
	  hp = 150;
	  enemyWeakness = Enemy_Tag::ENEMY_WEAKNESS_SKELETON;
	  enemyType = Enemy_Tag::ENEMY_TYPE_SKELETON;
	}

	void Skeleton::EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive) 
	{
		Enemy::EnemyGetDamage(someDamage, aRoomContainer, isPlayerSpelActive);
	}
}