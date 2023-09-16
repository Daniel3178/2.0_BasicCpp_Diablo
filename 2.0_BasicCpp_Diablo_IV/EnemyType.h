#pragma once
#include "Stats.h"

namespace diablo_IV
{
	class Stats;
	class EnemyType
	{
	public:
		const Stats& GetStats() const;
		void SetStat(const Stats::eStatIndex aStatIndex, const int aValue);
		void SetName(const std::string& aName);

	private:
		Stats myStats;
	};
}