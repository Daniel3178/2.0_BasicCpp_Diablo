#include "Item.h"
namespace diablo_II
{
	Item::Item(Item_Tag aTag)
	{
		switch (aTag)
		{
		case diablo_II::Item_Tag::ARMOR_CHEST:
		{
			weight = 2;
			name = "Chest";
			itemTag = Item_Tag::ARMOR_CHEST;
			itemType = Item_Tag::WEARABLE;
			break;
		}
		case diablo_II::Item_Tag::ARMOR_SHOULDER:
		{
			weight = 2;
			name = "Shoulder";
			itemTag = Item_Tag::ARMOR_SHOULDER;
			itemType = Item_Tag::WEARABLE;
			break;
		}
		case diablo_II::Item_Tag::ARMOR_LEGS:
		{
			weight = 2;
			name = "Legs";
			itemTag = Item_Tag::ARMOR_LEGS;
			itemType = Item_Tag::WEARABLE;
			break;
		}
		case diablo_II::Item_Tag::ARMOR_ARMS:
		{
			weight = 2;
			name = "Arms";
			itemTag = Item_Tag::ARMOR_ARMS;
			itemType = Item_Tag::WEARABLE;
			break;
		}
		case diablo_II::Item_Tag::ARMOR_HELMET:
		{
			weight = 2;
			name = "Helmet";
			itemTag = Item_Tag::ARMOR_HELMET;
			itemType = Item_Tag::WEARABLE;
			break;
		}
		case diablo_II::Item_Tag::PORTION_HP:
		{
			weight = 2;
			name = "Health Portion";
			itemTag = Item_Tag::PORTION_HP;
			itemType = Item_Tag::CONSUMABLE;
			break;
		}
		case diablo_II::Item_Tag::PORTION_STRENGTH:
		{
			weight = 2;
			name = "Strength Portion";
			itemTag = Item_Tag::PORTION_STRENGTH;
			itemType = Item_Tag::CONSUMABLE;
			break;
		}
		case diablo_II::Item_Tag::SPEL_HELLBOY:
		{
			weight = 2;
			name = "Spel Hellboy";
			itemTag = Item_Tag::SPEL_HELLBOY;
			itemType = Item_Tag::SPEL;
			break;
		}
		default:
			weight = 0;
			name = "Empty";
			itemTag = Item_Tag::EMPTY;
			itemType = Item_Tag::NOT_WEARABLE;
			break;
		}
	}

	void Item::DisplayItem()const 
	{
		std::cout << "\n Item's weight: " << int(this->weight) << '\n';
		std::cout << "\n Item's name: " << this->name << '\n';
		this->itemType == Item_Tag::WEARABLE ? std::cout << "\n Item : Armor\n" : std::cout << "\n Item : Portion\n";
	}

	const uint8_t& Item::GetItemWeight() const 
	{
		return weight;
	}

	const Item_Tag Item::GetItemType() const 
	{
		return itemType;
	}

	const Item_Tag Item::GetItemTag() const 
	{
		return itemTag;
	}

	const std::string& Item::GetItemName() const 
	{
		return name;
	}
}