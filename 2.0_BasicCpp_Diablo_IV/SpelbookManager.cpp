#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Item.h"
#include "SpellbookManager.h"
#include "PlayerManager.h"
#include "Player.h"
#include "Tools.h"

namespace diablo_IV
{
	const uint8_t SpellbookManager::CountSpellbookOpt() const
	{
		uint8_t optCounter { 0 };

		for(auto& eachItem : myPlayer.GetPlayerSpellbook())
		{
			std::cout << "\t[Press " << (int) ++optCounter << " ] :: Activate the spell" << eachItem->GetStats().GetName() << '\n';
		}

		std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
		std::cout << "\n\tYour choice : ";
		return optCounter;
	}


	void SpellbookManager::PlayerSpellbookChoice()
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\n";

		if(!myPlayer.GetPlayerSpellbook().empty())
		{
			while(!IsQuitPressed(myPlayer.GetPlayerSpellbook(), plrOpt))
			{
				optCounter = CountSpellbookOpt();
				do
				{
					plrOpt = GetPlayerIntFormat();
				}
				while(plrOpt > optCounter || plrOpt <= 0);
				optCounter = 0;
				std::cout << '\n';

				if(!IsQuitPressed(myPlayer.GetPlayerSpellbook(), plrOpt))
				{
					myPlayerManager.ActivatePlayerSpell(myPlayer.GetPlayerSpellbook(), plrOpt - 1);
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