#pragma once

namespace diablo_IV 
{
	class Item;
	enum class Box_State : uint8_t 
	{
		LOCKED,
		UNLOCKED,
		NO_LOCK,
		EMPTY
	};
	class ItemFactory;
	class Box 
	{
	private: 
		std::vector<std::shared_ptr<Item> >		itemsInTheBox;
		Box_State				boxState;
		uint8_t					boxLockStrength;
		ItemFactory& myItemFactory;
	public :
								Box(ItemFactory& anItemFactory);
		std::vector<std::shared_ptr<Item>>&		GetItemsInTheBox();
		Box_State&				GetBoxState();
		uint8_t&				GetBoxLockStrength();

	};
}