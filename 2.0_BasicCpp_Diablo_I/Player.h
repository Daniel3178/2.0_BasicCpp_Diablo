#pragma once
#include "RoomManager.h"

namespace diablo_I
{
	enum class Room_States : uint8_t;
	class Enemy;

	class Player
	{
	public:
		Player(const std::string aNmae);
		Player(const std::string aName, const uint16_t aStrength, const uint16_t aPlayerFlexibility, const uint16_t aPlayerPhysic);
		int& GetPlayerHp();
		const uint16_t& GetPlayerStrength() const;
		void SetCurrentRoom(Room_States aRoomID);
		const Room_States& GetPlayerCurrentRoom() const;
		const std::string GetPlayerCurrentWeapon();
		bool& GetPlayerLifeState();
		void DisplayPlayerStates() const;
		const std::string& GetPlayerName() const;
		void PlayerGetDamage(const uint16_t& someDamage);
		const uint16_t& GetPlayerAttackDamageValue();

	private:
		std::string playerName;
		uint16_t playerStrength;
		uint16_t playerFlexibility;
		uint16_t playerPhysic;
		uint16_t playerAttackDamage;
		int playerHp;
		uint16_t playerCarryingCapacity;
		uint16_t playerDefence;
		Room_States currentRoomID;
		bool playerLifeState;
		std::string playerCurrentWeapon;
	};
}
