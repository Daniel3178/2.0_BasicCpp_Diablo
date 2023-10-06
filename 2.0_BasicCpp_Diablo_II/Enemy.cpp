#pragma once
#include "Enemy.h"
#include "Player.h"
#include <random>
#include "Item.h"

namespace diablo_II 
{
	int& Enemy::GetEnemyHp() 
	{
		return hp;
	}

	Enemy_Tag Enemy::GetEnemyType() 
	{
		return enemyType;
	}

	const uint8_t& Enemy::GetEnemyAttackDamageValue()const 
	{
		return attackDamage;
	}

	void Enemy::EnemyGetDamage(const uint16_t& someDamage, std::vector<Item*>* aRoomContainer, const bool& isPlayerSpelActive) 
	{
		hp -= someDamage;
		std::cout << "\n\t*********************************************************\n";
		switch (this->GetEnemyType()) {
		case Enemy_Tag::ENEMY_TYPE_SKELETON:
		{
			if (this->hp <= 0) 
			{
				std::cout << "\tYou killed a skeleton\n";
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(1, 4);
				int random = dis(gen);
				switch (random)
				{
				case 1:
				{
					Item* item = new Item(Item_Tag::PORTION_HP);
					aRoomContainer->push_back(item);
					std::cout << "\tEnemy dropped an item! \n";
					break;
				}
				case 2:
				{
					Item* item = new Item(Item_Tag::PORTION_STRENGTH);
					aRoomContainer->push_back(item);
					std::cout << "\tEnemy dropped an item! \n";
					break;
				}
				default:
					break;
				}
			}
			else if (isPlayerSpelActive) 
			{
				hp -= 100;
				std::cout << "\tYou damaged a skeleton with your enhanced weapon! \n";
			}
			else 
			{
				std::cout << "\tYou damaged a skeleton \n";
			}
			break;
		}
		case Enemy_Tag::ENEMY_TYPE_VAMPIRE_KNIGHT:
		{
			if (this->hp <= 0) 
			{
				std::cout << "\n\tYou killed a vampire \n\n";
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(1, 4);
				int random = dis(gen);
				switch (random)
				{
				case 1:
				{
					Item* item = new Item(Item_Tag::PORTION_HP);
					aRoomContainer->push_back(item);
					std::cout << "\tEnemy dropped an item! \n";
					break;
				}
				case 2:
				{
					Item* item = new Item(Item_Tag::PORTION_STRENGTH);
					aRoomContainer->push_back(item);
					std::cout << "\tEnemy dropped an item! \n";
					break;
				}
				default:
					break;
				}
			}
			else if (isPlayerSpelActive) 
			{
				hp -= 100;
				std::cout << "\tYou damaged a vampire with your enhanced weapon! \n";
			}
			else 
			{
				std::cout << "\tYou damaged a vampire \n";
			}
			break;
		}
		case Enemy_Tag::ENEMY_TYPE_DRAGON_GUARDIANT:
		{
			if (this->hp <= 0) 
			{
				std::cout << "\tYou killed a diablo \n";
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(1, 4);
				int random = dis(gen);
				switch (random)
				{
				case 1:
				{
					Item* item = new Item(Item_Tag::PORTION_HP);
					aRoomContainer->push_back(item);
					std::cout << "\tEnemy dropped an item! \n";
					break;
				}
				case 2:
				{
					Item* item = new Item(Item_Tag::PORTION_STRENGTH);
					aRoomContainer->push_back(item);
					std::cout << "\tEnemy dropped an item! \n";
					break;
				}
				default:
					break;
				}
			}
			else if (isPlayerSpelActive) 
			{
				hp -= 100;
				std::cout << "\tYou damaged a dragon with your enhanced weapon! \n";
			}
			else 
			{
				std::cout << "\tYou damaged a diablo \n";
			}
			break;
		}
		}
		std::cout << "\t*********************************************************\n";
	}
}