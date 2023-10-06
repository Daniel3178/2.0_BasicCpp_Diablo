#pragma once
#include "MapBuilder.h"


namespace diablo_II 
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

	struct							Door;
	class							Enemy;
	struct							Item;
	struct							Box;

	class Room 
	{
	public:

									Room(std::vector<Door*>*someDoors, std::vector<Enemy*>* someEnemies,std::vector<Box*>* someBoxes, std::vector<Item*>* someItems, Room_States aRoomId) 
										: doorsInTheRoom(someDoors), enemiesInTheRoom(someEnemies), boxesInTheRoom(someBoxes), itemsInTheRoom(someItems), roomID(aRoomId){};
		 std::vector<Enemy*>*		GetEnemies() const;
		 void						SetEnemiesToNull();
		 std::vector<Door*>*		GetDoors() const;
		 void						SetDoorsToNull();
		 std::vector<Box*>*			GetBoxes() const;
		 void						SetBoxesToNull();
		 std::vector<Item*>*		GetItems() const;
		 void						SetItemsToNull();
		 Room_States				GetRoomID();

	private:
		std::vector<Enemy*>*		enemiesInTheRoom;
		std::vector<Door*>*			doorsInTheRoom;
		std::vector<Box*>*			boxesInTheRoom;
		std::vector<Item*>*			itemsInTheRoom;
		Room_States					roomID;
	};
}