#pragma once
#include "Enemy.h"
#include <random>
#include "EnemyType.h"
#include "Stats.h"
#include <iostream>
#include "Item.h"
namespace diablo_III
{
	Enemy::Enemy(const EnemyType& anEnemyType) : myEnemyType(&anEnemyType)
	{
		myHealth = myEnemyType->GetStats().GetStat(Stats::eStatIndex::eMaxHealth);
	}

	bool Enemy::IsAlive()
	{
		return myHealth > 0;
	}

	int Enemy::GetAttackDamage() const
	{
		return rand() % myEnemyType->GetStats().GetStat(Stats::eStatIndex::eAttack);
	}

	int Enemy::GetHealth() const
	{
		return myHealth;
	}

	int Enemy::GetMaxHealth() const
	{
		return myEnemyType->GetStats().GetStat(Stats::eStatIndex::eMaxHealth);
	}


	 const std::string Enemy::GetName() const
	{
		return myEnemyType->GetStats().GetName();
	}

	 void Enemy::TakeDamage(const int someDamage)
	 {
		 myHealth -= someDamage;
	 }
}