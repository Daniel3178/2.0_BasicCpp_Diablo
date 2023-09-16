#pragma once
#include "EnemyType.h"
#include <array>
#include "Enemy.h"
#include <memory>
#include <vector>
namespace diablo_IV
{
	class Enemy;
	class EnemyType;
	enum class eEnemyType;
	class array;
	class shared_ptr;
	class EnemyFactory
	{
	public:
		EnemyFactory() = default;
		EnemyFactory(const EnemyFactory&) = delete;
		void operator=(const EnemyFactory&) = delete;

		void InitializeEnemies();
		std::shared_ptr<Enemy>  CreateEnemy(const eEnemyType aEnemyType) const;
		std::shared_ptr<Enemy> CreatRandomEnemy() const;
		const std::array<EnemyType, static_cast<int>(eEnemyType::eCount)>& GetEnemyTypes();

	private:
		std::array<EnemyType, static_cast<int>(eEnemyType::eCount)> myEnemyTypes;


	};
}