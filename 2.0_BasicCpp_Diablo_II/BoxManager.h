#pragma once
#include <iostream>
#include <vector>
namespace diablo_II 
{
	class			Room;
	class			Player;
	struct			Item;
	struct			Box;

	class BoxManager 
	{
	private:
		Room&		myRoom;
		Player&		myPlayer;

	public:
					BoxManager(Player& aPlayer, Room& aRoom) : myPlayer(aPlayer), myRoom(aRoom) {};
		uint8_t		GetPlayerBoxChoiceOpt();
		void		ChoseBox();
		void		PlayerInBoxChoices(std::vector<Item*>* someItems);
		void		BreakLock(Box& aBox);

	};
}