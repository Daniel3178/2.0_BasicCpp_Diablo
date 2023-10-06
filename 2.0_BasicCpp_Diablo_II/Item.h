#pragma once
#include <iostream>

namespace diablo_II 
{
	enum class Item_Tag : uint8_t
	{
		WEARABLE,
		CONSUMABLE,
		NOT_WEARABLE,
		SPEL,
		ARMOR_CHEST,
		ARMOR_SHOULDER,
		ARMOR_LEGS,
		ARMOR_ARMS,
		ARMOR_HELMET,
		PORTION_HP,
		PORTION_STRENGTH,
		SPEL_HELLBOY,
		EMPTY
	};
	
	struct Item 
	{
	private:
		uint8_t					weight;
		std::string				name;
		Item_Tag				itemTag;
		Item_Tag				itemType;

	public:
								Item(Item_Tag aTag);
		void					DisplayItem() const;
		const uint8_t&			GetItemWeight() const;
		const Item_Tag			GetItemTag() const;
		const std::string&		GetItemName() const;
		const Item_Tag			GetItemType() const;
	};
}