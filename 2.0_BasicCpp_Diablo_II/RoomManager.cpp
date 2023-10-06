#include "RoomManager.h"
#include "BattleController.h"
#include "PlayerManager.h"
#include"Room.h"

namespace diablo_II 
{
	uint8_t RoomManager::GetPlayerRoomChoiceOpt() 
	{
		uint8_t optCounter{ 0 };
		uint8_t plrOpt{ 0 };
		bool isAccepted{ true };
		std::cout << "\n\n";
	
		for (auto& eachDoor : *myRoom.GetDoors()) 
		{
			switch (eachDoor->GetDoorID()) 
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
			isAccepted = true;
			plrOpt = GetPlayerIntFormat();
			if (plrOpt > optCounter || plrOpt <= 0) 
			{
				isAccepted = false;
			}
		} 
		while (!isAccepted);
		return plrOpt;
	}

	void RoomManager::ChoseRoom() 
	{
		bool quit{ false };
		bool isAccepted{ true };
		uint8_t plrOpt{ 0 };
		uint8_t plrLockOpt{ 0 };
		BattleController myBattleController(myPlayer, myRoom);

		while (!quit && myPlayer.GetPlayerLifeState() == true) 
		{
			plrOpt = GetPlayerRoomChoiceOpt();
			if (plrOpt - myRoom.GetDoors()->size() == 1) 
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
				if (myRoom.GetDoors()->at((size_t)plrOpt - 1)->GetStates() == Room_States::DOOR_STATE_LOCKED) 
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
						isAccepted = true;
						if (plrLockOpt > 2 || plrLockOpt <= 0) 
						{
							isAccepted = false;
						}
					} 
					while (!isAccepted);

					if (plrLockOpt == 1) 
					{
						if (myRoom.GetDoors()->at((size_t)plrOpt - 1)->IsBreakable(myPlayer.GetPlayerStrength())) 
						{
							myPlayer.SetCurrentRoom(myRoom.GetDoors()->at((size_t)plrOpt - 1)->GetDestinationRoom(myPlayer.GetPlayerCurrentRoom()));
						}
						myRoom.GetDoors()->at((size_t)plrOpt - 1)->BreakLock(myPlayer.GetPlayerStrength());
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
					myPlayer.SetCurrentRoom(myRoom.GetDoors()->at((size_t)plrOpt - 1)->GetDestinationRoom(myPlayer.GetPlayerCurrentRoom()));
					quit = true;
				}
			}
		}
	}

	uint8_t RoomManager::GetPlayerRoomOpt() 
	{
		uint8_t plrOpt{ 0 };
		bool isAccepted{ true };
		uint8_t optCounter{ 0 };
		std::cout << "\tPress [" << (int)++optCounter << "] :: Show enemies in the room";
		
		if (myRoom.GetEnemies() == nullptr) 
		{
			std::cout << " | NONE\n";
		}
		else if (myRoom.GetEnemies()->size() == 0) 
		{
			std::cout << " | NONE\n";
		}
		else {
			std::cout << '\n';
		}

		std::cout << "\tPress [" << (int)++optCounter << "] :: Show doors in the room" << '\n';
		std::cout << "\tPress [" << (int)++optCounter << "] :: Show boxes in the room ";
		
		if (myRoom.GetBoxes() == nullptr) 
		{
			std::cout << " | NONE\n";
		}
		else if (myRoom.GetBoxes()->size() == 0) 
		{
			std::cout << " | NONE\n";
		}
		else 
		{
			std::cout << '\n';
		}
		
		std::cout << "	Press [" << (int)++optCounter << "] :: Show items in the room ";
		
		if (myRoom.GetItems() == nullptr) 
		{
			std::cout << " | NONE\n";
		}
		else if (myRoom.GetItems()->size() == 0) 
		{
			std::cout << " | NONE\n";
		}
		else 
		{
			std::cout << '\n';
		}
		
		std::cout << "\tPress [" << (int)++optCounter << "] :: Show inventory " /*<< myPlayer.GetPlayerCurrentWeapon()*/ << '\n';
		std::cout << "\tPress [" << (int) ++optCounter << "] :: Show player states" << '\n';
		std::cout << "\n\tYour choice: ";
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
		return plrOpt;
	}

	bool RoomManager::IsLoot(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt) 
	{
		for (int i = 0; i < aPlrIndexTranslator.size(); i++) 
		{
			for (int j = 0; j < aPlrIndexTranslator[0].size(); j++) 
			{
				if (aPlayerOpt == aPlrIndexTranslator[i][1]) 
				{
					return true;
				}
			}
		}
		return false;
	}

	uint8_t RoomManager::GetIndex(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt) 
	{
		for (int i = 0; i < aPlrIndexTranslator.size(); i++) 
		{
			for (int j = 0; j < aPlrIndexTranslator[0].size(); j++) 
			{
				if (aPlayerOpt == aPlrIndexTranslator[i][j]) 
				{
					return i;
				}
			}
		}
		return -1;
	}

	void RoomManager::PlayerRoomObjectChoices() 
	{
		uint8_t optCounter{ 0 };
		uint8_t plrOpt{ 0 };
		uint8_t notSpelCounter{ 0 };
		uint8_t spelCounter{ 0 };
		PlayerManager myPlayerManager(myPlayer);
		bool isAccepted{ true };
		std::vector<std::vector<uint8_t>> plrIndexTranslator;
		std::cout << "\n\n";
		
		if (myRoom.GetItems() != nullptr) 
		{
			while ((notSpelCounter * 2) + spelCounter - plrOpt != -1) 
			{
				for (auto& eachItem : *myRoom.GetItems()) 
				{
					if (eachItem != nullptr) 
					{
						std::cout << "\t[Press " << (int) ++optCounter << " ] :: ";
						if (eachItem->GetItemType() == Item_Tag::WEARABLE) 
						{
							std::cout << "Equip ";
							notSpelCounter++;
						}
						else if (eachItem->GetItemType() == Item_Tag::CONSUMABLE) 
						{
							std::cout << "Consume ";
							notSpelCounter++;
						}
						else if (eachItem->GetItemType() == Item_Tag::SPEL) 
						{
							std::cout << "Aqcuire ";
							plrIndexTranslator.push_back({ optCounter, 0 });
							spelCounter++;
						}
						std::cout << eachItem->GetItemName() << '\n';
						
						if (eachItem->GetItemType() != Item_Tag::SPEL) 
						{
							std::cout << "\t[Press " << (int) ++optCounter << " ] :: Loot ";
							plrIndexTranslator.push_back({ uint8_t(optCounter - 1), optCounter });
							std::cout << eachItem->GetItemName() << " | Item weight: " << (int)eachItem->GetItemWeight() << '\n';
						}
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

				if ((notSpelCounter * 2) + spelCounter - plrOpt != -1) 
				{
					if (IsLoot(plrIndexTranslator, plrOpt)) 
					{
						myPlayerManager.LootItem(myRoom.GetItems(), GetIndex(plrIndexTranslator, plrOpt));
					}
					else if (myRoom.GetItems()->at(GetIndex(plrIndexTranslator, plrOpt))->GetItemType() == Item_Tag::WEARABLE) 
					{
						myPlayerManager.EquipArmor(myRoom.GetItems(), GetIndex(plrIndexTranslator, plrOpt));
					}
					else if (myRoom.GetItems()->at(GetIndex(plrIndexTranslator, plrOpt))->GetItemType() == Item_Tag::CONSUMABLE) 
					{
						myPlayerManager.ConsumePortion(myRoom.GetItems(), GetIndex(plrIndexTranslator, plrOpt));
					}
					else if (myRoom.GetItems()->at(GetIndex(plrIndexTranslator, plrOpt))->GetItemType() == Item_Tag::SPEL) 
					{
						std::cout << "\n\t*************************\n";
						std::cout << "\nYou have aquired a spel!\n";
						std::cout << "\t*************************\n";
						myPlayerManager.ActivatePlayerSpel(myRoom.GetItems(), GetIndex(plrIndexTranslator, plrOpt));
					}
					plrOpt = 0;
					plrIndexTranslator.clear();
					notSpelCounter = 0;
					spelCounter = 0;
				}
				else 
				{
					return;
				}
			}
		}
	}
}