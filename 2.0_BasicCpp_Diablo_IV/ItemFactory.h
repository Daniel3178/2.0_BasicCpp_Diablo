#pragma once
#include <array>
#include <memory>
#include <vector>
#include "ItemType.h"
namespace diablo_IV
{
	class Item;
	class ItemType;
	enum class eItemTypes
	{
		eSword,
		eGreatSword,
		eAchiliesSword,
		eBronzHelmet_Armour,
		eBronzChest_Armour,
		eBronzArm_Armour,
		eBronzLegs_Armour,
		eBronzShoulder_Armour,
		eSilverHelmet_Armour,
		eSilverChest_Armour,
		eSilverArm_Armour,
		eSilverLegs_Armour,
		eSilverShoulder_Armour,
		eGoldenHelmet_Armour,
		eGoldenChest_Armour,
		eGoldenArm_Armour,
		eGoldenLegs_Armour,
		eGoldenShoulder_Armour,
		ePortion_HP,
		ePortion_Strength,
		eHellBoy_Spell,
		eItemTypeCount,
	};

	class ItemFactory
	{
	public:
		ItemFactory() = default;
		ItemFactory(const ItemFactory&) = delete;
		void operator=(const ItemFactory&) = delete;

		void InitializeItems();
		std::shared_ptr<Item> CreateItem(const eItemTypes anItemType) const;
		std::shared_ptr<Item> CreatRandomItem();
		std::shared_ptr<Item> CreateRandomSpell() const;
		std::shared_ptr<Item> CreateRandomWeapon() const;
		std::shared_ptr<Item> CreateRandomArmour() const;
		std::array<ItemType, static_cast<int>(eItemTypes::eItemTypeCount)>& GetItemTypes();

	private:
		std::array<ItemType, static_cast<int>(eItemTypes::eItemTypeCount)> myItemTypes;

		void InitWeaponTypes();
		void InitArmourTypes();
		void InitSpellTypes();
		void InitPortionTypes();

		std::vector<eItemTypes> myWeaponCategory;
		std::vector<eItemTypes> mySpellCategory;
		std::vector<eItemTypes> myPortionCategory;
		std::vector<eItemTypes> myArmourCategory;
	};
}