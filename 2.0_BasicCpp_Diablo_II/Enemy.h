#pragma once
#include <iostream>
#include <vector>

namespace diablo_II 
{	
	class					Player;
	struct					Item;
		enum class Enemy_Tag :uint8_t
		{
		ENEMY_TYPE_SKELETON = 0,
		ENEMY_TYPE_VAMPIRE_KNIGHT = 1,
		ENEMY_TYPE_DRAGON_GUARDIANT = 2,
		ENEMY_WEAKNESS_VAMPIRE_KNIGHT,
		ENEMY_WEAKNESS_SKELETON,
		ENEMY_WEAKNESS_DRAGON_GUARDIANT,
		ENEMY_WEAKNESS_DEFAULT
		};

	class Enemy
	{
	protected:
		uint8_t				attackDamage;
		int					hp;
		Enemy_Tag			enemyWeakness;
		Enemy_Tag			enemyType;

	public:
							Enemy() : attackDamage(0), hp(0), enemyWeakness(Enemy_Tag::ENEMY_WEAKNESS_DEFAULT), enemyType(Enemy_Tag::ENEMY_TYPE_SKELETON){};
		int&				GetEnemyHp();
		Enemy_Tag			GetEnemyType();
		virtual void		EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive);
		const uint8_t&		GetEnemyAttackDamageValue() const;
	};

}
