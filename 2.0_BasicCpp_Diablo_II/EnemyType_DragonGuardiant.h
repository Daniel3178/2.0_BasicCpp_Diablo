#pragma once
#include "Enemy.h"

namespace diablo_II 
{
	struct				Item;
	class DragonGuardiant : public Enemy 
	{
	public:
						DragonGuardiant();
		void			EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive) override;
		void			SpecialAttack(Player* aPlayer);
	
	private:
		uint8_t			specialAbilityDamage;
	};
}