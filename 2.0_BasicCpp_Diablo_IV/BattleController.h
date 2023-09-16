#pragma once

namespace diablo_IV 
{
	class			Room; 
	class			Player;
	class			Enemy;
	class ItemFactory;
	class shared_ptr;
	class vector;

	class BattleController
	{
	public:
					BattleController(Player& aPlayer, std::shared_ptr<Room>& aRoom, ItemFactory& anItemFactory) : myPlayer(aPlayer), myRoom(aRoom), myItemFactory(anItemFactory) {};
		bool		ExistEnemies();
		void		RandomEnemyAttack();
		void		CheckEnemyStateInRoom(uint8_t anIndex);
		uint8_t		GetPlayerCombatOption();
		void		Combat();

	private:
		std::shared_ptr<Room>&		myRoom;
		Player&		myPlayer;
		ItemFactory& myItemFactory;
	};
}