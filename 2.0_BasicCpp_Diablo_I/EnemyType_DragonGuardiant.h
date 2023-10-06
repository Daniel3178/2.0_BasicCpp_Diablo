#pragma once
//#include <iostream>
#include "Enemy.h"

namespace diablo_I
{
	//class Player;
	class DragonGuardiant : public Enemy
	{
	public:
		DragonGuardiant();
		void EnemyGetDamage(const uint16_t& someDamage) override;

		void SpecialAttack(Player* aPlayer);
	private:
		uint8_t specialAbilityDamage;
	};
}