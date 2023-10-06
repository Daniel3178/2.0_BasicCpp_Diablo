#pragma once
#include "Enemy.h"

namespace diablo_I
{
	class Skeleton : public Enemy
	{
	public:
		Skeleton();
		void EnemyGetDamage(const uint16_t& someDamage)override;

	private:
	};
}
