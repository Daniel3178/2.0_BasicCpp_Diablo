#pragma once
#include "InventoryManager.h"
#include "PlayerManager.h"
#include "Player.h"

namespace diablo_II 
{
	void InventoryManager::PlayerInventoryChoices() 
	{
		uint8_t optCounter{ 0 };
		uint8_t plrOpt{ 0 };
		bool isAccepted{ true };
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\n";
	
		if (myPlayer.GetPlayerInventory() != nullptr) 
		{
			while (myPlayer.GetPlayerInventory()->size() * 2 - plrOpt != -1) 
			{
				for (auto& eachItem : *myPlayer.GetPlayerInventory()) 
				{
					if (eachItem != nullptr) 
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: ";
						eachItem->GetItemType() == Item_Tag::WEARABLE ? std::cout << "Equip " : std::cout << "Cosume ";
						std::cout << eachItem->GetItemName() << '\n';
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Drop ";
						std::cout << eachItem->GetItemName() << " | Item weight: " << (int)eachItem->GetItemWeight() << '\n';
					}
				}

				std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
				std::cout << "\n\tYour choirs : ";

				do 
				{
					isAccepted = true;
					plrOpt = GetPlayerIntFormat();
					if (plrOpt > optCounter || plrOpt <= 0) 
					{
						isAccepted = false;
					}
				} 
				while (!isAccepted);
				optCounter = 0;
				std::cout << '\n';

				if (myPlayer.GetPlayerInventory()->size() * 2 - plrOpt != -1) 
				{
					if (plrOpt % 2 == 0) 
					{
						myPlayerManager.DropItemsFromInventory(roomItemContainer, ((plrOpt + 1) / 2) - 1);
					}
					else if (myPlayer.GetPlayerInventory()->at(size_t((plrOpt + 1) / 2 - 1))->GetItemType() == Item_Tag::WEARABLE) 
					{
						myPlayerManager.EquipArmor(myPlayer.GetPlayerInventory(), ((plrOpt + 1) / 2) - 1);
					}
					else 
					{
						myPlayerManager.ConsumePortion(myPlayer.GetPlayerInventory(), ((plrOpt + 1) / 2) - 1);
					}
					plrOpt = 0;
				}
				else 
				{
					return;
				}
			}
		}

		if (myPlayer.GetPlayerInventory() == nullptr) 
		{
			std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
			std::cout << "\n\tYour choirs : ";

			do 
			{
				isAccepted = true;
				plrOpt = GetPlayerIntFormat();
				if (plrOpt > optCounter || plrOpt <= 0) 
				{
					isAccepted = false;
				}
			} 
			while (!isAccepted);
			return;
		}
	}

}