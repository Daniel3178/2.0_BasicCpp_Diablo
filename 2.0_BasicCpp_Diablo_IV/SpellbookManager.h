#pragma once


namespace diablo_IV
{
	class Player;
	class Item;

	class SpellbookManager
	{
	private:
		Player& myPlayer;
		const uint8_t CountSpellbookOpt() const;
	public:
		SpellbookManager(Player& aPlayer) : myPlayer(aPlayer)
		{};
		void PlayerSpellbookChoice();
	};
}

