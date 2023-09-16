#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Door.h"
#include <memory>
#include "MapBuilder.h"
#include "Room.h"
#include "Box.h"
#include "Item.h"
#include "ItemFactory.h"
#include "EnemyFactory.h"

namespace diablo_IV
{

	void MapBuilder::CreateMap(ItemFactory& anItemFactory, EnemyFactory& anEnemyFactory)
	{
		std::shared_ptr<Door> doorPtr1 = std::make_shared<Door>(eRoomID::eRoom_A, eRoomID::eRoom_B, Room_States::DOOR_STATE_LOCKED, 10);
		std::shared_ptr<Door> doorPtr2 = std::make_shared<Door>(eRoomID::eRoom_B, eRoomID::eRoom_C, Room_States::DOOR_STATE_LOCKED, 100);
		std::shared_ptr<Door> doorPtr3 = std::make_shared<Door>(eRoomID::eRoom_C, eRoomID::eRoom_D, Room_States::DOOR_STATE_LOCKED, 100);
		std::shared_ptr<Door> doorPtr4 = std::make_shared<Door>(eRoomID::eRoom_B, eRoomID::eRoom_E, Room_States::DOOR_STATE_UNLOCKED, 0);
		std::shared_ptr<Door> doorPtr5 = std::make_shared<Door>(eRoomID::eRoom_D, eRoomID::eRoom_E, Room_States::DOOR_STATE_UNLOCKED, 0);
		std::shared_ptr<Door> doorPtr6 = std::make_shared<Door>(eRoomID::eRoom_E, eRoomID::eRoom_F, Room_States::DOOR_STATE_LOCKED, 60);
		std::shared_ptr<Door> doorPtr7 = std::make_shared<Door>(eRoomID::eRoom_E, eRoomID::eRoom_G, Room_States::DOOR_STATE_UNLOCKED, 0);
		
		
		std::shared_ptr<Room> roomA = std::make_shared<Room>(anEnemyFactory, anItemFactory, eRoomID::eRoom_A);
		std::shared_ptr<Box> box1InA = std::make_shared<Box>(anItemFactory);
		std::shared_ptr<Box> box2InA = std::make_shared<Box>(anItemFactory);
		roomA->AddBox(box1InA);
		roomA->AddBox(box2InA);
		roomA->AddSomeRandomEnemies(3);
		roomA->AddDoor(doorPtr1);

		std::shared_ptr<Room> roomB = std::make_shared<Room>(anEnemyFactory, anItemFactory, eRoomID::eRoom_B);
		std::shared_ptr<Box> box1InB = std::make_shared<Box>(anItemFactory);
		std::shared_ptr<Box> box2InB = std::make_shared<Box>(anItemFactory);
		roomB->AddBox(box1InB);
		roomB->AddBox(box2InB);
		roomB->AddSomeRandomEnemies(4);
		roomB->AddDoor(doorPtr1);
		roomB->AddDoor(doorPtr2);
		roomB->AddDoor(doorPtr3);
		roomB->AddDoor(doorPtr4);

		std::shared_ptr<Room> roomC = std::make_shared<Room>(anEnemyFactory, anItemFactory, eRoomID::eRoom_C);
		std::shared_ptr<Box> box1InC = std::make_shared<Box>(anItemFactory);
		std::shared_ptr<Box> box2InC = std::make_shared<Box>(anItemFactory);
		roomC->AddBox(box1InC);
		roomC->AddBox(box2InC);
		roomC->AddSomeRandomEnemies(1);
		roomC->AddDoor(doorPtr2);
		roomC->AddDoor(doorPtr3);

		std::shared_ptr<Room> roomD = std::make_shared<Room>(anEnemyFactory, anItemFactory, eRoomID::eRoom_D);
		std::shared_ptr<Box> box1InD = std::make_shared<Box>(anItemFactory);
		std::shared_ptr<Box> box2InD = std::make_shared<Box>(anItemFactory);
		roomD->AddBox(box1InD);
		roomD->AddBox(box2InD);
		roomD->AddSomeRandomEnemies(5);
		roomD->AddDoor(doorPtr3);
		roomD->AddDoor(doorPtr5);

		std::shared_ptr<Room> roomE = std::make_shared<Room>(anEnemyFactory, anItemFactory, eRoomID::eRoom_E);
		std::shared_ptr<Box> box1InE = std::make_shared<Box>(anItemFactory);
		std::shared_ptr<Box> box2InE = std::make_shared<Box>(anItemFactory);
		roomE->AddBox(box1InE);
		roomE->AddBox(box2InE);
		roomE->AddSomeRandomEnemies(2);
		roomE->AddDoor(doorPtr4);
		roomE->AddDoor(doorPtr5);
		roomE->AddDoor(doorPtr6);
		roomE->AddDoor(doorPtr7);

		std::shared_ptr<Room> roomF = std::make_shared<Room>(anEnemyFactory, anItemFactory, eRoomID::eRoom_F);
		std::shared_ptr<Box> box1InF = std::make_shared<Box>(anItemFactory);
		std::shared_ptr<Box> box2InF = std::make_shared<Box>(anItemFactory);
		roomF->AddBox(box1InF);
		roomF->AddBox(box2InF);
		roomF->AddSomeRandomEnemies(4);
		roomF->AddDoor(doorPtr6);

		std::shared_ptr<Room> roomG = std::make_shared<Room>(anEnemyFactory, anItemFactory, eRoomID::eRoom_G);
		std::shared_ptr<Box> box1InG = std::make_shared<Box>(anItemFactory);
		std::shared_ptr<Box> box2InG = std::make_shared<Box>(anItemFactory);
		roomG->AddBox(box1InG);
		roomG->AddBox(box2InG);
		roomG->AddSomeRandomEnemies(4);
		roomG->AddDoor(doorPtr7);

		allRoomsInTheMap.insert(allRoomsInTheMap.begin(),roomA);
		allRoomsInTheMap.insert(allRoomsInTheMap.begin(),roomB);
		allRoomsInTheMap.insert(allRoomsInTheMap.begin(),roomC);
		allRoomsInTheMap.insert(allRoomsInTheMap.begin(),roomD);
		allRoomsInTheMap.insert(allRoomsInTheMap.begin(),roomE);
		allRoomsInTheMap.insert(allRoomsInTheMap.begin(),roomF);
		allRoomsInTheMap.insert(allRoomsInTheMap.begin(),roomG);
	
	}

	

	std::shared_ptr<Room>& MapBuilder::GetRoomByID(const eRoomID aRoomId)
	{
		for(auto& eachRoom : allRoomsInTheMap)
		{
			if(eachRoom->GetRoomID() == aRoomId)
			{
				return eachRoom;
			}
		}
		throw std::runtime_error("Room not found");
	}
}
