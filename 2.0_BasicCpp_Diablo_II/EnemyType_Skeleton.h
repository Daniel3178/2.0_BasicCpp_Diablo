#pragma once
#include "Enemy.h"

namespace diablo_II 
{
	struct			Item;

	class Skeleton : public Enemy 
	{
	public:
					Skeleton();
		void		EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive)override;

	private:
	};
}
