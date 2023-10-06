#pragma once
#include "MapBuilder.h"
#include <vector>

namespace diablo_II 
{
	enum class						Room_States : uint8_t;
	enum class						Item_Tag : uint8_t;
	class							Enemy;
	struct							Item;
	class							Room;

	typedef struct Armor 
	{
	public:
		Item*						chest;
		Item*						shoulder;
		Item*						legs;
		Item*						arms;
		Item*						helmet;
	} Armor;

	class Player 
	{
	private:
		Armor						playerEquipedArmor;
		std::string					playerName;
		uint16_t					playerStrength;
		uint16_t					playerFlexibility;
		uint16_t					playerPhysic;
		uint16_t					playerAttackDamage;
		int							playerHp;
		int							playerMaxHp;
		uint16_t					playerCarryingCapacity;
		uint16_t					playerDefence;
		Room_States					currentRoomID;
		bool						isPlayerAlive;
		bool						isPlayerSpelActive;
		uint8_t						playerSpelTimer;
		std::string					playerCurrentWeapon;
		std::vector<Item*>*			playerInventory;

	public :
									Player(const std::string aNmae);
									Player(const std::string aName, const uint16_t aStrength,const uint16_t aPlayerFlexibility, const uint16_t aPlayerPhysic);
									~Player();
		int&						GetPlayerHp();
		uint16_t&					GetPlayerDefence();
		uint16_t&					GetPlayerCarryingCapacity();
		uint16_t&					GetPlayerFlexibility();
		uint16_t&					GetPlayerPhysic();
		uint16_t&					GetPlayerStrength();
		uint8_t&					GetPlayerSpelTimer();
		int&						GetPlayerMaxHp();
		void						SetCurrentRoom(Room_States aRoomID);
		const Room_States&			GetPlayerCurrentRoom() const;
		const std::string			GetPlayerCurrentWeapon();
		std::vector<Item*>*			GetPlayerInventory() const;
		bool&						GetPlayerLifeState();
		Armor&						GetPlayerEquipedArmor();
		uint8_t						GetPlayerInventoryCurrentCapacity();
	    bool&						GetPlayerSpelState() ;
		const uint16_t				GetPlayerAttackDamageValue() ;
		const std::string&			GetPlayerName() const;
	};
}
