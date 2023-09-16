#pragma once


namespace diablo_IV
{
	enum class Room_States : uint8_t
	{
		NOTHING = 0,
		DOOR_STATE_LOCKED,
		DOOR_STATE_UNLOCKED,
		ROOM_A,
		ROOM_B,
		ROOM_C,
		ROOM_D,
		ROOM_E,
		ROOM_F,
		ROOM_G,
		DOOR_1,
		DOOR_2,
		DOOR_3,
		DOOR_4,
		DOOR_5,
		DOOR_6,
		DOOR_7,
	};

	enum class eRoomID
	{
		eRoom_A,
		eRoom_B,
		eRoom_C,
		eRoom_D,
		eRoom_E,
		eRoom_F,
		eRoom_G,
		eRoomCount
	};
	class EnemyFactory;
	class ItemFactory;
	enum class eEnemyType;
	enum class eItemTypes;
	class Door;
	class Enemy;
	class Item;
	class Box;

	class Room
	{
	public:

		Room(EnemyFactory& anEnemyFactory, ItemFactory& anItemFactory, eRoomID aRoomId)
			;
		std::vector<std::shared_ptr<Enemy>>& GetEnemies();
		const std::vector<std::shared_ptr<Door>>& GetDoors();
		const std::vector<std::shared_ptr<Box>>& GetBoxes();
		std::vector<std::shared_ptr<Item>>& GetItems();
		eRoomID GetRoomID();
		void AddSomeEnemies(const int aNumOfEnemies, const eEnemyType anEnemyType);
		void AddSomeRandomEnemies(const int aNumOfEnemies);

		void AddSomeItems(const int aNumOfItems, const eItemTypes anItemType);
		void AddSomeRandomItems(const int aNumOfEnemies);

		void AddBox(std::shared_ptr<Box> aBox);
		void AddDoor(std::shared_ptr<Door> aDoor);

	private:
		std::vector< std::shared_ptr<Enemy>>enemiesInTheRoom;
		std::vector<std::shared_ptr<Door>>doorsInTheRoom;
		std::vector<std::shared_ptr<Box>>boxesInTheRoom;
		std::vector<std::shared_ptr<Item>>itemsInTheRoom;
		eRoomID	roomID;
		EnemyFactory& myEnemyFactory;
		ItemFactory& myItemFactory;
	};
}