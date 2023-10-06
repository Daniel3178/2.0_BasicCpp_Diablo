#pragma once
#include "Enemy.h"
#include "Item.h"
namespace diablo_II 
{
	struct			Item;

	class VampireKnight : public Enemy 
	{
	public:
					VampireKnight();
		void		EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive)override;

	private:
		uint8_t		armor;
	};
}
