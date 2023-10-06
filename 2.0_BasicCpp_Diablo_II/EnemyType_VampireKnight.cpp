#pragma once
#include "EnemyType_VampireKnight.h"
#include "Player.h"
#include "Item.h"
namespace diablo_II 
{
	VampireKnight::VampireKnight() 
	{
		attackDamage = 8;
		hp = 400;
		enemyWeakness = Enemy_Tag::ENEMY_WEAKNESS_VAMPIRE_KNIGHT ;
		enemyType = Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT;
		armor =30;
	}
	
	void VampireKnight::EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive) 
	{
		Enemy::EnemyGetDamage(someDamage, aRoomContainer, isPlayerSpelActive);
	}
}