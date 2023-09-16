#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Equipment.h"
#include "PlayerManager.h"
#include "Player.h"
#include "Item.h"
#include "Tools.h"

namespace diablo_IV
{

	const uint8_t Equipment::CountPlayerEquipmentOpt()const
	{
		uint8_t optCounter { 0 };

		for(auto& eachItem : myPlayer.GetPlayerEquipedArmor())
		{
			if(eachItem != nullptr)
			{
				std::cout << "\t[Press " << (int) ++optCounter << " ] :: Unequip ";
				std::cout << eachItem->GetStats().GetName() << " |";
				std::cout << " Defence :: " << eachItem->GetStats().GetStat(Stats::eStatIndex::eDefence) << '\n';
			}
		}

		std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
		std::cout << "\n\tYour choice: ";
		return optCounter;
	}

	void Equipment::PlayerEquipmentChoices()
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\n";

		if(!myPlayer.GetPlayerEquipedArmor().empty())
		{
			while(!IsQuitPressed(myPlayer.GetPlayerEquipedArmor(), plrOpt))
			{
				optCounter = CountPlayerEquipmentOpt();
				do
				{
					plrOpt = GetPlayerIntFormat();
				}
				while(plrOpt > optCounter || plrOpt <= 0);
				optCounter = 0;
				std::cout << '\n';

				if(!IsQuitPressed(myPlayer.GetPlayerEquipedArmor(), plrOpt))
				{
					myPlayerManager.UnEquipArmor(roomItemContainer, myPlayer.GetPlayerEquipedArmor().at(static_cast<uint16_t>(plrOpt-1))->GetStats().GetArmourTag());
					plrOpt = 0; 
				}
				else
				{
					return;
				}
			}
		}
		else
		{
			ForceToReturn();
		}
	}
}