#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Item.h"

namespace diablo_IV
{
	class Player;
	class Item;

	class Equipment
	{
	private:
		Player& myPlayer;
		std::vector<std::shared_ptr<Item>>& roomItemContainer;
		std::vector<std::shared_ptr<Item>>& inventoryContainer;

	public:
		Equipment(Player& aPlayer, std::vector<std::shared_ptr<Item>>& aRoomItemContainer, std::vector<std::shared_ptr<Item>>& anInventoryContainer)
			: myPlayer(aPlayer), roomItemContainer(aRoomItemContainer), inventoryContainer(anInventoryContainer){};
		void PlayerEquipmentChoices();

	};
}