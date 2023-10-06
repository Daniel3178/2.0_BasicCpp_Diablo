#include "Stats.h"

namespace diablo_III
{
	const char* Stats::ourStatNames[static_cast<int>(eStatIndex::eStatCount)] = {
		"strength       ",
		"flexibility    ",
		"physic         ",
		"health         ",
		"maximum health ",
		"defence        ",
		"attack         ",
		"maximum weight ",

	};

	Stats::Stats()
	{
		myValues = { 0 };
		myName = "Undefined";
		myTag = eItemTag::eNone;
		myPortionTag = ePortionTag::eNone;
		myArmourTag = eArmourTag::eNone;
	}

	const std::string& Stats::GetName() const
	{
		return myName;
	}

	const int Stats::GetStat(const eStatIndex aStatIndex) const
	{
		return myValues[static_cast<int>(aStatIndex)];
	}

	void Stats::SetStat(const eStatIndex aStatIndex, int aValue)
	{
		myValues[static_cast<int>(aStatIndex)] = aValue;
	}

	void Stats::ChangeStat(const eStatIndex aStatIndex, int aNewValue)
	{
		myValues[static_cast<int>(aStatIndex)] += aNewValue;
	}

	void Stats::SetName(const std::string& aName)
	{
		myName = aName;
	}

	void Stats::TakeDamage(const int aDamage)
	{
		ChangeStat(eStatIndex::eHealth, -aDamage);
	}

	bool Stats::IsAlive() const
	{
		return myValues[static_cast<int>(eStatIndex::eHealth)] > 0;
	}

	void Stats::PrintStats() const
	{
		for(int i = 0; i < myValues.size(); i++)
		{
			if(GetStat(static_cast<eStatIndex>(i)) != 0)
			{
				std::cout << "\n\t" << Stats::ourStatNames[i] << "\t" << GetStat(static_cast<eStatIndex>(i)) << '\n';
			}
		}
	}

	void Stats::SetTag(const eItemTag aTag)
	{
		myTag = aTag;
	}

	const eItemTag& Stats::GetTag() const
	{
		return myTag;
	}

	void Stats::SetArmourTag(const eArmourTag aTag)
	{
		myArmourTag = aTag;
	}
	const eArmourTag& Stats::GetArmourTag() const
	{
		return myArmourTag;
	}
	void Stats::SetPortionTag(const ePortionTag aTag)
	{
		myPortionTag = aTag;
	}
	const ePortionTag& Stats::GetPortionTag() const
	{
		return myPortionTag;
	}
}