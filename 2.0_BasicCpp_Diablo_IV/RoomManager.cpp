#pragma once
#include <iostream>
#include <vector>
#include <Random>
#include<memory>
#include "Tools.h"
#include "RoomManager.h"
#include"Item.h"
#include "BattleController.h"
#include "PlayerManager.h"
#include"Room.h"
#include "Player.h"
#include "Door.h"

namespace diablo_IV
{
	uint8_t RoomManager::GetPlayerRoomChoiceOpt()
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		bool isAccepted { true };
		std::cout << "\n\n";

		for(auto& eachDoor : myRoom->GetDoors())
		{
				switch(eachDoor->GetDoorID())
				{
				case 1:
					std::cout << "\t[Press " << (int) ++optCounter << ']' << " Select Door1 : Connects Bone-Forged Catacombs & Lair of the Undying" << '\n';
					break;
				case 2:
					std::cout << "\t[Press " << (int)++optCounter << ']' << " Select Door2 : Connects Lair of the Undying & Diablo's Domain" << '\n';
					break;
				case 3:
					std::cout << "\t[Press " << (int)++optCounter << ']' << " Select Door3 : Connects Diablo's Domain & Halls of Eternal Night" << '\n';
					break;
				case 4:
					std::cout << "\t[Press " << (int)++optCounter << ']' << " Select Door4 : Connects Lair of the Undying & Crypt of Shadows" << '\n';
					break;
				case 5:
					std::cout << "\t[Press " << (int)++optCounter << ']' << " Select Door5 : Connects Halls of Eternal Night & Crypt of Shadows" << '\n';
					break;
				case 6:
					std::cout << "\t[Press " << (int)++optCounter << ']' << " Select Door6 : Connects Crypt of Shadows & Vault of Riches" << '\n';
					break;
				case 7:
					std::cout << "\t[Press " << (int)++optCounter << ']' << " Select Door7 : Connects Crypt of Shadows & Chamber of The Fallen King" << '\n';
					break;
				}
		}

		std::cout << "\t[Press " << (int)++optCounter << ']' << " Quit" << '\n';
		std::cout << "\n\tYour choirs : ";
		do
		{
			plrOpt = GetPlayerIntFormat();
		}
		while(plrOpt > optCounter || plrOpt <= 0);
		return plrOpt;
	}

	void RoomManager::ChoseRoom()
	{
		bool quit { false };
		uint8_t plrOpt { 0 };
		uint8_t plrLockOpt { 0 };
		BattleController myBattleController(myPlayer, myRoom, myItemFactory);

		while(!quit && myPlayer.GetPlayerLifeState() == true)
		{
			plrOpt = GetPlayerRoomChoiceOpt();
			if(plrOpt - myRoom->GetDoors().size() == 1)
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

				if(myRoom->GetDoors().at(static_cast<uint8_t>(plrOpt - 1))->GetStates() == Room_States::DOOR_STATE_LOCKED)
				{
					std::cout << "\n\t*************************\n";
					std::cout << "\tThe door is locked!\n";
					std::cout << "\t*************************\n";
					std::cout << "\t[Press 1] Break the lock \n";
					std::cout << "\t[Press 2] Cancel\n";
					std::cout << "\n\tYour choice : ";
					do
					{
						plrLockOpt = GetPlayerIntFormat();
					}
					while(plrLockOpt > 2 || plrLockOpt <= 0);

					if(plrLockOpt == 1)
					{
						if(myRoom->GetDoors().at(static_cast<uint8_t>(plrOpt - 1))->IsBreakable(myPlayer.GetStat(Stats::eStatIndex::eStrength)))
						{
							myPlayer.SetCurrentRoom(myRoom->GetDoors().at(static_cast<uint8_t>(plrOpt - 1))->GetDestinationRoom(myPlayer.GetPlayerCurrentRoom()));
						}
						myRoom->GetDoors().at(static_cast<uint8_t>(plrOpt - 1))->BreakLock(myPlayer.GetStat(Stats::eStatIndex::eStrength));
						quit = true;
						system("pause");
					}
					else
					{
						quit = true;
					}
				}
				else
				{
					myPlayer.SetCurrentRoom(myRoom->GetDoors().at(static_cast<uint8_t>(plrOpt - 1))->GetDestinationRoom(myPlayer.GetPlayerCurrentRoom()));
					quit = true;
				}
			}
		}
	}

	uint8_t RoomManager::GetPlayerRoomOpt()
	{
		uint8_t plrOpt { 0 };
		uint8_t optCounter { 0 };
		std::cout << "\tPress [" << (int)++optCounter << "] :: Show enemies in the room";

		if(myRoom->GetEnemies().empty())
		{
			std::cout << " | NONE\n";
		}
		else
		{
			std::cout << '\n';
		}

		std::cout << "\tPress [" << (int)++optCounter << "] :: Show doors in the room" << '\n';
		std::cout << "\tPress [" << (int)++optCounter << "] :: Show boxes in the room ";

		if(myRoom->GetBoxes().empty())
		{
			std::cout << " | NONE\n";
		}
		else
		{
			std::cout << '\n';
		}

		std::cout << "	Press [" << (int)++optCounter << "] :: Show items in the room ";

		if(myRoom->GetItems().empty())
		{
			std::cout << " | NONE\n";
		}
		else if(myRoom->GetItems().size() == 0)
		{
			std::cout << " | NONE\n";
		}
		else
		{
			std::cout << '\n';
		}

		std::cout << "\tPress [" << (int)++optCounter << "] :: Show inventory " << '\n';
		std::cout << "\tPress [" << (int) ++optCounter << "] :: Show player states" << '\n';
		std::cout << "\tPress [" << (int)++optCounter << "] :: Show Equipments " << '\n';
		std::cout << "\tPress [" << (int)++optCounter << "] :: Open Spellbook " << '\n';
		std::cout << "\n\tYour choice: ";
		do
		{
			plrOpt = GetPlayerIntFormat();
		}
		while(plrOpt > optCounter || plrOpt <= 0);
		return plrOpt;
	}

	bool RoomManager::IsLoot(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt)
	{
		for(int i = 0; i < aPlrIndexTranslator.size(); i++)
		{
			if(aPlayerOpt == aPlrIndexTranslator[i][1])
			{
				return true;
			}
		}
		return false;
	}

	uint8_t RoomManager::GetIndex(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt)
	{
		for(int i = 0; i < aPlrIndexTranslator.size(); i++)
		{
			for(int j = 0; j < aPlrIndexTranslator[0].size(); j++)
			{
				if(aPlayerOpt == aPlrIndexTranslator[i][j])
				{
					return i + 1;
				}
			}
		}
		return -1;
	}

	void RoomManager::PlayerRoomObjectChoices()
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		PlayerManager myPlayerManager(myPlayer);
		std::vector<std::vector<uint8_t>> plrIndexTranslator;
		std::cout << "\n\n";

		if(!myRoom->GetItems().empty())
		{
			while(myRoom->GetItems().size() - plrOpt != -1)
			{

				for(auto& eachItem : myRoom->GetItems())
				{
					std::cout << "\t[Press " << (int) ++optCounter << " ] :: Loot ";

					std::cout << eachItem->GetStats().GetName() << " | Item weight : " <<
						(int) eachItem->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) << '\n';
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

				if(myRoom->GetItems().size() - plrOpt != -1)
				{
					myPlayerManager.LootItem(myRoom->GetItems(), plrOpt - 1);
					plrOpt = 0;

				}
			}
		}
		else
		{
			std::cout << "\tEmpty!\n";
			system("pause");
			return;
		}
	}
}

