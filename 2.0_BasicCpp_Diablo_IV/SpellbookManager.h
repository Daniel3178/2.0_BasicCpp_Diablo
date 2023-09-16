#pragma once


namespace diablo_IV
{
	class Player;
	class Item;

	class SpellbookManager
	{
	private:
		Player& myPlayer;
		
	public:
		SpellbookManager(Player& aPlayer) : myPlayer(aPlayer)
		{};
		void PlayerSpellbookChoice();
	};
}

