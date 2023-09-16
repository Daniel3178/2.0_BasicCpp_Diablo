#pragma once
#include <iostream>
#include "Tools.h"
#include "InventoryManager.h"
#include "PlayerManager.h"
#include "Player.h"
#include "Equipment.h"

namespace diablo_IV
{

	void InventoryManager::PlayerInventoryChoices()
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\n";


		if(!myPlayer.GetPlayerInventory().empty())
		{
			while(myPlayer.GetPlayerInventory().size() * 2 - plrOpt != -1)
			{
				for(auto& eachItem : myPlayer.GetPlayerInventory())
				{
					std::cout << "\t[Press " << (int) ++optCounter << " ] :: ";
					if(eachItem->GetStats().GetTag() == eItemTag::eArmour || eachItem->GetStats().GetTag() == eItemTag::eWeapon)
					{
						std::cout << "Equip ";
					}
					else
					{
						std::cout << "Consume ";
					}
					std::cout << eachItem->GetStats().GetName() << '\n';
					std::cout << "\t[Press " << (int) ++optCounter << " ] :: Drop ";
					std::cout << eachItem->GetStats().GetName() << " | Item weight: " << (int) eachItem->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) << '\n';
				}

				std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
				std::cout << "\n\tYour choice : ";

				do
				{
					plrOpt = GetPlayerIntFormat();
				}
				while(plrOpt > optCounter || plrOpt <= 0);
				optCounter = 0;
				std::cout << '\n';

				if(myPlayer.GetPlayerInventory().size() * 2 - plrOpt != -1)
				{
					if(plrOpt % 2 == 0)
					{
						myPlayerManager.DropItemsFromInventory(roomItemContainer, (plrOpt / 2) - 1);
					}
					else if(myPlayer.GetPlayerInventory().at(static_cast<uint16_t>((plrOpt / 2)))->GetStats().GetTag() == eItemTag::eArmour)
					{
						myPlayerManager.EquipArmor(myPlayer.GetPlayerInventory(), (static_cast<uint16_t>(plrOpt / 2)));
					}
					else if(myPlayer.GetPlayerInventory().at(static_cast<uint16_t>(plrOpt / 2))->GetStats().GetTag() == eItemTag::eWeapon)
					{
						ShowWeaponHandSelectionDialog(static_cast<uint8_t>(plrOpt / 2));
					}
					else
					{
						myPlayerManager.ConsumePortion(myPlayer.GetPlayerInventory(), static_cast<uint16_t>(plrOpt / 2));
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
			std::cout << "\n\tYour choice : ";

			do
			{
				plrOpt = GetPlayerIntFormat();
			}
			while(plrOpt > optCounter || plrOpt <= 0);
			return;
		}
	}

	void InventoryManager::ShowWeaponHandSelectionDialog(const uint8_t anItemIndex)
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		PlayerManager myPlayerManager = PlayerManager(myPlayer);

		std::cout << "\n\t++++++++++++++++++++++++++++++++++\n";
		std::cout << "\tYou currently have :\n";
		std::cout << "\tLeft hand : ";
		myPlayer.GetPlayerWeapon(eHand::eLeftHand) != nullptr ? std::cout << myPlayer.GetPlayerWeapon(eHand::eLeftHand)->GetStats().GetName() : std::cout << "nothing \n";
		std::cout << "\tRight hand : ";
		myPlayer.GetPlayerWeapon(eHand::eRightHand) != nullptr ? std::cout << myPlayer.GetPlayerWeapon(eHand::eRightHand)->GetStats().GetName() : std::cout << "nothing ";
		std::cout << "\n\t++++++++++++++++++++++++++++++++++\n";
		std::cout << "\t[Press " << (int) ++optCounter << " ] :: Equip the weapon in your left hand \n";
		std::cout << "\t[Press " << (int) ++optCounter << " ] :: Equip the weapon in your right hand \n";
		std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
		std::cout << "\n\tYour choice : ";

		do
		{
			plrOpt = GetPlayerIntFormat();
		}
		while(plrOpt > optCounter || plrOpt <= 0);
		optCounter = 0;
		std::cout << '\n';

		switch(plrOpt)
		{
		case 1:
			myPlayerManager.EquipWeapon(myPlayer.GetPlayerInventory(), anItemIndex, eHand::eLeftHand);
			break;
		case 2:
			myPlayerManager.EquipWeapon(myPlayer.GetPlayerInventory(), anItemIndex, eHand::eRightHand);
			break;
		default:
			break;
		}
	}
}