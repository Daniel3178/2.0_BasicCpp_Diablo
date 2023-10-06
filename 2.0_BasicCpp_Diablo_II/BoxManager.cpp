#pragma once
#include"BoxManager.h"
#include"Room.h"
#include "BattleController.h"
#include "PlayerManager.h"
#include "Box.h"
#include "Item.h"

namespace diablo_II 
{
	uint8_t BoxManager::GetPlayerBoxChoiceOpt() 
	{
		uint8_t optCounter{ 0 };
		uint8_t plrOpt{ 0 };
		bool isAccepted{ true };
		std::cout << "\n\n";
	
		if (myRoom.GetBoxes() != nullptr) 
		{
			for (auto& eachBox : *myRoom.GetBoxes()) 
			{
				if (eachBox != nullptr) 
				{
					if (eachBox->GetItemsInTheBox()== nullptr) 
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Open Box " << (int)optCounter <<" | Empty!" << '\n';
					}
					else if ( eachBox->GetItemsInTheBox()->size() == 0) 
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Open Box " << (int)optCounter << " | Empty!" << '\n';
					}
					else 
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Open Box " << (int)optCounter << '\n';
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
			isAccepted = true;
			plrOpt = GetPlayerIntFormat();
			if (plrOpt > optCounter || plrOpt <= 0) 
			{
				isAccepted = false;
			}
		} 
		while (!isAccepted);

		std::cout << '\n';
		return plrOpt;
	}

	void BoxManager::BreakLock( Box& aBox ) 
	{
			std::cout << "\n\t++++++++++++++++++++++++++++++++++\n";
			std::cout << "\tThe lock has been broken \n";
			std::cout << "\t++++++++++++++++++++++++++++++++++\n";
			aBox.GetBoxState() = Box_State::UNLOCKED;
			aBox.GetBoxLockStrength() = 0;
	}

	void BoxManager::ChoseBox() 
	{
		bool quit{ false };
		bool isAccepted{ true };
		uint8_t plrOpt{ 0 };
		uint8_t plrLockOpt{ 0 };
		BattleController myBattleController(myPlayer, myRoom);
	
		while (!quit && myPlayer.GetPlayerLifeState() == true) 
		{
			plrOpt = GetPlayerBoxChoiceOpt();
			if (myRoom.GetBoxes() != nullptr) 
			{
				if (plrOpt - myRoom.GetBoxes()->size() == 1) 
				{
					quit = true;
				}
				else if (myBattleController.ExistEnemies()) 
				{
					myBattleController.RandomEnemyAttack();
					myBattleController.Combat();
					quit = true;
				}
				else 
				{
					if (myRoom.GetBoxes()->at(size_t(plrOpt -1))->GetBoxState() == Box_State::LOCKED) 
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
							isAccepted = true;
							if (plrLockOpt > 2 || plrLockOpt <= 0) 
							{
								isAccepted = false;
							}
						} 
						while (!isAccepted);

						if (plrLockOpt == 1) 
						{
							if (myRoom.GetBoxes()->at(size_t(plrOpt - 1))->GetBoxLockStrength() <= myPlayer.GetPlayerStrength()) 
							{
								BreakLock(*myRoom.GetBoxes()->at(size_t(plrOpt - 1)));
								PlayerInBoxChoices(myRoom.GetBoxes()->at(size_t(plrOpt - 1))->GetItemsInTheBox());
							}
							else 
							{
								std::cout << "\n\tYou don't have enough strength to break this lock! | Strength required : "<< (int)myRoom.GetBoxes()->at(size_t(plrOpt - 1))->GetBoxLockStrength()<< '\n';
							}
						}
					}
					else 
					{
						PlayerInBoxChoices(myRoom.GetBoxes()->at(size_t(plrOpt - 1))->GetItemsInTheBox());
					}
				}
			}
			else 
			{
				quit = true;
			}
		}
	}

	void BoxManager::PlayerInBoxChoices( std::vector<Item*>* someItems) 
	{
		uint8_t optCounter{ 0 };
		uint8_t plrOpt{ 0 };
		bool isAccepted{ true };
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\n";

		if (someItems != nullptr) 
		{
			while (someItems->size() * 2 - plrOpt != -1) 
			{
				for (auto& eachItem : *someItems) 
				{
					if (eachItem != nullptr) 
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: ";
						eachItem->GetItemType() == Item_Tag::WEARABLE ? std::cout << "Equip " : std::cout << "Cosume ";
						std::cout << eachItem->GetItemName() << '\n';
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: Loot ";
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

				if (someItems->size() * 2 - plrOpt != -1) 
				{
					if (plrOpt % 2 == 0) 
					{
						myPlayerManager.LootItem(someItems, ((plrOpt + 1) / 2) - 1);
					}
					else if (someItems->at((size_t(plrOpt + 1) / 2 - 1))->GetItemType() == Item_Tag::WEARABLE) 
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

		if (someItems == nullptr) 
		{
			std::cout << "\t[Press " << (int) ++optCounter << " ] :: Quit \n";
			std::cout << "\n\tYour choirs : ";

			do 
			{
				isAccepted = true;
				plrOpt = GetPlayerIntFormat();
				if (plrOpt > optCounter || plrOpt <= 0) {
					isAccepted = false;
				}
			}
			while (!isAccepted);
			return;
		}
	}
}