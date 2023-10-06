#include "RoomManager.h"
#include "Room.h"

namespace diablo_I
{
	RoomManager::RoomManager() :
		allRoomsInTheMap(nullptr), allDoorsInTheMap(nullptr)
	{}

	RoomManager::~RoomManager()
	{

		if (allRoomsInTheMap != nullptr)
		{
			DeallocateMemory_Map();
		}
	}
	//add features, add door, delete door
	void RoomManager::CreateMap()
	{

		Door* doorPtr1 = new Door(Room_States::ROOM_A, Room_States::ROOM_B, Room_States::DOOR_STATE_LOCKED);
		Door* doorPtr2 = new Door(Room_States::ROOM_A, Room_States::ROOM_D, Room_States::DOOR_STATE_UNLOCKED);
		Door* doorPtr3 = new Door(Room_States::ROOM_A, Room_States::ROOM_E, Room_States::DOOR_STATE_UNLOCKED);
		Door* doorPtr4 = new Door(Room_States::ROOM_B, Room_States::ROOM_C, Room_States::DOOR_STATE_UNLOCKED);
		Door* doorPtr5 = new Door(Room_States::ROOM_C, Room_States::ROOM_D, Room_States::DOOR_STATE_UNLOCKED);

		allDoorsInTheMap = new std::vector<Door*> { doorPtr1,doorPtr2,doorPtr3,doorPtr4,doorPtr5 };

		std::vector<Door*>* doorsInRoomA = new std::vector<Door*> { doorPtr1, doorPtr2, doorPtr3 };
		std::vector<Door*>* doorsInRoomB = new std::vector<Door*> { doorPtr1, doorPtr4 };
		std::vector<Door*>* doorsInRoomC = new std::vector<Door*> { doorPtr4, doorPtr5 };
		std::vector<Door*>* doorsInRoomD = new std::vector<Door*> { doorPtr2, doorPtr5 };
		std::vector<Door*>* doorsInRoomE = new std::vector<Door*> { doorPtr3 };

		std::vector<Enemy*>* enemiesInRoomA = new std::vector<Enemy*> { new Skeleton(), new Skeleton(), new Skeleton() };
		std::vector<Enemy*>* enemiesInRoomB = new std::vector<Enemy*> { new Skeleton(),new VampireKnight(),new VampireKnight() };
		std::vector<Enemy*>* enemiesInRoomC = new std::vector<Enemy*> { new Skeleton() };
		std::vector<Enemy*>* enemiesInRoomD = new std::vector<Enemy*> { new VampireKnight() };
		std::vector<Enemy*>* enemiesInRoomE = new std::vector<Enemy*> { new DragonGuardiant() };

		Room* roomA = new Room(doorsInRoomA, enemiesInRoomA, Room_States::ROOM_A);
		Room* roomB = new Room(doorsInRoomB, enemiesInRoomB, Room_States::ROOM_B);
		Room* roomC = new Room(doorsInRoomC, enemiesInRoomC, Room_States::ROOM_C);
		Room* roomD = new Room(doorsInRoomD, enemiesInRoomD, Room_States::ROOM_D);
		Room* roomE = new Room(doorsInRoomE, enemiesInRoomE, Room_States::ROOM_E);

		allRoomsInTheMap = new std::vector<Room*> { roomA, roomB, roomC, roomD, roomE };
	}

	void RoomManager::DeallocateMemory_Map()
	{

		for (auto& eachRoom : *allRoomsInTheMap)
		{
			for (auto& eachDoor : *eachRoom->GetDoors())
			{
				eachDoor = nullptr;
			}
			eachRoom->GetDoors()->clear();
			delete eachRoom->GetDoors();
			eachRoom->SetDoorsToNull();

			for (auto& eachEnemy : *eachRoom->GetEnemies())
			{
				delete eachEnemy;
				eachEnemy = nullptr;
			}

			eachRoom->GetEnemies()->clear();
			delete eachRoom->GetEnemies();
			eachRoom->SetEnemiesToNull();

			delete eachRoom;
			eachRoom = nullptr;
		}

		for (auto& eachDoor : *allDoorsInTheMap)
		{
			delete eachDoor;
			eachDoor = nullptr;
		}

		allDoorsInTheMap->clear();
		allRoomsInTheMap->clear();
		delete allDoorsInTheMap;
		delete allRoomsInTheMap;
		allRoomsInTheMap = nullptr;
		allDoorsInTheMap = nullptr;
	}

	Room* RoomManager::GetRoomByID(const Room_States aRoomId)
	{
		for (auto& eachRoom : *allRoomsInTheMap)
		{
			if (eachRoom->GetRoomID() == aRoomId)
			{
				return eachRoom;
			}
		}
		return nullptr;
	}
}
