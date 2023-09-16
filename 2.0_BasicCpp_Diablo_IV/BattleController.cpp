#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "Room.h"
#include "Enemy.h"
#include "PlayerManager.h"
#include "BattleController.h"
#include "Player.h"
#include "ItemFactory.h"
#include "Tools.h"


namespace diablo_IV
{
	bool BattleController::ExistEnemies()
	{

		if(myRoom->GetEnemies().size() > 0) 
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

		for(int i = 0, j = dis(gen); i < myRoom->GetEnemies().size() && myPlayer.GetPlayerLifeState() == true; i += (j % 3) == 0 ? j % 3 + 1 : j % 3, j = dis(gen))
		{ /*Här är ett exempel på en multi-variabel for loop */
			if(myRoom->GetEnemies().at(i) != nullptr)
			{
			myPlayerManager.PlayerGetDamage(myRoom->GetEnemies().at(i)->GetAttackDamage());
			std::cout << "\n\t>>>>>>> A " << myRoom->GetEnemies().at(i)->GetName() << " attacled! | Your current hp : " << myPlayer.GetStat(Stats::eStatIndex::eHealth) << " <<<<<<<\n";

			}

		}
	}

	void BattleController::CheckEnemyStateInRoom(uint8_t anIndex)
	{
		if(myRoom->GetEnemies().at(anIndex)->GetHealth() <= 0)
		{
			myRoom->GetEnemies().erase(myRoom->GetEnemies().begin() + anIndex);
			myRoom->AddSomeRandomItems(1);
			std::cout << "\n\t---***--- Enemy has been killed and an item has been dropped! ---***---\n";
		}
	}

	uint8_t BattleController::GetPlayerCombatOption()
	{
		uint16_t enemyHp { 0 };
		uint8_t optCounter { 0 };
		uint8_t plrOpt { 0 };
		std::cout << "\n\n";

		for(auto& eachEnemy : myRoom->GetEnemies())
		{


				std::cout << "\t[Press " << (int)++optCounter << ']' << " Attack! | Enemy type: " << eachEnemy->GetName() << " | HP: " << (int)eachEnemy->GetHealth() << '\n';

		}

		if(optCounter == 0)
		{
			std::cout << "\t---***--- Area is cleard! ---***---\n";
		}
		std::cout << "\n\t[Press " << (int)++optCounter << ']' << " Change weapon | current weapon : " << myPlayer.GetPlayerCurrentWeapon() << '\n';
		std::cout << "\t[Press " << (int)++optCounter << ']' << " Show player states" << '\n';
		std::cout << "\t[Press " << (int) ++optCounter << ']' << " Quit" << '\n';
		std::cout << "\n\tYour choirs : ";

		do
		{
			plrOpt = diablo_IV::GetPlayerIntFormat();
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
			if(myPlayer.GetPlayerSpelState())
			{
				std::cout << "\n\t++++++++++++++++++++++++++++++++++\n";
				for(int i = 0; i < myRoom->GetEnemies().size(); i++)
				{
					if(myRoom->GetEnemies().at(i) != nullptr)
					{
						myRoom->GetEnemies().at(i)->TakeDamage(5);
						std::cout << "\tEnemies are taking damage of a spell\n";
					}
				}
				std::cout << "\t++++++++++++++++++++++++++++++++++\n";
			}
			plrOpt = GetPlayerCombatOption();
			if(plrOpt <= myRoom->GetEnemies().size())
			{
				myRoom->GetEnemies().at(static_cast<uint8_t>(plrOpt - 1))->TakeDamage(myPlayer.GetPlayerAttackDamageValue());
				CheckEnemyStateInRoom( static_cast<uint8_t>( plrOpt -1));
				RandomEnemyAttack();
			}
			else if(plrOpt - myRoom->GetEnemies().size() == 1)
			{
				//Change weapon
			}
			else if(plrOpt - myRoom->GetEnemies().size() == 2)
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