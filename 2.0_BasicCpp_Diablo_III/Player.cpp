#include "Player.h"
#include "Item.h"
#include "Room.h"
namespace diablo_III
{
	Player::Player(const std::string aName)
	{
		SetStat(Stats::eStatIndex::eStrength, 10);
		SetStat(Stats::eStatIndex::eFlexibility, 20);
		SetStat(Stats::eStatIndex::ePhysic, 8);
		SetStat(Stats::eStatIndex::eMaxHealth, 200);
		SetStat(Stats::eStatIndex::eHealth, 200);
		int maxWeight = GetStat(Stats::eStatIndex::eStrength) + GetStat(Stats::eStatIndex::eFlexibility) / 3;
		SetStat(Stats::eStatIndex::eMaxWeight, maxWeight );
		int attackDamage = (GetStat(Stats::eStatIndex::eStrength) * GetStat(Stats::eStatIndex::eFlexibility) / 6);
		SetStat(Stats::eStatIndex::eAttack, attackDamage);
		int defence = GetStat(Stats::eStatIndex::ePhysic) + GetStat(Stats::eStatIndex::eFlexibility);
		SetStat(Stats::eStatIndex::eDefence, defence);
		currentRoomID = eRoomID::eRoom_A;

		playerSpelTimer = 0;
		playerInventory ={0};
		isPlayerSpelActive = false;
	};

	Player::Player(const std::string aName, const uint16_t aStrength, const uint16_t aPlayerFlexibility, const uint16_t aPlayerPhysic)
	{
		SetStat(Stats::eStatIndex::eStrength, 10);
		SetStat(Stats::eStatIndex::eFlexibility, 20);
		SetStat(Stats::eStatIndex::ePhysic, 8);
		SetStat(Stats::eStatIndex::eMaxHealth, 200);
		SetStat(Stats::eStatIndex::eHealth, 200);
		int maxWeight = GetStat(Stats::eStatIndex::eStrength) + GetStat(Stats::eStatIndex::eFlexibility) / 3;
		SetStat(Stats::eStatIndex::eMaxWeight, maxWeight);
		int attackDamage = (GetStat(Stats::eStatIndex::eStrength) * GetStat(Stats::eStatIndex::eFlexibility) / 6);
		SetStat(Stats::eStatIndex::eAttack, attackDamage);
		int defence = GetStat(Stats::eStatIndex::ePhysic) + GetStat(Stats::eStatIndex::eFlexibility);
		SetStat(Stats::eStatIndex::eDefence, defence);
		currentRoomID = eRoomID::eRoom_A;
		playerSpelTimer = 0;
		playerInventory = {0};
		isPlayerSpelActive = false;
	}

	Player::~Player()
	{
	}

	std::vector < std::shared_ptr<Item>> &Player::GetPlayerEquipedArmor()
	{
		return playerEquipedArmour;
	}


	void Player::SetCurrentRoom(eRoomID aRoomId)
	{
		currentRoomID = aRoomId;
	}

	std::vector<std::shared_ptr<Item>>& Player::GetPlayerInventory() 
	{
		return playerInventory;
	}

	const std::string Player::GetPlayerCurrentWeapon()
	{
		return playerCurrentWeapon;
	}

	const eRoomID& Player::GetPlayerCurrentRoom() const
	{
		return currentRoomID;
	};


	bool Player::GetPlayerLifeState()
	{
		return GetStat(Stats::eStatIndex::eHealth)>0;
	}

	const std::string& Player::GetPlayerName() const
	{
		return myStats.GetName();
	}

	const uint16_t Player::GetPlayerAttackDamageValue()
	{
		int playerDamage = GetStat(Stats::eStatIndex::eAttack);
		int playerStrength = GetStat(Stats::eStatIndex::eStrength);
		int playerPhysic = GetStat(Stats::eStatIndex::ePhysic);
		return (playerDamage + (playerStrength * playerPhysic)) / 3;
	}

	uint8_t Player::GetPlayerInventoryCurrentCapacity()
	{
		uint8_t sum { 0 };
		for(auto& eachItem : this->GetPlayerInventory())
		{
			if(eachItem != nullptr)
			{
			sum += eachItem->GetStats().GetStat(Stats::eStatIndex::eMaxWeight);

			}
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

	void Player::SetStat(Stats::eStatIndex aStatIndex, int aValue)
	{
		myStats.SetStat(aStatIndex, aValue);
	}

	const int Player::GetStat(Stats::eStatIndex aStatIndex) const
	{
		  const int resutl = myStats.GetStat(aStatIndex);
		  return resutl;
	}

	void Player::SetName(const std::string& aName)
	{
		myStats.SetName(aName);
	}
	 Stats& Player::GetStats() 
	{
		return myStats;
	}

}