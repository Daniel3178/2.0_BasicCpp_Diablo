#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Item.h"
namespace diablo_III 
{
	class						Player;
	class						Item;
	
	class InventoryManager 
	{
	private:
		Player&					myPlayer;
		std::vector<std::shared_ptr<Item>>&		roomItemContainer;
	
	public: 
								InventoryManager(Player& aPlayer, std::vector<std::shared_ptr<Item>>& aRoomItemContainer) 
									: myPlayer(aPlayer), roomItemContainer(aRoomItemContainer) {};
		void					PlayerInventoryChoices();
	};
}