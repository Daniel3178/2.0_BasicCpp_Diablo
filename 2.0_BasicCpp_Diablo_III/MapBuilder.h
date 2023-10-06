#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Door.h"
#include <memory>

namespace diablo_III 
{
	class						Room;
	class						Door;
	class						Box;
	enum class eRoomID;
	class EnemyFactory;
	class ItemFactory;
	class MapBuilder 
	{
	public:
		MapBuilder() : allRoomsInTheMap { 0 }, allDoorsInTheMap { 0 }
		{};
		void					CreateMap(ItemFactory& anItemFactory, EnemyFactory& anEnemyFactory);
		std::shared_ptr<Room>&		GetRoomByID(const eRoomID aRoomID);

	private:
		std::vector<std::shared_ptr<Room>>		allRoomsInTheMap;
		std::vector<std::shared_ptr<Door>>		allDoorsInTheMap;

	};
}
