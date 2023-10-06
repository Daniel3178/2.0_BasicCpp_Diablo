#pragma once
#include <vector>

namespace diablo_II 
{
	class			Room;
	class			Player;
	class			Enemy;

	class BattleController
	{
	public:
					BattleController(Player& aPlayer, Room& aRoom) : myPlayer(aPlayer), myRoom(aRoom) {};
		bool		ExistEnemies();
		void		RandomEnemyAttack();
		void		CheckEnemyStateInRoom(uint8_t anIndex);
		uint8_t		GetPlayerCombatOption();
		void		Combat();

	private:
		Room&		myRoom;
		Player&		myPlayer;
	};
}