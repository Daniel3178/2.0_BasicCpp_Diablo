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
#include "Player.h"
#include <vector>

namespace diablo_III
{
	int diablo_III::GetPlayerIntFormat()
	{
		unsigned int usrInput { 0 };
		std::cin >> usrInput;
		while(std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			std::cout << "Please answer with only digits : " << '\n';
			std::cin >> usrInput;
		}
		return usrInput;
	}

	void GameManager::Play(Player* aPlayer, std::shared_ptr<Room>& aRoom)
	{
		PlayerManager myPlayerManager(*aPlayer);
		BattleController myBattleController(*aPlayer, aRoom, myItemFactory);
		RoomManager myRoomManager(*aPlayer, aRoom, myItemFactory);
		BoxManager myBoxManager(*aPlayer, aRoom, myItemFactory);
		InventoryManager myInventoryManager(*aPlayer, aRoom->GetItems());

		switch(aRoom->GetRoomID())
		{
		case eRoomID::eRoom_A:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Bone-Forged Catacombs\n";
			std::cout << "\t========================\n";
			break;
		case eRoomID::eRoom_B:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Lair of the Undying\n";
			std::cout << "\t========================\n";
			break;
		case eRoomID::eRoom_C:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Diablo's Domain\n";
			std::cout << "\t========================\n";
			break;
		case eRoomID::eRoom_D:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Halls of Eternal Night\n";
			std::cout << "\t========================\n";
			break;
		case eRoomID::eRoom_E:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Crypt of Shadows\n";
			std::cout << "\t========================\n";
			break;
		case eRoomID::eRoom_F:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Vault of Riches\n";
			std::cout << "\t========================\n";
			break;
		case eRoomID::eRoom_G:
			std::cout << "\n\t========================";
			std::cout << "\n\tYou are in Chamber of The Fallen King\n";
			std::cout << "\t========================\n";
			break;
		default:
			break;
		}
		switch(myRoomManager.GetPlayerRoomOpt())
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
		myMapBuilder.CreateMap(myItemFactory, myEnemyFactory);
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
		while(myPlayer.GetPlayerLifeState() == true && myMapBuilder.GetRoomByID(eRoomID::eRoom_C)->GetEnemies().size() > 0)
		{
			switch(myPlayer.GetPlayerCurrentRoom())
			{
			case diablo_III::eRoomID::eRoom_A:
				while(myPlayer.GetPlayerCurrentRoom() == eRoomID::eRoom_A && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(eRoomID::eRoom_A));
					if(myPlayer.GetPlayerSpelState())
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_III::eRoomID::eRoom_B:
				while(myPlayer.GetPlayerCurrentRoom() == eRoomID::eRoom_B && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(eRoomID::eRoom_B));
					if(myPlayer.GetPlayerSpelState())
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_III::eRoomID::eRoom_C:
				while(myPlayer.GetPlayerCurrentRoom() == eRoomID::eRoom_C && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(eRoomID::eRoom_C));
					if(myPlayer.GetPlayerSpelState())
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_III::eRoomID::eRoom_D:
				while(myPlayer.GetPlayerCurrentRoom() == eRoomID::eRoom_D && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(eRoomID::eRoom_D));
					if(myPlayer.GetPlayerSpelState())
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_III::eRoomID::eRoom_E:
				while(myPlayer.GetPlayerCurrentRoom() == eRoomID::eRoom_E && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(eRoomID::eRoom_E));
					if(myPlayer.GetPlayerSpelState())
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_III::eRoomID::eRoom_F:
				while(myPlayer.GetPlayerCurrentRoom() == eRoomID::eRoom_F && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(eRoomID::eRoom_F));
					if(myPlayer.GetPlayerSpelState())
					{
						myPlayerManager.CountSpelTimer();
					}
				}
				break;
			case diablo_III::eRoomID::eRoom_G:
				while(myPlayer.GetPlayerCurrentRoom() == eRoomID::eRoom_G && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myMapBuilder.GetRoomByID(eRoomID::eRoom_G));
					if(myPlayer.GetPlayerSpelState())
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
