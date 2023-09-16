#pragma once
#include<string>
#include <memory>
#include <array>
#include <vector>

namespace diablo_IV
{

	enum class eHand
	{
		eLeftHand,
		eRightHand
	};
	enum class eItemTag
	{
		eNone,
		eArmour,
		eWeapon,
		ePortion,
		eSpell,
		eCount
	};
	enum class eArmourTag
	{
		eNone,
		eArm,
		eLeg,
		eChest,
		eHelmet,
		eShoulder
	};
	enum class ePortionTag
	{
		eNone,
		eHealth,
		eStrength
	};



	class Stats
	{
	public:
		enum class eStatIndex
		{
			eStrength,
			eFlexibility,
			ePhysic,
			eHealth,
			eMaxHealth,
			eDefence,
			eAttack,
			eMaxWeight,
			eStatCount
		};

		Stats();
		const std::string& GetName() const;
		const int GetStat(const eStatIndex aStatIndex) const;
		void SetStat(const eStatIndex aStatIndex, int aValue);
		void ChangeStat(const eStatIndex aStatIndex, int aNewValue);
		void SetName(const std::string& aName);
		void PrintStats() const;
		const eItemTag& GetTag() const;
		void SetTag(const eItemTag aTag);
		void SetArmourTag(const eArmourTag aTag);
		void SetPortionTag(const ePortionTag aTag);
		const eArmourTag& GetArmourTag() const;
		const ePortionTag& GetPortionTag() const;
		void TakeDamage(const int aDamage);
		bool IsAlive() const;
		static const char* ourStatNames[];

	private:
		std::string myName;
		std::array <int, static_cast<int>(eStatIndex::eStatCount)> myValues;
		eItemTag myTag;
		eArmourTag myArmourTag;
		ePortionTag myPortionTag;
	};
}