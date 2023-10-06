#pragma once
#include <vector>
#include <iostream>
namespace diablo_II 
{
	class						Player;
	struct						Item;
	
	class InventoryManager 
	{
	private:
		Player&					myPlayer;
		std::vector<Item*>*		roomItemContainer;
	
	public: 
								InventoryManager(Player& aPlayer, std::vector<Item*>* aRoomItemContainer) 
									: myPlayer(aPlayer), roomItemContainer(aRoomItemContainer) {};
		void					PlayerInventoryChoices();
	};
}