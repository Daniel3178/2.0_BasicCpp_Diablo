#pragma once
#include<vector>
#include <iostream>

namespace diablo_II 
{
	class				Player;
	struct				Item;
	enum class			Item_Tag : uint8_t;

	class PlayerManager 
	{
	private:
		Player&			myPlayer;
	
	public : 
						PlayerManager(Player& aPlayer) : myPlayer(aPlayer) {};
		void			DisplayPlayerStates() const;
		void			PlayerGetDamage(const uint16_t& someDamage);
		void			DisplayInventory()const;
		void			DropItemsFromInventory(std::vector<Item*>* someItemInTheRoom, const uint8_t anItemIndex);
		void			LootItem(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex);
		void			EquipArmor(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex);
		void			UnEquipArmor(std::vector<Item*>* aRoomItemContainer, Item_Tag anArmor);
		void			ConsumePortion(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex);
		void			ActivatePlayerSpel(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex);
		void			CountSpelTimer();
	};
}