#pragma once

namespace diablo_IV 
{
	class			Room;
	class			Player;
	
	
	class Item;
	class ItemFactory;
	
	class Box;

	class BoxManager 
	{
	private:
		std::shared_ptr<Room>&		myRoom;
		Player&		myPlayer;
		ItemFactory& myItemFactory;
		void TryToBreak(uint8_t aPlrOpt);
		void DisplayLockOpt()const;
		void InteractWithBox(const uint8_t aPlrOpt);
		const uint8_t GetNumOfInBoxOpt(const std::vector<std::shared_ptr<Item>>& someItems)const;
		const uint8_t GetNumOfBoxOpt()const ;
	public:
					BoxManager(Player& aPlayer, std::shared_ptr<Room>& aRoom, ItemFactory& anItemFactory) : myPlayer(aPlayer), myRoom(aRoom), myItemFactory(anItemFactory) {};
		uint8_t		GetPlayerBoxChoiceOpt();
		void		ChoseBox();
		void		PlayerInBoxChoices(std::vector<std::shared_ptr<Item>>& someItems);
		void		BreakLock(Box& aBox);

	};
}