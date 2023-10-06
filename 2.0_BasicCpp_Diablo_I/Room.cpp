#include "Room.h"

namespace diablo_I
{
	Room::Room(std::vector<Door*>* someDoors, std::vector<Enemy*>* someEnemies, Room_States aRoomId) :
		doorsInTheRoom(someDoors), enemiesInTheRoom(someEnemies), roomID(aRoomId)
	{}

	std::vector<Enemy*>* Room::GetEnemies() const
	{
		return enemiesInTheRoom;
	}

	void Room::SetEnemiesToNull()
	{
		enemiesInTheRoom = nullptr;
	}

	std::vector<Door*>* Room::GetDoors() const
	{
		return doorsInTheRoom;
	}

	void Room::SetDoorsToNull()
	{
		doorsInTheRoom = nullptr;
	}

	Room_States Room::GetRoomID()
	{
		return roomID;
	}
}