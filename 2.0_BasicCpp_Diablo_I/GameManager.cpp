
#include "GameManager.h"
#include <Random>

namespace diablo_I
{

	GameManager::GameManager()
	{}

	int GameManager::GetPlayerIntFormat()
	{
		unsigned int usrInput { 0 };
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

	uint8_t GameManager::GetPlayerCombatOption(Player* aPlayer, Room* aRoom)
	{

		uint8_t enemyHp { 0 };
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		bool isAccepted { true };
		std::cout << "\n\n";

		for (auto& eachEnemy : *aRoom->GetEnemies())
		{
			switch (eachEnemy->GetEnemyType())
			{
			case Enemy_Tag::ENEMY_TYPE_SKELETON:
				enemyHp = eachEnemy->GetEnemyHp();
				std::cout << "[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: skeleton | HP: " << (int) enemyHp << '\n';
				break;
			case Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT:
				enemyHp = eachEnemy->GetEnemyHp();
				std::cout << "[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: vampire | HP: " << (int) enemyHp << '\n';
				break;
			case Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT:
				enemyHp = eachEnemy->GetEnemyHp();
				std::cout << "[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: dragon | HP: " << (int) enemyHp << '\n';
				break;
			default:
				break;
			}
		}
		optCounter == 0 ? std::cout << "Area is cleard!\n" : std::cout << "";
		std::cout << "\n[Press " << (int)++optCounter << ']' << " Change weapon | current weapon : " << aPlayer->GetPlayerCurrentWeapon() << '\n';
		std::cout << "[Press " << (int)++optCounter << ']' << " Show player states" << '\n';
		std::cout << "[Press " << (int) ++optCounter << ']' << " Quit" << '\n';
		std::cout << "Your choirs : ";
		do
		{
			plrOpt = GetPlayerIntFormat();
			isAccepted = (plrOpt > optCounter || plrOpt <= 0) ? false : true;
		}
		while (!isAccepted);

		return plrOpt;
	}

	bool GameManager::ExistEnemies(std::vector<Enemy*>* someEnemies)
	{
		if (someEnemies->size() > 0)
		{
			return true;
		}
		else
			return false;
	}

	void GameManager::CheckEnemyStateInRoom(Room* aRoom, uint8_t anIndex)
	{
		if (aRoom->GetEnemies()->at(anIndex)->GetEnemyHp() <= 0)
		{
			delete aRoom->GetEnemies()->at(anIndex);
			aRoom->GetEnemies()->at(anIndex) = nullptr;
			aRoom->GetEnemies()->erase(aRoom->GetEnemies()->begin() + anIndex);
		}
	}


	void GameManager::Combat(Player* aPlayer, Room* aRoom)
	{

		bool inCombatMode { true };
		uint8_t plrOpt { 0 };
		while (inCombatMode && aPlayer->GetPlayerLifeState() == true)
		{
			plrOpt = GetPlayerCombatOption(aPlayer, aRoom);
			if (plrOpt <= aRoom->GetEnemies()->size())
			{
				aRoom->GetEnemies()->at((size_t) plrOpt - 1)->EnemyGetDamage(aPlayer->GetPlayerAttackDamageValue());
				//check if enemies are deade
				CheckEnemyStateInRoom(aRoom, (size_t) plrOpt - 1);
				RandomEnemyAttack(aPlayer, aRoom->GetEnemies());

			}
			else if (plrOpt - aRoom->GetEnemies()->size() == 1)
			{
				// change weapon
			}
			else if (plrOpt - aRoom->GetEnemies()->size() == 2)
			{
				aPlayer->DisplayPlayerStates();
			}
			else
			{
				// quit
				inCombatMode = false;
			}
		}
	}
	void GameManager::RandomEnemyAttack(Player* aPlayer, std::vector<Enemy*>* someEnemies)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, (uint8_t) (someEnemies->size() + 2));

		std::cout << "\n\n";
		for (int i = 0, j = dis(gen); i < someEnemies->size() && aPlayer->GetPlayerLifeState() == true; i += (j % 3) == 0 ? j % 3 + 1 : j % 3, j = dis(gen))
		{
			aPlayer->PlayerGetDamage(someEnemies->at(i)->GetEnemyAttackDamageValue());
			if (someEnemies->at(i)->GetEnemyType() == Enemy_Tag::ENEMY_TYPE_SKELETON)
			{
				std::cout << "A skeleton attacked! | Your current hp : " << aPlayer->GetPlayerHp() << '\n';
			}
			else if (someEnemies->at(i)->GetEnemyType() == Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT)
			{
				std::cout << "A vampire attacked! | Your current hp : " << aPlayer->GetPlayerHp() << '\n';
			}
			else if (someEnemies->at(i)->GetEnemyType() == Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT)
			{
				std::cout << "A dragon attacked! | Your current hp : " << aPlayer->GetPlayerHp() << '\n';
			}
		}

	}
	uint8_t GameManager::GetPlayerRoomChoiceOpt(std::vector<Door*>* someDoors)
	{
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		bool isAccepted { true };
		std::cout << "\n\n";
		for (auto& eachDoor : *someDoors)
		{
			switch (eachDoor->GetDoorID())
			{
			case 1:
				std::cout << "[Press " << (int) ++optCounter << ']' << " Select Door1 : Connects Room A & B" << '\n';
				break;
			case 2:
				std::cout << "[Press " << (int)++optCounter << ']' << " Select Door2 : Connects Room A & D" << '\n';
				break;
			case 3:
				std::cout << "[Press " << (int)++optCounter << ']' << " Select Door3 : Connects Room A & E" << '\n';
				break;
			case 4:
				std::cout << "[Press " << (int)++optCounter << ']' << " Select Door4 : Connects Room B & C" << '\n';
				break;
			case 5:
				std::cout << "[Press " << (int)++optCounter << ']' << " Select Door5 : Connects Room C & D" << '\n';
				break;
			}
		}

		std::cout << "[Press " << (int)++optCounter << ']' << " Quit" << '\n';
		std::cout << "Your choirs : ";
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

	void GameManager::ChoseRoom(Player* aPlayer, Room* aRoom)
	{
		bool quit { false };
		bool isAccepted { true };
		uint8_t plrOpt { 0 };
		uint8_t plrLockOpt { 0 };
		while (!quit && aPlayer->GetPlayerLifeState() == true)
		{
			plrOpt = GetPlayerRoomChoiceOpt(aRoom->GetDoors());
			if (plrOpt - aRoom->GetDoors()->size() == 1)
			{
				quit = true;
			}
			else if (ExistEnemies(aRoom->GetEnemies()))
			{
				RandomEnemyAttack(aPlayer, aRoom->GetEnemies());
				Combat(aPlayer, aRoom);
				quit = true;
			}
			else
			{
				if (aRoom->GetDoors()->at((size_t) plrOpt - 1)->GetStates() == Room_States::DOOR_STATE_LOCKED)
				{
					std::cout << "\n\nThe Door is locked! \n\n";
					std::cout << "[Press 1] Break the lock \n";
					std::cout << "[Press 2] Cancel\n";
					std::cout << "Your choice : ";
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
						if (aRoom->GetDoors()->at((size_t) plrOpt - 1)->IsBreakable(aPlayer->GetPlayerStrength()))
						{
							aPlayer->SetCurrentRoom(aRoom->GetDoors()->at((size_t) plrOpt - 1)->GetDestinationRoom(aPlayer->GetPlayerCurrentRoom()));
						}
						aRoom->GetDoors()->at((size_t) plrOpt - 1)->BreakLock(aPlayer->GetPlayerStrength());
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
					aPlayer->SetCurrentRoom(aRoom->GetDoors()->at((size_t) plrOpt - 1)->GetDestinationRoom(aPlayer->GetPlayerCurrentRoom()));
					quit = true;
				}

			}
		}
	}

	uint8_t GameManager::GetPlayerRoomOpt(const std::string& aPlayerCurrentWeapon, std::vector<Enemy*>* someEnemies)
	{
		uint8_t plrOpt { 0 };
		bool isAccepted { true };

		if (ExistEnemies(someEnemies))
		{
			std::cout << "	Press [1] :: There are enemies in the room, FIGHT!" << '\n';
		}
		else
		{
			std::cout << "	Press [1] :: There are no enemies in the room, the option is deactivated" << '\n';
		}
		std::cout << "	Press [2] :: There are doors in the room, CHOSE ONE!" << '\n';
		std::cout << "	Press [3] :: Right now there are no boxes in the room, the option is deactivated " << '\n';
		std::cout << "	Press [4] :: Change weapon | current weapon : " << aPlayerCurrentWeapon << '\n';
		std::cout << "	Press [5] :: Show player states" << '\n';
		std::cout << "	Your choice: ";
		do
		{
			isAccepted = true;
			plrOpt = GetPlayerIntFormat();
			if (plrOpt > 5 || plrOpt <= 0)
			{
				isAccepted = false;
			}
		}
		while (!isAccepted);

		return plrOpt;

	}

	void GameManager::Play(Player* aPlayer, Room* aRoom)
	{
		switch (aRoom->GetRoomID())
		{
		case Room_States::ROOM_A:
			std::cout << "\n You are in Room A\n";
			break;
		case Room_States::ROOM_B:
			std::cout << "\n You are in Room B\n";
			break;
		case Room_States::ROOM_C:
			std::cout << "\n You are in Room C\n";
			break;
		case Room_States::ROOM_D:
			std::cout << "\n You are in Room D\n";
			break;
		case Room_States::ROOM_E:
			std::cout << "\n You are in Room E\n";
			break;

		default:
			break;
		}
		switch (GetPlayerRoomOpt(aPlayer->GetPlayerName(), aRoom->GetEnemies()))
		{
		case 1:
			Combat(aPlayer, aRoom);
			break;
		case 2:
			ChoseRoom(aPlayer, aRoom);
			break;
		case 3:
			//boxes
			break;
		case 4:
			//change weapon
			break;
		case 5:
			aPlayer->DisplayPlayerStates();
			break;
		default:
			break;
		}
	}

	void GameManager::Run()
	{
		RoomManager myRoomManager;
		myRoomManager.CreateMap();
		uint8_t counter { 0 };
		Player myPlayer("Here007");
		std::cout << "\n In Eldoria, the return of the dreaded dragon Drakonar cast fear upon the land. \n"
			<< "The desperate cries of the people reached the ears of a young orphan, Ava.Determined to\n"
			<< "bring salvation,she embarked on a perilous quest armed with a mystical blade.Guided by \n"
			<< "ancient propheciesand aided by loyal companions, Ava faced deadly trialsand conquered her\n "
			<< "fears.At last, she stood before the menacing dragon, clashing with unwavering resolve.With\n"
			<< "a final strike, Ava vanquished the beast, liberating the realm.Eldoria rejoiced, hailing\n"
			<< "Ava as their hero.Yet, as peace settled, a new dragon emerged, and a new hero's destiny awaited\n"
			<< "to face this fresh threat. The dragon lives in one of the rooms, find it and kill it to bring back\n"
			<< "the peace once more!\n";
		uint8_t counte { 0 };
		while (myPlayer.GetPlayerLifeState() == true
			&& myRoomManager.GetRoomByID(Room_States::ROOM_E)->GetEnemies()->size() > 0)
		{

			switch (myPlayer.GetPlayerCurrentRoom())
			{
			case diablo_I::Room_States::ROOM_A:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_A && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myRoomManager.GetRoomByID(Room_States::ROOM_A));
				}
				break;
			case diablo_I::Room_States::ROOM_B:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_B && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myRoomManager.GetRoomByID(Room_States::ROOM_B));
				}

				break;
			case diablo_I::Room_States::ROOM_C:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_C && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myRoomManager.GetRoomByID(Room_States::ROOM_C));
				}

				break;
			case diablo_I::Room_States::ROOM_D:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_D && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myRoomManager.GetRoomByID(Room_States::ROOM_D));
				}
				break;
			case diablo_I::Room_States::ROOM_E:
				while (myPlayer.GetPlayerCurrentRoom() == Room_States::ROOM_E && myPlayer.GetPlayerLifeState() == true)
				{
					Play(&myPlayer, myRoomManager.GetRoomByID(Room_States::ROOM_E));
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
