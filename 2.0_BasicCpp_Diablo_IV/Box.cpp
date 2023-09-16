#pragma once
#include <vector>
#include <memory>
#include "Box.h"
#include "Item.h"
#include <random>
#include "ItemFactory.h"
namespace diablo_IV
{
	Box::Box(ItemFactory& anItemFactory) : myItemFactory(anItemFactory)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 3);
		int random = dis(gen);
		switch(random)
		{
		case 1:
		{
			std::shared_ptr<Item> item1 = myItemFactory.CreateItem(eItemTypes::eBronzShoulder_Armour);
			std::shared_ptr<Item> item2 = myItemFactory.CreateItem(eItemTypes::eBronzLegs_Armour);
			std::shared_ptr<Item> item3 = myItemFactory.CreateItem(eItemTypes::ePortion_HP);
			
			itemsInTheBox = { item1, item2, item3 };
			boxState = Box_State::LOCKED;
			boxLockStrength = 20;
			break;
		}
		case 2:
		{
			std::shared_ptr<Item> item1 = myItemFactory.CreateItem(eItemTypes::eBronzArm_Armour);
			std::shared_ptr<Item> item2 = myItemFactory.CreateItem(eItemTypes::eBronzChest_Armour);
			std::shared_ptr<Item> item3 = myItemFactory.CreateItem(eItemTypes::ePortion_HP);
			std::shared_ptr<Item> item4 = myItemFactory.CreateItem(eItemTypes::ePortion_Strength);

			itemsInTheBox = { item1, item2, item3, item4 };
			boxState = Box_State::NO_LOCK;
			boxLockStrength = 0;
			break;
		}
		case 3:
		{
			std::shared_ptr<Item> item1 = myItemFactory.CreateItem(eItemTypes::eBronzHelmet_Armour);
			std::shared_ptr<Item> item2 = myItemFactory.CreateItem(eItemTypes::ePortion_HP);
			itemsInTheBox = { item1, item2 };
			boxState = Box_State::LOCKED;
			boxLockStrength = 10;
			break;
		}
		default:
		{

			boxState = Box_State::NO_LOCK;
			boxLockStrength = 0;
			break;
		}
		}
	}

	std::vector<std::shared_ptr<Item>>& Box::GetItemsInTheBox()
	{
		return itemsInTheBox;
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