#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Door.h"
#include "EnemyType_Skeleton.h"
#include "EnemyType_VampireKnight.h"
#include "EnemyType_DragonGuardiant.h"

namespace diablo_II 
{
	class						Room;
	struct						Door;
	struct						Box;

	class MapBuilder 
	{
	public:
								MapBuilder() : allRoomsInTheMap(nullptr), allDoorsInTheMap(nullptr){};
								~MapBuilder();
		void					CreateMap();
		void					DeallocateMemory_Map();
		Room*					GetRoomByID(const Room_States aRoomID);

	private:
		std::vector<Room*>*		allRoomsInTheMap;
		std::vector<Door*>*		allDoorsInTheMap;

	};
}
