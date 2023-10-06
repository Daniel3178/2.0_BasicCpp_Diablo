#pragma once
#include <vector>
#include <memory>
namespace diablo_III 
{
	class			Room; /*H�r forward deklarerar du klassen Room f�r att kompilatorn ska kunna k�nna till den data typen i header filen*/
	class			Player;
	class			Enemy;
	class ItemFactory;

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