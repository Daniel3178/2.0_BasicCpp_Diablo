#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Door.h"
#include "EnemyType_Skeleton.h"
#include "EnemyType_VampireKnight.h"
#include "EnemyType_DragonGuardiant.h"

namespace diablo_I
{
	class Room;
	struct Door;
	class RoomManager
	{
	public:
		RoomManager();
		~RoomManager();
		void CreateMap();
		void DeallocateMemory_Map();
		Room* GetRoomByID(const Room_States aRoomID);

	private:
		std::vector<Room*>* allRoomsInTheMap;
		std::vector<Door*>* allDoorsInTheMap;

	};
}
