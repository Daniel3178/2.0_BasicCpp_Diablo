#pragma once
#include "BattleController.h"
#include "Room.h"
#include "PlayerManager.h"
#include "Player.h"
#include "ItemFactory.h"
#include <random>
#include <memory>
namespace diablo_III
{
	bool BattleController::ExistEnemies()
	{
		if(myRoom->GetEnemies().size() > 1) /*Även om myRoom är en referens, behöver du arrow för att kunna nå dess funktioner; detta eftersom myRomm
			är en reference till en smart-pekare. Om det hade varit till en raw-pekare så behövde du ingen arrow utan en punkt 
			kunde lösa problemet dvs myRoom.GetEnemies().size()*/
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
		std::uniform_int_distribution<> dis(1, (uint8_t) (myRoom->GetEnemies().size() + 2));
		PlayerManager myPlayerManager(myPlayer);
		std::cout << "\n\t*********************************************************\n";

		for(int i = 1, j = dis(gen); i < myRoom->GetEnemies().size() && myPlayer.GetPlayerLifeState() == true; i += (j % 3) == 0 ? j % 3 + 1 : j % 3, j = dis(gen))
		{ /*Här är ett exempel på en multi-variabel for loop */
			if(myRoom->GetEnemies().at(i) != nullptr)
			{
			myPlayerManager.PlayerGetDamage(myRoom->GetEnemies().at(i)->GetAttackDamage());
			std::cout << "\tA " << myRoom->GetEnemies().at(i)->GetName() << " attacled! | Your current hp : " << myPlayer.GetStat(Stats::eStatIndex::eHealth) << '\n';

			}

		}
		std::cout << "\t*********************************************************\n";
	}

	void BattleController::CheckEnemyStateInRoom(uint8_t anIndex)
	{
		if(myRoom->GetEnemies().at(anIndex)->GetHealth() <= 0)
		{
			myRoom->GetEnemies().erase(myRoom->GetEnemies().begin() + anIndex);
			myRoom->AddSomeRandomItems(1);
			std::cout << "\n\tEnemy has been killed and an item has been dropped!\n";
		}
	}

	uint8_t BattleController::GetPlayerCombatOption()
	{
		uint16_t enemyHp { 0 };
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		//bool isAccepted { true };
		std::cout << "\n\n";

		for(auto& eachEnemy : myRoom->GetEnemies())
		{
			if(eachEnemy != nullptr)
			{

				std::cout << "\t[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: " << eachEnemy->GetName() << " | HP: " << (int)eachEnemy->GetHealth() << '\n';
			}

		}

		if(optCounter == 0)
		{
			std::cout << "\t***********************************************\n";
			std::cout << "\tArea is cleard!\n";
			std::cout << "\t***********************************************\n";
		}
		std::cout << "\n\t[Press " << (int)++optCounter << ']' << " Change weapon | current weapon : " << myPlayer.GetPlayerCurrentWeapon() << '\n';
		std::cout << "\t[Press " << (int)++optCounter << ']' << " Show player states" << '\n';
		std::cout << "\t[Press " << (int) ++optCounter << ']' << " Quit" << '\n';
		std::cout << "\n\tYour choirs : ";

		do
		{
			plrOpt = diablo_III::GetPlayerIntFormat();
			/*isAccepted = (plrOpt > optCounter || plrOpt <= 0) ? false : true;*/
		}
		while(plrOpt > optCounter || plrOpt <= 0);
		return plrOpt;
	}

	void BattleController::Combat()
	{
		bool inCombatMode { true };
		uint8_t plrOpt { 0 };

		while(inCombatMode && myPlayer.GetPlayerLifeState() == true)
		{
			plrOpt = GetPlayerCombatOption();
			if(plrOpt < myRoom->GetEnemies().size())
			{
				myRoom->GetEnemies().at((size_t) plrOpt)->TakeDamage(myPlayer.GetPlayerAttackDamageValue())/*, myRoom.GetItems(), myPlayer.GetPlayerSpelState())*/;
				CheckEnemyStateInRoom((size_t) plrOpt);
				RandomEnemyAttack();
			}
			else if(plrOpt - myRoom->GetEnemies().size() == 0)
			{
				//Change weapon
			}
			else if(plrOpt - myRoom->GetEnemies().size() == 1)
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