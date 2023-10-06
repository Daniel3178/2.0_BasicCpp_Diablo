#include "EnemyType.h"

namespace diablo_III
{
	const Stats& EnemyType::GetStats()const
	{
		return myStats;
	}

	void EnemyType::SetStat(const Stats::eStatIndex aStatIndex, int aValue)
	{
		myStats.SetStat(aStatIndex, aValue);
	}

	void EnemyType::SetName(const std::string& aName)
	{
		myStats.SetName(aName);
	}
}