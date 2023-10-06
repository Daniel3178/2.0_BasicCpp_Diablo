#pragma once
#include "MapBuilder.h"
#include "Room.h"
#include "ItemFactory.h"
#include "EnemyFactory.h"
#include<memory>
namespace diablo_III 
{
	class			Player;
	class			Room;
	class			Door;
	enum class		Room_States : uint8_t;
	class			Box;
	int				GetPlayerIntFormat();

	class GameManager 
	{
	public:
					GameManager(ItemFactory& anItemFactory, EnemyFactory& anEnemyFactory) : myItemFactory(anItemFactory), myEnemyFactory(anEnemyFactory){};
		void		Play(Player* aPlayer, std::shared_ptr<Room>& aRoom);
		void		Run();
	private:
		ItemFactory& myItemFactory;
		EnemyFactory& myEnemyFactory;
	};
}