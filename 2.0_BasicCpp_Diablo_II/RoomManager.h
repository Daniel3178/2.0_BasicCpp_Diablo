#pragma once
#include <iostream>
#include <vector>
namespace diablo_II 
{
	class				Player;
	class				Room;

	class RoomManager 
	{
	private: 
		Player&			myPlayer;
		Room&			myRoom;

	public: 
						RoomManager(Player& aPlayer, Room& aRoom) : myPlayer(aPlayer), myRoom(aRoom) {};
		uint8_t			GetPlayerRoomChoiceOpt();
		void			ChoseRoom();
		uint8_t			GetPlayerRoomOpt();
		void			PlayerRoomObjectChoices();
		bool			IsLoot(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt);
		uint8_t			GetIndex(std::vector<std::vector<uint8_t>>& aPlrIndexTranslator, uint8_t aPlayerOpt);
	};
}