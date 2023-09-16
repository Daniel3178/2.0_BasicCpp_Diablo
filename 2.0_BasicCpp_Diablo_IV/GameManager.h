#pragma once
#include <memory>
#include <vector>

namespace diablo_IV 
{
	class			Player;
	class			Room;
	class			Door;
	enum class		Room_States : uint8_t;
	class			Box;
	class EnemyFactory;
	class ItemFactory;
	enum class eRoomID;
	class GameManager 
	{
	public:
					GameManager(ItemFactory& anItemFactory, EnemyFactory& anEnemyFactory) : myItemFactory(anItemFactory), myEnemyFactory(anEnemyFactory){};
		void		Run();
		eRoomID     Play(Player* aPlayer, std::shared_ptr<Room>& aRoom);
	private:
		void DisplayIntroToRoom(const eRoomID aRoomID);
		ItemFactory& myItemFactory;
		EnemyFactory& myEnemyFactory;

	};
}