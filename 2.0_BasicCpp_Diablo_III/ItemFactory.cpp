#pragma once
#include "ItemFactory.h"
#include "ItemType.h"
#include "Item.h"
#include <random>


namespace diablo_III
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
		std::uniform_int_distribution<> dis(1, size_t(myItemTypes.size()-2));

		return CreateItem(static_cast<eItemTypes>(dis(gen)));


	}

	std::shared_ptr<Item> ItemFactory::CreateRandomArmour() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, size_t(myArmourCategory.size()-1));

		return CreateItem(myArmourCategory[dis(gen)]);

	}
	std::shared_ptr<Item> ItemFactory::CreateRandomWeapon() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, size_t(myWeaponCategory.size()-1));

		return CreateItem(myWeaponCategory[dis(gen)]);

	}
	std::shared_ptr<Item> ItemFactory::CreateRandomSpell() const
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, size_t(mySpellCategory.size() - 1));

		return CreateItem(mySpellCategory[dis(gen)]);

	}

	void ItemFactory::InitWeaponTypes()
	{
		myItemTypes[static_cast<int>(eItemTypes::eSword)].SetName("sword");
		myItemTypes[static_cast<int>(eItemTypes::eSword)].SetTag(eItemTag::eWeapon);
		myItemTypes[static_cast<int>(eItemTypes::eSword)].SetStat(Stats::eStatIndex::eAttack, 10);

		myItemTypes[static_cast<int>(eItemTypes::eGreatSword)].SetName("great sword");
		myItemTypes[static_cast<int>(eItemTypes::eGreatSword)].SetTag(eItemTag::eWeapon);
		myItemTypes[static_cast<int>(eItemTypes::eGreatSword)].SetStat(Stats::eStatIndex::eAttack, 20);

		myWeaponCategory.push_back(eItemTypes::eSword);
		myWeaponCategory.push_back(eItemTypes::eGreatSword);
	}

	void ItemFactory::InitPortionTypes()
	{
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetName("health portion");
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetTag(eItemTag::ePortion);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetPortionTag(ePortionTag::eHealth);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_HP)].SetStat(Stats::eStatIndex::eHealth, 10);

		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetName("strength portion");
		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetTag(eItemTag::ePortion);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetPortionTag(ePortionTag::eStrength);
		myItemTypes[static_cast<int>(eItemTypes::ePortion_Strength)].SetStat(Stats::eStatIndex::eStrength, 10);

		myPortionCategory.push_back(eItemTypes::ePortion_HP);
		myPortionCategory.push_back(eItemTypes::ePortion_Strength);
	}
	void ItemFactory::InitArmourTypes()
	{
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetName("arm");
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetArmourTag(eArmourTag::eArm);
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzArm_Armour)].SetStat(Stats::eStatIndex::eDefence, 5);


		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetName("chest");
		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetArmourTag(eArmourTag::eChest);
		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzChest_Armour)].SetStat(Stats::eStatIndex::eDefence, 15);

		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetName("shoulder");
		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetArmourTag(eArmourTag::eShoulder);
		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzShoulder_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);

		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetName("legs");
		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetArmourTag(eArmourTag::eLeg);
		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzLegs_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);

		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetName("helmet");
		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetArmourTag(eArmourTag::eHelmet);
		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetTag(eItemTag::eArmour);
		myItemTypes[static_cast<int>(eItemTypes::eBronzHelmet_Armour)].SetStat(Stats::eStatIndex::eDefence, 10);

		myArmourCategory.push_back(eItemTypes::eBronzArm_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzChest_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzShoulder_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzLegs_Armour);
		myArmourCategory.push_back(eItemTypes::eBronzHelmet_Armour);
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