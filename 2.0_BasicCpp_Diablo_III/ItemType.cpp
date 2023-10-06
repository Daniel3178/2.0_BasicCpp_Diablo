#include "ItemType.h"

namespace diablo_III
{
	ItemType::ItemType()
	{

	}

	const Stats& ItemType::GetStats() const
	{
		return myStats;
	}


	void ItemType::SetStat(const Stats::eStatIndex aStatIndex, const int aValue)
	{
		myStats.SetStat(aStatIndex, aValue);
	}

	void ItemType::SetName(const std::string& aName)
	{
		myStats.SetName(aName);
	}
	void ItemType::SetTag(const eItemTag aTag)
	{
		myStats.SetTag(aTag);
	}
	void ItemType::SetArmourTag(const eArmourTag aTag)
	{
		myStats.SetArmourTag(aTag);
	}
	void ItemType::SetPortionTag(const ePortionTag aTag)
	{
		myStats.SetPortionTag(aTag);
	}
}