#include "Room.h"

namespace diablo_II 
{
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

	 std::vector<Box*>* Room::GetBoxes() const 
	 {
		 return boxesInTheRoom;
	 }

	 void Room::SetBoxesToNull() 
	 {
		 boxesInTheRoom = nullptr;
	 }

	 std::vector<Item*>* Room::GetItems() const 
	 {
		 return itemsInTheRoom;
	 }

	 void Room::SetItemsToNull() 
	 {
		 itemsInTheRoom = nullptr;
	 }

	 Room_States Room::GetRoomID() 
	 {
		 return roomID;
	 }
}