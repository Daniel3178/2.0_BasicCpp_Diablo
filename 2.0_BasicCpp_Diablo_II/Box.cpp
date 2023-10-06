#pragma once
#include <vector>
#include "Box.h"
#include "Item.h"
#include <random>

namespace diablo_II 
{
	Box::Box() 
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 4);
		int random = dis(gen);
		switch (random)
		{
		case 1:
		{
			Item* item1 = new Item(Item_Tag::ARMOR_SHOULDER);
			Item* item2 = new Item(Item_Tag::ARMOR_LEGS);
			Item* item3 = new Item(Item_Tag::PORTION_HP);

			itemsInTheBox = new std::vector<Item*>{ item1, item2, item3 };
			boxState = Box_State::LOCKED;
			boxLockStrength = 20;
			break;
		}
		case 2:
		{
			Item* item1 = new Item(Item_Tag::ARMOR_ARMS);
			Item* item2 = new Item(Item_Tag::ARMOR_CHEST);
			Item* item3 = new Item(Item_Tag::PORTION_HP);
			Item* item4 = new Item(Item_Tag::PORTION_STRENGTH);

			itemsInTheBox = new std::vector<Item*>{ item1, item2, item3, item4 };
			boxState = Box_State::NO_LOCK;
			boxLockStrength = 0;
			break;
		}
		case 3:
		{
			Item* item1 = new Item(Item_Tag::ARMOR_HELMET);
			Item* item2 = new Item(Item_Tag::PORTION_STRENGTH);

			itemsInTheBox = new std::vector<Item*>{ item1, item2 };
			boxState = Box_State::LOCKED;
			boxLockStrength = 10;
			break;
		}
		default:
		{
			itemsInTheBox = nullptr;
			boxState = Box_State::NO_LOCK;
			boxLockStrength = 0;
			break;
		}
		}
	}

	std::vector<Item*>* Box::GetItemsInTheBox() 
	{
		return itemsInTheBox;
	}

	void Box::SetItemsInTheBoxToNull() 
	{
		itemsInTheBox = nullptr;
	}

	Box_State& Box::GetBoxState() 
	{
		return boxState;
	}

	uint8_t& Box::GetBoxLockStrength() 
	{
		return boxLockStrength;
	}
}