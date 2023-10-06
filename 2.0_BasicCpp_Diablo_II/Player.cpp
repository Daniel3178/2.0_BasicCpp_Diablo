#include "Player.h"
#include "Item.h"

namespace diablo_II 
{
	Player::Player(const std::string aName) : playerName(aName)
	{
		playerStrength = 10;
		playerFlexibility = 20;
		playerPhysic = 8;
		playerMaxHp = 200;
		playerHp = playerMaxHp;
		playerCarryingCapacity = playerStrength + (uint16_t)(playerFlexibility / 3);
		playerAttackDamage = (uint16_t)((playerStrength * playerFlexibility) / 6);
		playerDefence = playerPhysic + playerFlexibility;
		currentRoomID = Room_States::ROOM_A;
		playerCurrentWeapon = "Sword";
		playerEquipedArmor.chest = nullptr;
		playerEquipedArmor.shoulder = nullptr;
		playerEquipedArmor.legs = nullptr;
		playerEquipedArmor.arms = nullptr;
		playerEquipedArmor.helmet = nullptr;
		playerSpelTimer = 0;
		playerInventory = new std::vector<Item*>{};
		isPlayerSpelActive = false;
		isPlayerAlive = true;
	};

	Player::Player(const std::string aName, const uint16_t aStrength, const uint16_t aPlayerFlexibility, const uint16_t aPlayerPhysic) :
		playerName(aName), playerStrength(aStrength), playerFlexibility(aPlayerFlexibility), playerPhysic(aPlayerPhysic)
	{
		playerMaxHp = 200;
		playerHp = playerMaxHp;
		playerCarryingCapacity = uint16_t(playerStrength + playerFlexibility / 3);
		playerAttackDamage = playerStrength * playerFlexibility;
		playerDefence = playerPhysic + playerFlexibility;
		currentRoomID = Room_States::ROOM_A;
		playerCurrentWeapon = "Sword";
		playerEquipedArmor.chest = nullptr;
		playerEquipedArmor.shoulder = nullptr;
		playerEquipedArmor.legs = nullptr;
		playerEquipedArmor.arms = nullptr;
		playerEquipedArmor.helmet = nullptr;
		playerSpelTimer = 0;
		playerInventory = new std::vector<Item*>{};
		isPlayerSpelActive = false;
		isPlayerAlive = true;
	}

	Player::~Player() 
	{
		if (this->GetPlayerInventory() != nullptr) 
		{
			for (auto& eachItem : *this->GetPlayerInventory()) 
			{
				delete eachItem;
				eachItem = nullptr;
			}
			this->GetPlayerInventory()->clear();
			delete this->GetPlayerInventory();
			playerInventory = nullptr;
		}

		for (auto* eachArmorPiece : { playerEquipedArmor.chest, playerEquipedArmor.shoulder, playerEquipedArmor.arms, playerEquipedArmor.helmet, playerEquipedArmor.legs }) 
		{
			if (eachArmorPiece != nullptr) 
			{
				delete eachArmorPiece;
				eachArmorPiece = nullptr;
			}
		}
	}

	uint16_t& Player::GetPlayerDefence() 
	{
		return playerDefence;
	}

	uint16_t& Player::GetPlayerCarryingCapacity() 
	{
		return playerCarryingCapacity;
	}

	uint16_t& Player::GetPlayerFlexibility() 
	{
		return playerFlexibility;
	}

	uint16_t& Player::GetPlayerPhysic() 
	{
		return playerPhysic;
	}

	Armor& Player::GetPlayerEquipedArmor() 
	{
		return playerEquipedArmor;
	}

	int& Player::GetPlayerMaxHp() 
	{
		return playerMaxHp;
	}

	void Player::SetCurrentRoom(Room_States aRoomId) 
	{
		currentRoomID = aRoomId;
	}

	std::vector<Item*>* Player::GetPlayerInventory() const 
	{
		return playerInventory;
	}

	const std::string Player::GetPlayerCurrentWeapon() 
	{
		return playerCurrentWeapon;
	}

	const Room_States& Player::GetPlayerCurrentRoom() const 
	{
		return currentRoomID;
	};

	uint16_t& Player::GetPlayerStrength() 
	{
		return playerStrength;
	}

	int& Player::GetPlayerHp() 
	{
		return playerHp;
	}

	bool& Player::GetPlayerLifeState() 
	{
		return isPlayerAlive;
	}

	const std::string& Player::GetPlayerName() const 
	{
		return playerName;
	}

	const uint16_t Player::GetPlayerAttackDamageValue() 
	{
		return (playerAttackDamage + (playerStrength * playerPhysic)) / 3;
	}

	uint8_t Player::GetPlayerInventoryCurrentCapacity() 
	{
		uint8_t sum{ 0 };
		for (auto& eachItem : *this->GetPlayerInventory()) 
		{
			sum += eachItem->GetItemWeight();
		}
		return sum;
	}

	uint8_t& Player::GetPlayerSpelTimer() 
	{
		return playerSpelTimer;
	}

	bool& Player::GetPlayerSpelState() 
	{
		return isPlayerSpelActive;
	}
}