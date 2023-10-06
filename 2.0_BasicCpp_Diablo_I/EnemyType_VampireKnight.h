#pragma once
#include "Enemy.h"

namespace diablo_I
{
	class VampireKnight : public Enemy
	{
	public:
		VampireKnight();
		void EnemyGetDamage(const uint16_t& someDamage)override;

	private:
		uint8_t armor;
	};
}
