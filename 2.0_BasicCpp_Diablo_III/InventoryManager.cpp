#pragma once
#include "InventoryManager.h"
#include "PlayerManager.h"
#include "Player.h"
#include "Item.h"
#include "GameManager.h"

namespace diablo_III
{
	void InventoryManager::PlayerInventoryChoices()
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		bool isAccepted { true };
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\n";

		if(!myPlayer.GetPlayerInventory().empty())
		{
			while(myPlayer.GetPlayerInventory().size() * 2 - plrOpt != -1)
			{
				for(auto& eachItem : myPlayer.GetPlayerInventory())
				{
					if(eachItem != nullptr)
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: ";
						eachItem->GetStats().GetTag() == eItemTag::eArmour ? std::cout << "Equip " : std::cout << "Cosume ";
						std::cout << eachItem->GetStats().GetName() << '\n';
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Drop ";
						std::cout << eachItem->GetStats().GetName()<< " | Item weight: " << (int) eachItem->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) << '\n';
					}
				}

				std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
				std::cout << "\n\tYour choirs : ";

				do
				{
					//isAccepted = true;
					plrOpt = GetPlayerIntFormat();
					//if(plrOpt > optCounter || plrOpt <= 0)
					//{
					//	isAccepted = false;
					//}
				}
				while(plrOpt > optCounter || plrOpt <= 0);
				optCounter = 0;
				std::cout << '\n';

				if(myPlayer.GetPlayerInventory().size() * 2 - plrOpt != 1)
				{
					if(plrOpt % 2 == 0)
					{
						myPlayerManager.DropItemsFromInventory(roomItemContainer, ((plrOpt + 1) / 2) );
					}
					else if(myPlayer.GetPlayerInventory().at(size_t((plrOpt + 1) / 2 ))->GetStats().GetTag() == eItemTag::eArmour)
					{
						myPlayerManager.EquipArmor(myPlayer.GetPlayerInventory(), ((plrOpt + 1) / 2) );
					}
					else
					{
						myPlayerManager.ConsumePortion(myPlayer.GetPlayerInventory(), ((plrOpt + 1) / 2) );
					}
					plrOpt = 0;
				}
				else
				{
					return;
				}
			}
		}

		if(myPlayer.GetPlayerInventory().empty())
		{
			std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
			std::cout << "\n\tYour choirs : ";

			do
			{
				//isAccepted = true;
				plrOpt = GetPlayerIntFormat();
				//if(plrOpt > optCounter || plrOpt <= 0)
				//{
				//	isAccepted = false;
				//}
			}
			while(plrOpt > optCounter || plrOpt <= 0);
			return;
		}
	}

}