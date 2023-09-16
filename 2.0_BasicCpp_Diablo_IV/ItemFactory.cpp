#pragma once
#include <array>
#include <vector>
#include <memory>
#include "ItemFactory.h"
#include "ItemType.h"
#include "Item.h"
#include <random>


namespace diablo_IV
{

	void ItemFactory::InitializeItems()
	{
		InitArmourTypes();
		InitSpellTypes();
		InitWeaponTypes();
		InitPortionTypes();
	}

	std::shared_ptr<Item> ItemFactory::CreateItem(const eItemTypes anItemType) const
	{		
		std::shared_ptr<Item> aNewItem = std::make_shared<Item>(myItemTypes[static_cast<int>(anItemType)]);
			return aNewItem;
	}

	std::shared_ptr<Item> ItemFactory::CreatRandomItem()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, static_cast<int>(eItemTypes::eItemTypeCount)-1);

		return CreateItem(static_cast<eItemTypes>(dis(gen)));


	}

	std::shared_ptr<Item> ItemFactory::CreateRandomArmour() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, static_cast<uint8_t>(myArmourCategory.size()-1));

		return CreateItem(myArmourCategory[dis(gen)]);

	}
	std::shared_ptr<Item> ItemFactory::CreateRandomWeapon() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, static_cast<uint8_t>(myWeaponCategory.size()-1));

		return CreateItem(myWeaponCategory[dis(gen)]);

	}
	std::shared_ptr<Item> ItemFactory::CreateRandomSpell() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, static_cast<uint8_t>(mySpellCategory.size() - 1));

		return CreateItem(mySpellCategory[dis(gen)]);

	}

	void ItemFactory::InitWeaponTypes()
	{
		myItemTypes[static_cast<int>(eItemTypes::eSword)].SetName("sword");
		myItemTypes[static_cast<int>(eItemTypes::eSword)].SetTag(eItemTag::eWeapon);
		myItemTypes[static_cast<int>(eItemTypes::eSword)].SetStat(Stats::eStatIndex::eAttack, 10);
		myItemTypes[static_cast<int>(eItemTypes::eSword)].SetStat(Stats::eStatIndex::eMaxWeight, 1);

		myItemTypes[static_cast<int>(eItemTypes::eGreatSword)].SetName("great sword");
		myItemTypes[static_cast<int>(eItemTypes::eGreatSword)].SetTag(eItemTag::eWeapon);
		myItemTypes[static_cast<int>(eItemTypes::eGreatSword)].SetStat(Stats::eStatIndex::eAttack, 20);
		myItemTypes[static_cast<int>(eItemTypes::eGreatSword)].SetStat(Stats::eStatIndex::eMaxWeight, 2);

		myItemTypes[static_cast<int>(eItemTypes::eAchiliesSword)].SetName("Achilies sword");
		myItemTypes[static_cast<int>(eItemTypes::eAchiliesSword)].SetTag(eItemTag::eWeapon);
		myItemTypes[static_cast<int>(eItemTypes::eAchiliesSword)].SetStat(Stats::eStatIndex::eAttack, 35);
		myItemTypes[static_cast<int>(eItemTypes::eAchiliesSword)].SetStat(Stats::eStatIndex::eMaxWeight, 3);

		myWeaponCategory.push_back(eItemTypes::eSword);
		myWeaponCategory.push_back(eItemTypes::eGreatSword);
		myWeaponCategory.push_back(eItemTypes::eAchiliesSword);
	}

	void ItemFactory::InitPortionTypes()
	{
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetName("health portion");
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetTag(eItemTag::ePortion);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetPortionTag(ePortionTag::eHealth);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetStat(Stats::eStatIndex::eHealth, 10);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetStat(Stats::eStatIndex::eMaxWeight, 1);


		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetName("strength portion");
		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetTag(eItemTag::ePortion);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetPortionTag(ePortionTag::eStrength);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetStat(Stats::eStatIndex::eStrength, 10);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetStat(Stats::eStatIndex::eMaxWeight, 1);


		myPortionCategory.push_back(eItemTypes::ePortion_HP);
		myPortionCategory.push_back(eItemTypes::ePortion_Strength);
	}
	void ItemFactory::InitArmourTypes()
	{
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetName("arm (Bronze)");
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetArmourTag(eArmourTag::eArm);
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetStat(Stats::eStatIndex::eDefence, 5);
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 1);


		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetName("chest (Bronze)");
		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetArmourTag(eArmourTag::eChest);
		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetStat(Stats::eStatIndex::eDefence, 5);
		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 1);


		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetName("shoulder (Bronze)");
		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetArmourTag(eArmourTag::eShoulder);
		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetStat(Stats::eStatIndex::eDefence, 5);
		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 1);


		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetName("legs (Bronze)");
		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetArmourTag(eArmourTag::eLeg);
		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetStat(Stats::eStatIndex::eDefence, 5);
		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 1);


		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetName("helmet (Bronze)");
		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetArmourTag(eArmourTag::eHelmet);
		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetStat(Stats::eStatIndex::eDefence, 5);
		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 1);

		myItemTypes[static_cast<int>(eItemTypes::eSilverArm_Armour)].SetName("arm (Silver)");
		myItemTypes[static_cast<int>(eItemTypes::eSilverArm_Armour)].SetArmourTag(eArmourTag::eArm);
		myItemTypes[static_cast<int>(eItemTypes::eSilverArm_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eSilverArm_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);
		myItemTypes[static_cast<int>(eItemTypes::eSilverArm_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 2);


		myItemTypes[static_cast<int>(eItemTypes::eSilverChest_Armour)].SetName("chest (Silver)");
		myItemTypes[static_cast<int>(eItemTypes::eSilverChest_Armour)].SetArmourTag(eArmourTag::eChest);
		myItemTypes[static_cast<int>(eItemTypes::eSilverChest_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eSilverChest_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);
		myItemTypes[static_cast<int>(eItemTypes::eSilverChest_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 2);


		myItemTypes[static_cast<int>(eItemTypes::eSilverShoulder_Armour)].SetName("shoulder (Silver)");
		myItemTypes[static_cast<int>(eItemTypes::eSilverShoulder_Armour)].SetArmourTag(eArmourTag::eShoulder);
		myItemTypes[static_cast<int>(eItemTypes::eSilverShoulder_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eSilverShoulder_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);
		myItemTypes[static_cast<int>(eItemTypes::eSilverShoulder_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 2);


		myItemTypes[static_cast<int>(eItemTypes::eSilverLegs_Armour)].SetName("legs (Silver)");
		myItemTypes[static_cast<int>(eItemTypes::eSilverLegs_Armour)].SetArmourTag(eArmourTag::eLeg);
		myItemTypes[static_cast<int>(eItemTypes::eSilverLegs_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eSilverLegs_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);
		myItemTypes[static_cast<int>(eItemTypes::eSilverLegs_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 2);


		myItemTypes[static_cast<int>(eItemTypes::eSilverHelmet_Armour)].SetName("helmet (Silver)");
		myItemTypes[static_cast<int>(eItemTypes::eSilverHelmet_Armour)].SetArmourTag(eArmourTag::eHelmet);
		myItemTypes[static_cast<int>(eItemTypes::eSilverHelmet_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eSilverHelmet_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);
		myItemTypes[static_cast<int>(eItemTypes::eSilverHelmet_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 2);

		myItemTypes[static_cast<int>(eItemTypes::eGoldenArm_Armour)].SetName("arm (Golden)");
		myItemTypes[static_cast<int>(eItemTypes::eGoldenArm_Armour)].SetArmourTag(eArmourTag::eArm);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenArm_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenArm_Armour)].SetStat(Stats::eStatIndex::eDefence, 15);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenArm_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 3);


		myItemTypes[static_cast<int>(eItemTypes::eGoldenChest_Armour)].SetName("chest (Golden)");
		myItemTypes[static_cast<int>(eItemTypes::eGoldenChest_Armour)].SetArmourTag(eArmourTag::eChest);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenChest_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenChest_Armour)].SetStat(Stats::eStatIndex::eDefence, 15);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenChest_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 3);


		myItemTypes[static_cast<int>(eItemTypes::eGoldenShoulder_Armour)].SetName("shoulder (Golden)");
		myItemTypes[static_cast<int>(eItemTypes::eGoldenShoulder_Armour)].SetArmourTag(eArmourTag::eShoulder);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenShoulder_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenShoulder_Armour)].SetStat(Stats::eStatIndex::eDefence, 15);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenShoulder_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 3);


		myItemTypes[static_cast<int>(eItemTypes::eGoldenLegs_Armour)].SetName("legs (Golden)");
		myItemTypes[static_cast<int>(eItemTypes::eGoldenLegs_Armour)].SetArmourTag(eArmourTag::eLeg);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenLegs_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenLegs_Armour)].SetStat(Stats::eStatIndex::eDefence, 15);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenLegs_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 3);


		myItemTypes[static_cast<int>(eItemTypes::eGoldenHelmet_Armour)].SetName("helmet (Golden)");
		myItemTypes[static_cast<int>(eItemTypes::eGoldenHelmet_Armour)].SetArmourTag(eArmourTag::eHelmet);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenHelmet_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenHelmet_Armour)].SetStat(Stats::eStatIndex::eDefence, 15);
		myItemTypes[static_cast<int>(eItemTypes::eGoldenHelmet_Armour)].SetStat(Stats::eStatIndex::eMaxWeight, 3);


		myArmourCategory.push_back(eItemTypes::eBronzArm_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzChest_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzShoulder_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzLegs_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzHelmet_Armour);

		myArmourCategory.push_back(eItemTypes::eSilverArm_Armour);
		myArmourCategory.push_back(eItemTypes::eSilverChest_Armour);
		myArmourCategory.push_back(eItemTypes::eSilverShoulder_Armour);
		myArmourCategory.push_back(eItemTypes::eSilverLegs_Armour);
		myArmourCategory.push_back(eItemTypes::eSilverHelmet_Armour);

		myArmourCategory.push_back(eItemTypes::eGoldenArm_Armour);
		myArmourCategory.push_back(eItemTypes::eGoldenChest_Armour);
		myArmourCategory.push_back(eItemTypes::eGoldenShoulder_Armour);
		myArmourCategory.push_back(eItemTypes::eGoldenLegs_Armour);
		myArmourCategory.push_back(eItemTypes::eGoldenHelmet_Armour);

	}

	void ItemFactory::InitSpellTypes()
	{
		myItemTypes[static_cast<int>(eItemTypes::eHellBoy_Spell)].SetName("HellBoy");
		myItemTypes[static_cast<int>(eItemTypes::eHellBoy_Spell)].SetStat(Stats::eStatIndex::eAttack, 20);
		myItemTypes[static_cast<int>(eItemTypes::eHellBoy_Spell)].SetTag(eItemTag::eSpell);

		mySpellCategory.push_back(eItemTypes::eHellBoy_Spell);

	}
	std::array<ItemType, static_cast<int>(eItemTypes::eItemTypeCount)>& ItemFactory::GetItemTypes()
	{
		return myItemTypes;
	}
}