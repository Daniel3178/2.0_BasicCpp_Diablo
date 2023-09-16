#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "Enemy.h"
#include "EnemyType.h"
#include <memory>
#include "EnemyFactory.h"
#include <random>
namespace diablo_IV
{
	void EnemyFactory::InitializeEnemies()
	{
		myEnemyTypes[static_cast<int>(eEnemyType::eSkeleton)].SetName("Skeleton");
		myEnemyTypes[static_cast<int>(eEnemyType::eSkeleton)].SetStat(Stats::eStatIndex::eAttack, 5);
		myEnemyTypes[static_cast<int>(eEnemyType::eSkeleton)].SetStat(Stats::eStatIndex::eMaxHealth, 20);

		myEnemyTypes[static_cast<int>(eEnemyType::eVampire)].SetName("Vampire");
		myEnemyTypes[static_cast<int>(eEnemyType::eVampire)].SetStat(Stats::eStatIndex::eAttack, 10);
		myEnemyTypes[static_cast<int>(eEnemyType::eVampire)].SetStat(Stats::eStatIndex::eMaxHealth, 30);

		myEnemyTypes[static_cast<int>(eEnemyType::eDragon)].SetName("Dragon");
		myEnemyTypes[static_cast<int>(eEnemyType::eDragon)].SetStat(Stats::eStatIndex::eAttack, 10);
		myEnemyTypes[static_cast<int>(eEnemyType::eDragon)].SetStat(Stats::eStatIndex::eMaxHealth, 50);
	}

	std::shared_ptr<Enemy> EnemyFactory::CreateEnemy(const eEnemyType aEnemyType) const
	{
		std::shared_ptr<Enemy> myNewEnemy = std::make_shared<Enemy>(myEnemyTypes[static_cast<int>(aEnemyType)]);
		return myNewEnemy;
	}

	std::shared_ptr<Enemy> EnemyFactory::CreatRandomEnemy() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, static_cast<uint8_t>(eEnemyType::eCount) - 1);

		return CreateEnemy(static_cast<eEnemyType>(dis(gen)));
	}
	const std::array<EnemyType, static_cast<int>(eEnemyType::eCount)>& EnemyFactory::GetEnemyTypes()
	{
		return myEnemyTypes;
	}

}