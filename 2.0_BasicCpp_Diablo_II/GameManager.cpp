#pragma once
#include "GameManager.h"
#include "Item.h"
#include"Box.h"
#include <Random>
#include "PlayerManager.h"
#include "BattleController.h"
#include "RoomManager.h"
#include "BoxManager.h"
#include "InventoryManager.h"

namespace diablo_II 
{
	int diablo_II::GetPlayerIntFormat()
	{
		unsigned int usrInput{ 0 };
		std::cin >> usrInput;
		while (std::cin.fail() || std::cin.peek() != '\n') 
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			std::cout << "Please answer with only digits : " << '\n';
			std::cin >> usrInput;
		}
		return usrInput;
	}

	void GameManager::Play(Player* aPlayer, Room* aRoom) 
	{
		PlayerManager myPlayerManager(*aPlayer);
		BattleController myBattleController(*aPlayer, *aRoom);
		RoomManager myRoomManager(*aPlayer, *aRoom);
		BoxManager myBoxManager(*aPlayer, *aRoom);
		InventoryManager myInventoryManager(*aPlayer, aRoom->GetItems());

		switch (aRoom->GetRoomID())
		{
		case Room_States::ROOM_A:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Bone-Forged Catacombs\n";
			std::cout << "\t========================\n";
			break;
		case Room_States::ROOM_B:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Lair of the Undying\n";
			std::cout << "\t========================\n";
			break;
		case Room_States::ROOM_C:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Diablo's Domain\n";
			std::cout << "\t========================\n";
			break;
		case Room_States::ROOM_D:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Halls of Eternal Night\n";
			std::cout << "\t========================\n";
			break;
		case Room_States::ROOM_E:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Crypt of Shadows\n";
			std::cout << "\t========================\n";
			break;		
		case Room_States::ROOM_F:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Vault of Riches\n";
			std::cout << "\t========================\n";
			break;		
		case Room_States::ROOM_G:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Chamber of The Fallen King\n";
			std::cout << "\t========================\n";
			break;
		default:
			break;
		}
		switch (myRoomManager.GetPlayerRoomOpt())
		{
		case 1:
			myBattleController.Combat();
			break;
		case 2:
			myRoomManager.ChoseRoom();
			break;
		case 3:
			myBoxManager.ChoseBox();
			break;
		case 4:
			myRoomManager.PlayerRoomObjectChoices();
			break;
		case 5:
			myInventoryManager.PlayerInventoryChoices();
			break;
		case 6:
			myPlayerManager.DisplayPlayerStates();
			break;
		default:
			break;
		}
	}

	void GameManager::Run() 
	{
		MapBuilder myMapBuilder;
		myMapBuilder.CreateMap();
		Player myPlayer("Hero007");
		PlayerManager myPlayerManager(myPlayer);

		std::cout << "\n In Eldoria, the return of the dreaded diablo Drakonar cast fear upon the land. \n"
			<< "The desperate cries of the people reached the ears of a young orphan, Ava.Determined to\n"
			<< "bring salvation,she embarked on a perilous quest armed with a mystical blade.Guided by \n"
			<< "ancient propheciesand aided by loyal companions, Ava faced deadly trialsand conquered her\n "
			<< "fears.At last, she stood before the menacing diablo, clashing with unwavering resolve.With\n"
			<< "a final strike, Ava vanquished the beast, liberating the realm.Eldoria rejoiced, hailing\n"
			<< "Ava as their hero.Yet, as peace settled, a new diablo emerged, and a new hero's destiny awaited\n"
			<< "to face this fresh threat. The diablo lives in one of the rooms, find it and kill it to bring back\n"
			<< "the peace once more!\n";
		while (myPlayer.GetPlayerLifeState() == true && myMapBuilder.GetRoomByID(Room_States::ROOM_C)->GetEnemies()->size() > 0) 
		{
			switch (myPlayer.GetPlayerCurrentRoom())
			{
			case diablo_II::Room_States::ROOM_A:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_A && myPlayer.GetPlayerLifeState() == true) 
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(Room_States::ROOM_A));
					if (myPlayer.GetPlayerSpelState()) 
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_II::Room_States::ROOM_B:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_B && myPlayer.GetPlayerLifeState() == true) 
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(Room_States::ROOM_B));
					if (myPlayer.GetPlayerSpelState()) 
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_II::Room_States::ROOM_C:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_C && myPlayer.GetPlayerLifeState() == true) 
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(Room_States::ROOM_C));
					if (myPlayer.GetPlayerSpelState()) 
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_II::Room_States::ROOM_D:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_D && myPlayer.GetPlayerLifeState() == true) 
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(Room_States::ROOM_D));
					if (myPlayer.GetPlayerSpelState()) 
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_II::Room_States::ROOM_E:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_E && myPlayer.GetPlayerLifeState() == true) 
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(Room_States::ROOM_E));
					if (myPlayer.GetPlayerSpelState()) 
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_II::Room_States::ROOM_F:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_F && myPlayer.GetPlayerLifeState() == true) 
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(Room_States::ROOM_F));
					if (myPlayer.GetPlayerSpelState()) 
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_II::Room_States::ROOM_G:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_G && myPlayer.GetPlayerLifeState() == true) 
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(Room_States::ROOM_G));
					if (myPlayer.GetPlayerSpelState()) 
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			default:
				break;
			}
		}
		myPlayer.GetPlayerLifeState() ? std::cout << "\nGood Job!" : std::cout << "\nYou have been killed by an enemy!\n";
		system("pause");
	}
}
