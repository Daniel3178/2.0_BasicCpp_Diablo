#pragma once
#include "RoomManager.h"
#include "Room.h"

namespace diablo_I
{
	class Player;
	class Room;
	struct Door;
	enum class Room_States : uint8_t;
	class GameManager
	{

	public:
		GameManager();
		void RandomEnemyAttack(Player* aPlayer, std::vector<Enemy*>* someEnemies);
		int GetPlayerIntFormat();
		uint8_t GetPlayerCombatOption(Player* aPlayer, Room* aRoom);
		bool ExistEnemies(std::vector<Enemy*>* someEnemies);
		void CheckEnemyStateInRoom(Room* aRoom, uint8_t anIndex);
		void Combat(Player* aPlayer, Room* aRoom);
		uint8_t GetPlayerRoomChoiceOpt(std::vector<Door*>* someDoores);
		void ChoseRoom(Player* aPlayer, Room* aRoom);
		uint8_t GetPlayerRoomOpt(const std::string& aPlayerCurrentWeapon, std::vector<Enemy*>* someEnemies);
		void Play(Player* aPlayer, Room* aRoom);
		void Run();
	};
}