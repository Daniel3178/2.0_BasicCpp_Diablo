#include "Player.h"
namespace diablo_I
{
	Player::Player(const std::string aName) :
		playerName(aName)
	{
		playerStrength = 10;
		playerFlexibility = 30;
		playerPhysic = 8;

		playerHp = playerPhysic * 4 + playerStrength * 6 + playerFlexibility;
		playerCarryingCapacity = playerStrength + (uint16_t) (playerFlexibility / 3);
		playerAttackDamage = (uint16_t) ((playerStrength * playerFlexibility) / 6);
		playerDefence = playerPhysic + playerFlexibility;
		currentRoomID = Room_States::ROOM_A;
		playerCurrentWeapon = "Sword";
		playerLifeState = true;
	};

	Player::Player(const std::string aName, const uint16_t aStrength, const uint16_t aPlayerFlexibility, const uint16_t aPlayerPhysic) :
		playerName(aName), playerStrength(aStrength), playerFlexibility(aPlayerFlexibility), playerPhysic(aPlayerPhysic)
	{

		playerHp = playerPhysic * 4 + playerStrength * 6 + playerFlexibility;
		playerCarryingCapacity = playerStrength + playerFlexibility / 3;
		playerAttackDamage = playerStrength * playerFlexibility;
		playerDefence = playerPhysic + playerFlexibility;
		currentRoomID = Room_States::ROOM_A;
		playerCurrentWeapon = "Sword";
		playerLifeState = true;
	}

	void Player::SetCurrentRoom(Room_States aRoomId)
	{
		currentRoomID = aRoomId;
	}

	const std::string Player::GetPlayerCurrentWeapon()
	{
		return playerCurrentWeapon;
	}
	
	const Room_States& Player::GetPlayerCurrentRoom() const
	{
		return currentRoomID;
	};

	const uint16_t& Player::GetPlayerStrength() const
	{
		return playerStrength;
	}
	
	int& Player::GetPlayerHp()
	{
		return playerHp;
	}
	
	bool& Player::GetPlayerLifeState()
	{
		return playerLifeState;
	}
	
	const std::string& Player::GetPlayerName() const
	{
		return playerName;
	}
	
	void Player::PlayerGetDamage(const uint16_t& someDamage)
	{
		playerHp -= int(someDamage);
		if (playerHp <= 0)
		{
			playerLifeState = false;
		}
	}

	const uint16_t& Player::GetPlayerAttackDamageValue()
	{
		return playerAttackDamage;

	}
	
	void Player::DisplayPlayerStates() const
	{
		std::cout << "\n\nPlayer's Name : " << playerName << '\n';
		std::cout << "Player's Health : " << playerHp << '\n';
		std::cout << "Player's Strength : " << (int) playerStrength << '\n';
		std::cout << "Player's Flexibility : " << (int) playerFlexibility << '\n';
		std::cout << "Player's Physic : " << (int) playerPhysic << '\n';
		std::cout << "Player's Carry Capacity : " << (int) playerCarryingCapacity << '\n';
		std::cout << "Player's Defence : " << (int) playerDefence << '\n';
		std::cout << "Player's Attack Damage : " << (int) playerAttackDamage << '\n';
		std::cout << "Player's Current Weapon : " << playerCurrentWeapon << "\n\n";
		system("pause");

	}
}