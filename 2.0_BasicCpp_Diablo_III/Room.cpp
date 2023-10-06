#include "Room.h"
//#include "EnemyFactory.h"
#include <random>
#include "Box.h"
namespace diablo_III
{
	Room::Room(EnemyFactory& anEnemyFactory, ItemFactory& anItemFactory, eRoomID aRoomId)
		: myEnemyFactory(anEnemyFactory), myItemFactory(anItemFactory), doorsInTheRoom { 0 }, enemiesInTheRoom { 0 }, boxesInTheRoom { 0 }, itemsInTheRoom { 0 }, roomID(aRoomId)
	{

	}
	 std::vector<std::shared_ptr<Enemy>>& Room::GetEnemies() 
	{
		return enemiesInTheRoom;
	}


	const std::vector<std::shared_ptr<Door>>& Room::GetDoors() 
	{
		return doorsInTheRoom;
	}


	const std::vector<std::shared_ptr<Box>>& Room::GetBoxes()
	{
		return boxesInTheRoom;
	}

	
	 std::vector<std::shared_ptr<Item>>& Room::GetItems()
	{
		return itemsInTheRoom;
	}

	
	eRoomID Room::GetRoomID()
	{
		return roomID;
	}

	void Room::AddSomeEnemies(const int aNumOfEnemies, const eEnemyType anEnemyType)
	{
		for(int i = 0; i < aNumOfEnemies; i++)
		{
			enemiesInTheRoom.push_back(myEnemyFactory.CreateEnemy(anEnemyType));
		}
	}

	void Room::AddSomeRandomEnemies(const int aNumOfEnemies)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, static_cast<int>(eEnemyType::eCount)-1/*size_t(myEnemyFactory.GetEnemyTypes().size()-1)*/);

		for(int i = 0; i < aNumOfEnemies; i++)
		{
			enemiesInTheRoom.push_back(myEnemyFactory.CreateEnemy(static_cast<eEnemyType>(dis(gen))));
		}
	}

	void Room::AddSomeItems(const int aNumOfItems, const eItemTypes anItemTyp)
	{
		for(int i = 0; i < aNumOfItems; i++)
		{
			itemsInTheRoom.push_back(myItemFactory.CreateItem(anItemTyp));
		}
	}

	void Room::AddSomeRandomItems(const int aNumOfItems)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, static_cast<int>(eItemTypes::eItemTypeCount) -1 /*myItemFactory.GetItemTypes().size()*/);

		for(int i = 0; i < aNumOfItems; i++)
		{
			itemsInTheRoom.push_back(myItemFactory.CreateItem(static_cast<eItemTypes>(dis(gen))));
		}
	}

	void Room::AddBox(std::shared_ptr<Box> aBox)
	{
		boxesInTheRoom.push_back(aBox);
	}
	void Room::AddDoor(std::shared_ptr<Door> aDoor)
	{
		doorsInTheRoom.push_back(aDoor);
	}

}