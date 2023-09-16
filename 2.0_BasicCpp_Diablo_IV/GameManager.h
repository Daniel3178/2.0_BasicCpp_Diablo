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

	class GameManager 
	{
	public:
					GameManager(ItemFactory& anItemFactory, EnemyFactory& anEnemyFactory) : myItemFactory(anItemFactory), myEnemyFactory(anEnemyFactory){};
		void		Play(Player* aPlayer, std::shared_ptr<Room>& aRoom);
		void		Run();
	private:
		ItemFactory& myItemFactory;
		EnemyFactory& myEnemyFactory;
	};
}