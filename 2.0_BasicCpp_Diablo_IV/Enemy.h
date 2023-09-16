#pragma once
#include <iostream>

namespace diablo_IV 
{	

	enum class eEnemyType
	{
		eSkeleton,
		eVampire,
		eDragon,
		eCount
	};
	class EnemyType;
	class Item;
	class Enemy
	{
	public: 
		Enemy(const EnemyType& anEnemyType);
		bool IsAlive();
		int GetAttackDamage() const;
		int GetHealth() const;
		int GetMaxHealth()const ;
	    const std::string GetName() const ;

		void TakeDamage(const int someDamage);

	private:
		int myHealth;
	    const EnemyType* myEnemyType;
	};
}
