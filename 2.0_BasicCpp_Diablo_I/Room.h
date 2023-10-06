#pragma once
#include "RoomManager.h"

namespace diablo_I
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
		DOOR_1,
		DOOR_2,
		DOOR_3,
		DOOR_4,
		DOOR_5
	};

	struct Door;
	class Enemy;
	class Room
	{
	public:

		Room(std::vector<Door*>* someDoors, std::vector<Enemy*>* someEnemies, Room_States aRoomId);
		std::vector<Enemy*>* GetEnemies() const;
		void SetEnemiesToNull();
		std::vector<Door*>* GetDoors() const;
		void SetDoorsToNull();
		Room_States GetRoomID();

	private:
		std::vector<Enemy*>* enemiesInTheRoom;
		std::vector<Door*>* doorsInTheRoom;
		Room_States roomID;
	};
}