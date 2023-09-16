#pragma once
#include <memory>
#include <vector>
#include <string>
#include <array>
#include "Stats.h"
namespace diablo_IV
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
		struct PlayerEquipedWeapon
		{
		private:
			std::shared_ptr<Item> leftHand;
			std::shared_ptr<Item> rightHand;
		public :
			void SetPlayerWeapon(eHand aHand, std::shared_ptr<Item> anItem);
			std:: shared_ptr<Item>& GetPlayerWeapon(eHand aHnad);
		};

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
		std::vector<std::shared_ptr<Item>>& GetPlayerSpellbook();

		bool& GetPlayerSpelState();
		const uint16_t				GetPlayerAttackDamageValue();
		const std::string& GetPlayerName() const;

		void SetStat(Stats::eStatIndex aStatIndex, int aValue);
		const int GetStat(Stats::eStatIndex aStatIndex) const;
		Stats& GetStats();
		void SetName(const std::string& aName);
		void SetPlayerWeapon(eHand aHand, std::shared_ptr<Item> anItem);
		std::shared_ptr<Item>& GetPlayerWeapon(eHand aHnad);
	private:
		struct PlayerEquipedWeapon myPlayerEquipedWeapon;
		Stats myStats;
		eRoomID						currentRoomID;
		bool						isPlayerSpelActive;
		uint8_t						playerSpelTimer;
		std::string					playerCurrentWeapon;

		std::vector<std::shared_ptr<Item>> playerInventory;
		std::vector<std::shared_ptr<Item>> playerEquipedArmour;
		std::vector<std::shared_ptr<Item>> playerSpelbook;
	};
}
