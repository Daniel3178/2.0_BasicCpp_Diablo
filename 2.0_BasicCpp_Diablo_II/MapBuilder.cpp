#include "MapBuilder.h"
#include "Room.h"
#include "Box.h"
#include "Item.h"

namespace diablo_II 
{
	MapBuilder::~MapBuilder() 
	{
		if (allRoomsInTheMap != nullptr) 
		{
			DeallocateMemory_Map();
		}
	}

	void MapBuilder::CreateMap() 
	{
		Door* doorPtr1 = new Door(Room_States::ROOM_A, Room_States::ROOM_B, Room_States::DOOR_STATE_LOCKED, 10);
		Door* doorPtr2 = new Door(Room_States::ROOM_B, Room_States::ROOM_C, Room_States::DOOR_STATE_LOCKED, 100);
		Door* doorPtr3 = new Door(Room_States::ROOM_C, Room_States::ROOM_D, Room_States::DOOR_STATE_LOCKED, 100);
		Door* doorPtr4 = new Door(Room_States::ROOM_B, Room_States::ROOM_E, Room_States::DOOR_STATE_UNLOCKED,0);
		Door* doorPtr5 = new Door(Room_States::ROOM_D, Room_States::ROOM_E, Room_States::DOOR_STATE_UNLOCKED,0);
		Door* doorPtr6 = new Door(Room_States::ROOM_E, Room_States::ROOM_F, Room_States::DOOR_STATE_LOCKED,60);
		Door* doorPtr7 = new Door(Room_States::ROOM_E, Room_States::ROOM_G, Room_States::DOOR_STATE_UNLOCKED,0);

		allDoorsInTheMap = new std::vector<Door*>{ doorPtr1,doorPtr2,doorPtr3,doorPtr4,doorPtr5,doorPtr6, doorPtr7 };

		std::vector<Door*>* doorsInRoomA = new std::vector<Door*>{ doorPtr1 };
		std::vector<Door*>* doorsInRoomB = new std::vector<Door*>{ doorPtr2, doorPtr4, doorPtr1 };
		std::vector<Door*>* doorsInRoomC = new std::vector<Door*>{ doorPtr3, doorPtr2 };
		std::vector<Door*>* doorsInRoomD = new std::vector<Door*>{ doorPtr3, doorPtr5 };
		std::vector<Door*>* doorsInRoomE = new std::vector<Door*>{ doorPtr5,doorPtr6,doorPtr7, doorPtr4 };
		std::vector<Door*>* doorsInRoomF = new std::vector<Door*>{ doorPtr6 };
		std::vector<Door*>* doorsInRoomG = new std::vector<Door*>{ doorPtr7 };

		std::vector<Enemy*>* enemiesInRoomA = new std::vector<Enemy*>
		{
			new Skeleton(),
			new Skeleton(),
		};
		std::vector<Enemy*>* enemiesInRoomB = new std::vector<Enemy*>
		{
			new Skeleton(),
			new Skeleton(),
			new VampireKnight()
		};
		std::vector<Enemy*>* enemiesInRoomC = new std::vector<Enemy*>
		{
			new Skeleton(),
			new Skeleton(),
			new Skeleton(),
			new DragonGuardiant(),
			new VampireKnight(),
			new VampireKnight()
		};
		std::vector<Enemy*>* enemiesInRoomD = new std::vector<Enemy*>
		{
			new VampireKnight(),
			new VampireKnight(),
			new Skeleton(),
			new Skeleton(),
			new VampireKnight()
		};
		std::vector<Enemy*>* enemiesInRoomE = new std::vector<Enemy*>
		{
			new Skeleton(),
			new Skeleton(),
			new Skeleton(),
			new Skeleton(),
			new Skeleton(),
		};		
		std::vector<Enemy*>* enemiesInRoomF = new std::vector<Enemy*>
		{
			new Skeleton(),
			new Skeleton(),
			new VampireKnight()
		};		
		std::vector<Enemy*>* enemiesInRoomG = new std::vector<Enemy*>
		{
			new VampireKnight(),
			new VampireKnight()
		};
		std::vector<Box*>* boxesInRoomA = new std::vector<Box*>{ new Box(),new Box() };
		std::vector<Box*>* boxesInRoomB = new std::vector<Box*>{ new Box()};
		std::vector<Box*>* boxesInRoomE = new std::vector<Box*>{ new Box(),new Box() };
		std::vector<Box*>* boxesInRoomF = new std::vector<Box*>{ new Box(),new Box(),new Box(),new Box() };
		std::vector<Box*>* boxesInRoomG = new std::vector<Box*>{ new Box() };

		std::vector<Item*>* roomAContainer = new std::vector<Item*>{};
		std::vector<Item*>* roomBContainer = new std::vector<Item*>{};
		std::vector<Item*>* roomCContainer = new std::vector<Item*>{};
		std::vector<Item*>* roomDContainer = new std::vector<Item*>{};
		roomDContainer->push_back(new Item(Item_Tag::SPEL_HELLBOY));
		std::vector<Item*>* roomEContainer = new std::vector<Item*>{};
		std::vector<Item*>* roomFContainer = new std::vector<Item*>{};
		std::vector<Item*>* roomGContainer = new std::vector<Item*>{};

		Room* roomA = new Room(doorsInRoomA, enemiesInRoomA, boxesInRoomA, roomAContainer, Room_States::ROOM_A);
		Room* roomB = new Room(doorsInRoomB, enemiesInRoomB, boxesInRoomB, roomBContainer, Room_States::ROOM_B);
		Room* roomC = new Room(doorsInRoomC, enemiesInRoomC, nullptr, roomCContainer, Room_States::ROOM_C);
		Room* roomD = new Room(doorsInRoomD, enemiesInRoomD, nullptr, roomDContainer, Room_States::ROOM_D);
		Room* roomE = new Room(doorsInRoomE, enemiesInRoomE, boxesInRoomE, roomEContainer, Room_States::ROOM_E);
		Room* roomF = new Room(doorsInRoomF, enemiesInRoomF, boxesInRoomF, roomFContainer, Room_States::ROOM_F);
		Room* roomG = new Room(doorsInRoomG, enemiesInRoomG, boxesInRoomG, roomGContainer, Room_States::ROOM_G);

		allRoomsInTheMap = new std::vector<Room*>{ roomA, roomB, roomC, roomD, roomE,roomF,roomG };
	}

	void MapBuilder::DeallocateMemory_Map() 
	{
		if (allRoomsInTheMap != nullptr) 
		{
			for (auto& eachRoom : *allRoomsInTheMap) 
			{
				if (eachRoom->GetDoors() != nullptr) 
				{
					for (auto& eachDoor : *eachRoom->GetDoors()) 
					{
						eachDoor = nullptr;
					}
					eachRoom->GetDoors()->clear();
					delete eachRoom->GetDoors();
					eachRoom->SetDoorsToNull();
				}

				if (eachRoom->GetEnemies() != nullptr) 
				{
					for (auto& eachEnemy : *eachRoom->GetEnemies()) 
					{
						delete eachEnemy;
						eachEnemy = nullptr;
					}
					eachRoom->GetEnemies()->clear();
					delete eachRoom->GetEnemies();
					eachRoom->SetEnemiesToNull();
				}

				if (eachRoom->GetBoxes() != nullptr) 
				{
					for (auto& eachBox : *eachRoom->GetBoxes()) 
					{
						if (eachBox->GetItemsInTheBox() != nullptr) 
						{
							for (auto& eachItem : *eachBox->GetItemsInTheBox()) 
							{
								delete eachItem;
								eachItem = nullptr;
							}
							eachBox->GetItemsInTheBox()->clear();
							delete eachBox->GetItemsInTheBox();
							eachBox->SetItemsInTheBoxToNull();
						}
						delete eachBox;
						eachBox = nullptr;
					}
					eachRoom->GetBoxes()->clear();
					delete eachRoom->GetBoxes();
					eachRoom->SetBoxesToNull();
				}

				if (eachRoom->GetItems() != nullptr) 
				{
					for (auto& eachItemInTheRoom : *eachRoom->GetItems()) 
					{
						delete eachItemInTheRoom;
						eachItemInTheRoom = nullptr;
					}
					eachRoom->GetItems()->clear();
					delete eachRoom->GetItems();
					eachRoom->SetItemsToNull();
				}
				delete eachRoom;
				eachRoom = nullptr;
			}

			if (allDoorsInTheMap != nullptr) 
			{
				for (auto& eachDoor : *allDoorsInTheMap) 
				{
					delete eachDoor;
					eachDoor = nullptr;
				}
				allDoorsInTheMap->clear();
				delete allDoorsInTheMap;
				allDoorsInTheMap = nullptr;
			}
			allRoomsInTheMap->clear();
			delete allRoomsInTheMap;
			allRoomsInTheMap = nullptr;
		}
	}

	Room* MapBuilder::GetRoomByID(const Room_States aRoomId) 
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
