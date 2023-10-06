#pragma once
#include "MapBuilder.h"
#include "Room.h"

namespace diablo_II 
{
	class			Player;
	class			Room;
	struct			Door;
	enum class		Room_States : uint8_t;
	struct			Box;
	int				GetPlayerIntFormat();

	class GameManager 
	{
	public:
					GameManager(){};
		void		Play(Player* aPlayer, Room* aRoom);
		void		Run();
	};
}