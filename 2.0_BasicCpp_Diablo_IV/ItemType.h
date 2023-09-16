#pragma once
#include "Stats.h"
#include<array>
namespace diablo_IV
{
	class ItemType
	{
	public :
		ItemType();
		const Stats& GetStats() const;
		void SetStat(const Stats::eStatIndex aStatIndex, const int aValue);
		void SetName(const std::string& aName);
		void SetTag(const eItemTag aTag);
		void SetArmourTag(const eArmourTag aTag);
		void SetPortionTag(const ePortionTag aTag);
		
	private:
		Stats myStats;
	};
}