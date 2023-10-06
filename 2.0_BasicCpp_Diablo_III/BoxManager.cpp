#pragma once
#include"BoxManager.h"
#include"Room.h"
#include "BattleController.h"
#include "PlayerManager.h"
#include "Box.h"
#include "Item.h"
#include "ItemType.h"
#include "Stats.h"
#include "Player.h"
namespace diablo_III
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
					else if(eachBox->GetItemsInTheBox().size() == 0)
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Open Box " << (int) optCounter << " | Empty!" << '\n';
					}
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

		std::cout << '\n';
		return plrOpt;
	}

	void BoxManager::BreakLock(Box& aBox)
	{
		std::cout << "\n\t++++++++++++++++++++++++++++++++++\n";
		std::cout << "\tThe lock has been broken \n";
		std::cout << "\t++++++++++++++++++++++++++++++++++\n";
		aBox.GetBoxState() = Box_State::UNLOCKED;
		aBox.GetBoxLockStrength() = 0;
	}

	void BoxManager::ChoseBox()
	{
		bool quit { false };
		bool isAccepted { true };
		uint8_t plrOpt { 0 };
		uint8_t plrLockOpt { 0 };
		BattleController myBattleController(myPlayer, myRoom, myItemFactory );

		while(!quit && myPlayer.GetPlayerLifeState() == true)
		{
			plrOpt = GetPlayerBoxChoiceOpt();
			if(myRoom->GetBoxes().size()>1)
			{
				if(plrOpt - myRoom->GetBoxes().size() == 0)
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
					if(myRoom->GetBoxes().at(size_t(plrOpt ))->GetBoxState() == Box_State::LOCKED)
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
							/*isAccepted = true;
							if(plrLockOpt > 2 || plrLockOpt <= 0)
							{
								isAccepted = false;
							}*/
						}
						while(plrLockOpt > 2 || plrLockOpt <= 0);

						if(plrLockOpt == 1)
						{
							if(myRoom->GetBoxes().at(size_t(plrOpt ))->GetBoxLockStrength() <= myPlayer.GetStat(Stats::eStatIndex::eStrength))
							{
								BreakLock(*myRoom->GetBoxes().at(size_t(plrOpt )));
								PlayerInBoxChoices(myRoom->GetBoxes().at(size_t(plrOpt ))->GetItemsInTheBox());
							}
							else
							{
								std::cout << "\n\tYou don't have enough strength to break this lock! | Strength required : " << (int) myRoom->GetBoxes().at(size_t(plrOpt ))->GetBoxLockStrength() << '\n';
							}
						}
					}
					else
					{
						PlayerInBoxChoices(myRoom->GetBoxes().at(size_t(plrOpt ))->GetItemsInTheBox());
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
			while(someItems.size() * 2 - plrOpt != -1)
			{
				for(auto& eachItem : someItems)
				{
					if(eachItem != nullptr)
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: ";
						eachItem->GetStats().GetTag() == eItemTag::eArmour ? std::cout << "Equip " : std::cout << "Cosume ";
						std::cout << eachItem->GetStats().GetName() << '\n';
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Loot ";
						std::cout << eachItem->GetStats().GetName() << " | Item weight: " << (int) eachItem->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) << '\n';
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

1;				if(someItems.size() * 2 - plrOpt != -1 && !someItems.empty() && someItems[0] != nullptr)
				{
					if(plrOpt % 2 == 0)
					{
						myPlayerManager.LootItem(someItems, ((plrOpt + 1) / 2) - 1);
					}
					else if(someItems.at((size_t(plrOpt + 1) / 2 - 1))->GetStats().GetTag() == eItemTag::eArmour)
					{
						myPlayerManager.EquipArmor(someItems, ((plrOpt + 1) / 2) - 1);
					}
					else
					{
						myPlayerManager.ConsumePortion(someItems, ((plrOpt + 1) / 2) - 1);
					}
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