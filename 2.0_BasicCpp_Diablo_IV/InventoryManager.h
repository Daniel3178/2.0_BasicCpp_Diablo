#pragma once

namespace diablo_IV 
{
	class						Player;
	class						Item;

	class InventoryManager 
	{
	private:
		Player&					myPlayer;
		std::vector<std::shared_ptr<Item>>&		roomItemContainer;
		void ShowWeaponHandSelectionDialog(const uint8_t anItemIndex);
	
	public: 
								InventoryManager(Player& aPlayer, std::vector<std::shared_ptr<Item>>& aRoomItemContainer) 
									: myPlayer(aPlayer), roomItemContainer(aRoomItemContainer) {};
		void					PlayerInventoryChoices();
	};
}