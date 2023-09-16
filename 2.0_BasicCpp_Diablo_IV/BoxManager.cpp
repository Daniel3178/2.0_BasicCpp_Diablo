#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include"BoxManager.h"
#include"Room.h"
#include "BattleController.h"
#include "PlayerManager.h"
#include "Box.h"
#include "Item.h"
#include "Player.h"
#include "Tools.h"
namespace diablo_IV
{
	uint8_t BoxManager::GetPlayerBoxChoiceOpt()
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		bool isAccepted { true };
		std::cout << "\n\n";

		if(!myRoom->GetBoxes().empty())
		{
			for(auto& eachBox : myRoom->GetBoxes())
			{
				if(eachBox != nullptr)
				{
					if(eachBox->GetItemsInTheBox().empty())
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Open Box " << (int) optCounter << " | Empty!" << '\n';
					}
					//else if(eachBox->GetItemsInTheBox().size() == 1 && eachBox->GetItemsInTheBox().at(0) == nullptr)
					//{
					//	std::cout << "\t[Press " << (int) ++optCounter << " ] :: Open Box " << (int) optCounter << " | Empty!" << '\n';
					//}
					else
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Open Box " << (int) optCounter << '\n';
					}
				}
			}
		}
		else
		{
			std::cout << " \nNo boxes in this room" << '\n';
		}

		std::cout << "\t[Press " << (int)++optCounter << ']' << " Quit" << '\n';
		std::cout << "\n\tYour choice : ";
		do
		{
			plrOpt = GetPlayerIntFormat();
		}
		while(plrOpt > optCounter || plrOpt <= 0);

		std::cout << '\n';
		return plrOpt;
	}

	void BoxManager::BreakLock(Box& aBox)
	{
		std::cout << "\n\t++++++++++++++++++++++++++++++++++\n";
		std::cout << "\tThe lock has been broken \n";
		std::cout << "\t+++++++++++++++++++++++++++\n";
		aBox.GetBoxState() = Box_State::UNLOCKED;
		aBox.GetBoxLockStrength() = 0;
	}

	void BoxManager::ChoseBox()
	{
		bool quit { false };
		uint8_t plrOpt { 0 };
		uint8_t plrLockOpt { 0 };
		BattleController myBattleController(myPlayer, myRoom, myItemFactory );

		while(!quit && myPlayer.GetPlayerLifeState() == true)
		{
			plrOpt = GetPlayerBoxChoiceOpt();
			if(myRoom->GetBoxes().size()>0)
			{
				if(plrOpt - myRoom->GetBoxes().size() == 1)
				{
					quit = true;
				}
				else if(myBattleController.ExistEnemies())
				{
					myBattleController.RandomEnemyAttack();
					myBattleController.Combat();
					quit = true;
				}
				else
				{
					if(myRoom->GetBoxes().at(static_cast<uint8_t>(plrOpt - 1))->GetBoxState() == Box_State::LOCKED)
					{
						std::cout << "\n\t*************************\n";
						std::cout << "\tThe box is locked!\n";
						std::cout << "\t*************************\n";
						std::cout << "\t[Press 1] :: Break the lock \n";
						std::cout << "\t[Press 2] :: Cancel\n";
						std::cout << "\n\tYour choice : ";

						do
						{
							plrLockOpt = GetPlayerIntFormat();
						}
						while(plrLockOpt > 2 || plrLockOpt <= 0);

						if(plrLockOpt == 1)
						{
							if(myRoom->GetBoxes().at(static_cast<uint8_t>(plrOpt - 1))->GetBoxLockStrength() <= myPlayer.GetStat(Stats::eStatIndex::eStrength))
							{
								BreakLock(*myRoom->GetBoxes().at(static_cast<uint8_t>(plrOpt - 1)));
								PlayerInBoxChoices(myRoom->GetBoxes().at(static_cast<uint8_t>(plrOpt - 1))->GetItemsInTheBox());
							}
							else
							{
								std::cout << "\n\tYou don't have enough strength to break this lock! | Strength required : " << (int) myRoom->GetBoxes().at(static_cast<uint8_t>(plrOpt - 1))->GetBoxLockStrength() << '\n';
							}
						}
					}
					else
					{
						PlayerInBoxChoices(myRoom->GetBoxes().at(static_cast<uint8_t>(plrOpt - 1))->GetItemsInTheBox());
					}
				}
			}
			else
			{
				quit = true;
			}
		}
	}

	void BoxManager::PlayerInBoxChoices(std::vector<std::shared_ptr<Item>>& someItems)
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		bool isAccepted { true };
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\n";

		if(someItems.size()>0)
		{
			while(someItems.size() - plrOpt != -1)
			{
				for(auto& eachItem : someItems)
				{
					if(eachItem != nullptr)
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Loot ";
						std::cout << eachItem->GetStats().GetName() << " | Item weight: " << (int) eachItem->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) << '\n';
					}
				}

				std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
				std::cout << "\n\tYour choirs : ";

				do
				{
					plrOpt = GetPlayerIntFormat();
				}
				while(plrOpt > optCounter || plrOpt <= 0);
				optCounter = 0;
				std::cout << '\n';

1;				if(someItems.size() - plrOpt != -1 && !someItems.empty() )
				{
						myPlayerManager.LootItem(someItems, plrOpt  - 1);
					plrOpt = 0;
				}
				else
				{
					return;
				}
			}
		}

		if(someItems.size()==0)
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
}