#pragma once
#include "MapBuilder.h"
//#include "Room.h"
#include <vector>
#include <memory>
#include "Stats.h"

namespace diablo_III
{
	enum class						Room_States : uint8_t;
	enum class						Item_Tag : uint8_t;
	class							Enemy;
	class							Item;
	class							Room;
	enum class eRoomID;
	class Stats;
	class Player
	{

	public:
		Player(const std::string aNmae);
		Player(const std::string aName, const uint16_t aStrength, const uint16_t aPlayerFlexibility, const uint16_t aPlayerPhysic);
		~Player();
	
		uint8_t& GetPlayerSpelTimer();
		void						SetCurrentRoom(eRoomID aRoomID);
		const eRoomID& GetPlayerCurrentRoom() const;
		const std::string			GetPlayerCurrentWeapon();
		std::vector<std::shared_ptr<Item>>& GetPlayerInventory();
		bool						GetPlayerLifeState();
		std::vector<std::shared_ptr<Item>>& GetPlayerEquipedArmor();
		uint8_t						GetPlayerInventoryCurrentCapacity();
		bool& GetPlayerSpelState();
		const uint16_t				GetPlayerAttackDamageValue();
		const std::string& GetPlayerName() const;

		void SetStat(Stats::eStatIndex aStatIndex, int aValue);
		const int GetStat(Stats::eStatIndex aStatIndex) const;
		Stats& GetStats();
		void SetName(const std::string& aName);

	private:
		Stats myStats;
		eRoomID						currentRoomID;
		bool						isPlayerSpelActive;
		uint8_t						playerSpelTimer;
		std::string					playerCurrentWeapon;
		std::vector<std::shared_ptr<Item>>			playerInventory;
		std::vector<std::shared_ptr<Item>> playerEquipedArmour;
	};
}
