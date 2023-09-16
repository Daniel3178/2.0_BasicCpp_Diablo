#pragma once

namespace diablo_IV 
{
	class				Player;
	class				Room;
	class ItemFactory;
	class RoomManager 
	{
	private: 
		Player&			myPlayer;
		std::shared_ptr<Room>&			myRoom;
		ItemFactory& myItemFactory;
	public: 
						RoomManager(Player& aPlayer, std::shared_ptr<Room>& aRoom, ItemFactory& anItemFactory) :myItemFactory(anItemFactory), myPlayer(aPlayer), myRoom(aRoom) {};
		uint8_t			GetPlayerRoomChoiceOpt();
		void			ChoseRoom();
		uint8_t			GetPlayerRoomOpt();
		void			PlayerRoomObjectChoices();
		bool			IsLoot(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt);
		uint8_t			GetIndex(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt);
	};
}