#pragma once
#include "BattleController.h"
#include "Room.h"
#include "PlayerManager.h"
#include <random>

namespace diablo_II 
{
	bool BattleController::ExistEnemies() 
	{
		if (myRoom.GetEnemies()->size() > 0) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void BattleController::RandomEnemyAttack() 
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, (uint8_t)(myRoom.GetEnemies()->size() + 2));
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\t*********************************************************\n";

		for (int i = 0, j = dis(gen); i < myRoom.GetEnemies()->size() && myPlayer.GetPlayerLifeState() == true; i += (j % 3) == 0 ? j % 3 + 1 : j % 3, j = dis(gen)) 
		{
			myPlayerManager.PlayerGetDamage(myRoom.GetEnemies()->at(i)->GetEnemyAttackDamageValue());
			if (myRoom.GetEnemies()->at(i)->GetEnemyType() == Enemy_Tag::ENEMY_TYPE_SKELETON) 
			{
				std::cout << "\tA skeleton attacked! | Your current hp : " << myPlayer.GetPlayerHp() << '\n';
			}
			else if (myRoom.GetEnemies()->at(i)->GetEnemyType() == Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT) 
			{
				std::cout << "\tA vampire attacked! | Your current hp : " << myPlayer.GetPlayerHp() << '\n';
			}
			else if (myRoom.GetEnemies()->at(i)->GetEnemyType() == Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT) 
			{
				std::cout << "\tA diablo attacked! | Your current hp : " << myPlayer.GetPlayerHp() << '\n';
			}
		}
		std::cout << "\t*********************************************************\n";
	}

	void BattleController::CheckEnemyStateInRoom(uint8_t anIndex) 
	{
		if (myRoom.GetEnemies()->at(anIndex)->GetEnemyHp() <= 0) 
		{
			delete myRoom.GetEnemies()->at(anIndex);
			myRoom.GetEnemies()->at(anIndex) = nullptr;
			myRoom.GetEnemies()->erase(myRoom.GetEnemies()->begin() + anIndex);
		}
	}

	uint8_t BattleController::GetPlayerCombatOption() 
	{
		uint16_t enemyHp{ 0 };
		uint8_t optCounter{ 0 };
		uint8_t plrOpt{ 0 };
		bool isAccepted{ true };
		std::cout << "\n\n";

		for (auto& eachEnemy : *myRoom.GetEnemies()) 
		{
			switch (eachEnemy->GetEnemyType())
			{
			case Enemy_Tag::ENEMY_TYPE_SKELETON:
				enemyHp = eachEnemy->GetEnemyHp();
				std::cout << "\t[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: skeleton | HP: " << (int)enemyHp << '\n';
				break;
			case Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT:
				enemyHp = eachEnemy->GetEnemyHp();
				std::cout << "\t[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: vampire | HP: " << (int)enemyHp << '\n';
				break;
			case Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT:
				enemyHp = eachEnemy->GetEnemyHp();
				std::cout << "\t[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: diablo | HP: " << (int)enemyHp << '\n';
				break;
			default:
				break;
			}
		}
	
		if (optCounter == 0) 
		{
			std::cout << "\t***********************************************\n";
			std::cout <<"\tArea is cleard!\n";
			std::cout << "\t***********************************************\n";
		}
		std::cout << "\n\t[Press " << (int)++optCounter << ']' << " Change weapon | current weapon : " << myPlayer.GetPlayerCurrentWeapon() << '\n';
		std::cout << "\t[Press " << (int)++optCounter << ']' << " Show player states" << '\n';
		std::cout << "\t[Press " << (int) ++optCounter << ']' << " Quit" << '\n';
		std::cout << "\n\tYour choirs : ";
		
		do 
		{
			plrOpt = diablo_II::GetPlayerIntFormat();
			isAccepted = (plrOpt > optCounter || plrOpt <= 0) ? false : true;
		}
		while (!isAccepted);
		return plrOpt;
	}

	void BattleController::Combat() 
	{
		bool inCombatMode{ true };
		uint8_t plrOpt{ 0 };
	
		while (inCombatMode && myPlayer.GetPlayerLifeState() == true) 
		{
			plrOpt = GetPlayerCombatOption();
			if (plrOpt <= myRoom.GetEnemies()->size()) 
			{
				myRoom.GetEnemies()->at((size_t)plrOpt - 1)->EnemyGetDamage(myPlayer.GetPlayerAttackDamageValue(), myRoom.GetItems(), myPlayer.GetPlayerSpelState());
				CheckEnemyStateInRoom((size_t)plrOpt - 1);
				RandomEnemyAttack();
			}
			else if (plrOpt - myRoom.GetEnemies()->size() == 1) 
			{
				//Change weapon
			}
			else if (plrOpt - myRoom.GetEnemies()->size() == 2) 
			{
				PlayerManager myPlayerManager(myPlayer);
				myPlayerManager.DisplayPlayerStates();
			}
			else 
			{
				inCombatMode = false;
			}
		}
	}
}