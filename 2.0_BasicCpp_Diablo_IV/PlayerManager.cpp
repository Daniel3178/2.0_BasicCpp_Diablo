#pragma once
#include<vector>
#include <iostream>
#include <memory>
#include "Tools.h"
#include "PlayerManager.h"
#include <iostream>
#include "Player.h"
#include "Item.h"

namespace diablo_IV
{
	void PlayerManager::DisplayPlayerStates() const
	{
		std::cout << "\n\t----------------------------------------------------------\n";
		std::cout << "\n\tPlayer's Name : " << myPlayer.GetPlayerName() << '\n';
		std::cout << "\tPlayer's Health : " << myPlayer.GetStat(Stats::eStatIndex::eHealth) << '\n';
		std::cout << "\tPlayer's Strength : " << (int) myPlayer.GetStat(Stats::eStatIndex::eStrength) << '\n';
		std::cout << "\tPlayer's Flexibility : " << (int) myPlayer.GetStat(Stats::eStatIndex::eFlexibility) << '\n';
		std::cout << "\tPlayer's Physic : " << (int) myPlayer.GetStat(Stats::eStatIndex::ePhysic) << '\n';
		std::cout << "\tPlayer's Carry Capacity : " << (int) myPlayer.GetStat(Stats::eStatIndex::eMaxWeight) << '\n';
		std::cout << "\tPlayer's Defence : " << (int) myPlayer.GetStat(Stats::eStatIndex::eDefence) << '\n';
		std::cout << "\tPlayer's Attack Damage : " << (int) myPlayer.GetPlayerAttackDamageValue() << '\n';
		std::string playerLeftHandWeaponName = myPlayer.GetPlayerWeapon(eHand::eLeftHand) == nullptr ? "empty" : 
			myPlayer.GetPlayerWeapon(eHand::eLeftHand)->GetStats().GetName();
		std::string playerRighttHandWeaponName = myPlayer.GetPlayerWeapon(eHand::eRightHand) == nullptr ? "empty" : 
			myPlayer.GetPlayerWeapon(eHand::eRightHand)->GetStats().GetName();
		std::cout << "\tPlayer's left hand weapon : " + playerLeftHandWeaponName << '\n';
		std::cout << "\tPlayer's Right hand weapon : " + playerRighttHandWeaponName << '\n';
		for(auto& eachArmourPiece : myPlayer.GetPlayerEquipedArmor())
		{
			std::cout << "\tPlayer's armour type : " << eachArmourPiece->GetStats().GetName() << '\n';
		}
		std::cout << "\t----------------------------------------------------------\n";
		system("pause");
	}

	void PlayerManager::PlayerGetDamage(const uint16_t& someDamage)
	{
		int playerDefence = myPlayer.GetStat(Stats::eStatIndex::eDefence);
		myPlayer.GetStats().TakeDamage(80 * someDamage / (1 + playerDefence));
	}

	void PlayerManager::DisplayInventory() const
	{
		for(auto& eachItem : myPlayer.GetPlayerInventory())
		{
			std::cout << "\n\t" << eachItem->GetStats().GetName() << '\n';
		}
	}

	void PlayerManager::DropItemsFromInventory(std::vector<std::shared_ptr<Item>>& someItemInTheRoom, const uint8_t anItemIndex)
	{
		someItemInTheRoom.push_back(myPlayer.GetPlayerInventory().at(anItemIndex));
		myPlayer.GetPlayerInventory().erase(myPlayer.GetPlayerInventory().begin() + anItemIndex);
		std::cout << "\n\t----------------------------------------------------------";
		std::cout << "\n\tYou have dropped an item in this room \n";
		std::cout << "\t----------------------------------------------------------\n";
	}

	void PlayerManager::LootItem(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex)
	{
		bool isPlayerSlotAvailable { false };

		auto& playerEquiptedArmor = myPlayer.GetPlayerEquipedArmor();

		if(aSourceContainer.at(anItemIndex)->GetStats().GetTag() == eItemTag::eArmour)
		{
			isPlayerSlotAvailable = true;

			for(auto equipIterator = playerEquiptedArmor.begin(); equipIterator != playerEquiptedArmor.end(); equipIterator++)
			{
				if((*equipIterator)->GetStats().GetArmourTag() == aSourceContainer.at(anItemIndex)->GetStats().GetArmourTag())
				{
					isPlayerSlotAvailable = false;
				}
			}
		}

		if(!(aSourceContainer.at(anItemIndex)->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) + myPlayer.GetPlayerInventoryCurrentCapacity() > myPlayer.GetStat(Stats::eStatIndex::eMaxWeight))
			&& aSourceContainer.at(anItemIndex)->GetStats().GetTag() != eItemTag::eSpell && !isPlayerSlotAvailable)
		{
			myPlayer.GetPlayerInventory().push_back(aSourceContainer.at(anItemIndex));
			aSourceContainer.at(anItemIndex) = nullptr;
			aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);
			std::cout << "\n\t----------------------------------------------------------";
			std::cout << "\n\tA new item has been added to the inventory!\n";
			std::cout << "\t----------------------------------------------------------\n";
		}
		else if(!(aSourceContainer.at(anItemIndex)->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) + myPlayer.GetPlayerInventoryCurrentCapacity() > myPlayer.GetStat(Stats::eStatIndex::eMaxWeight))
			&& aSourceContainer.at(anItemIndex)->GetStats().GetTag() != eItemTag::eSpell && isPlayerSlotAvailable)
		{
			this->EquipArmor(aSourceContainer, anItemIndex);
		}
		else if(aSourceContainer.at(anItemIndex)->GetStats().GetTag() == eItemTag::eSpell)
		{
			myPlayer.GetPlayerSpellbook().push_back(aSourceContainer.at(anItemIndex));
			aSourceContainer.at(anItemIndex) = nullptr;
			aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);
			std::cout << "\n\t----------------------------------------------------------";
			std::cout << "\n\tA new spell has been added to the spelbook!\n";
			std::cout << "\t----------------------------------------------------------\n";
		}
		else
		{
			std::cout << "\n\t----------------------------------------------------------";
			std::cout << "\n\tYou don't have enough capacity in your inventory\n";
			std::cout << "\t----------------------------------------------------------\n";
		}
	}

	void PlayerManager::EquipArmor(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex)
	{

		for(auto& eachArmourPiece : myPlayer.GetPlayerEquipedArmor())
		{
			if(eachArmourPiece != nullptr)
			{

				if(eachArmourPiece->GetStats().GetArmourTag() == aSourceContainer.at(anItemIndex)->GetStats().GetArmourTag())
				{
					UnEquipArmor(aSourceContainer, eachArmourPiece->GetStats().GetArmourTag());

				}
			}
		}
		myPlayer.GetPlayerEquipedArmor().push_back(aSourceContainer.at(anItemIndex));
		myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eDefence, aSourceContainer.at(anItemIndex)->GetStats().GetStat(Stats::eStatIndex::eDefence));
		std::cout << "\n\t----------------------------------------------------------";
		std::cout << "\n\tYou have equiped a new piece of armor : " << aSourceContainer.at(anItemIndex)->GetStats().GetName() << '\n';
		std::cout << "\t----------------------------------------------------------\n";
		aSourceContainer.at(anItemIndex) = nullptr;
		aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);

	}
	void PlayerManager::EquipWeapon(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex, eHand aHand)
	{
		if(myPlayer.GetPlayerWeapon(aHand) != nullptr)
		{
			UnEquipWeapon(aSourceContainer, aHand);
		}
		else
		{
		myPlayer.SetPlayerWeapon(aHand, aSourceContainer.at(anItemIndex));
		myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eAttack, aSourceContainer.at(anItemIndex)->GetStats().GetStat(Stats::eStatIndex::eAttack));
		std::cout << "\n\t----------------------------------------------------------";
		std::cout << "\n\tYou have equiped a new weapon: " << aSourceContainer.at(anItemIndex)->GetStats().GetName() << " in your: ";
		aHand == eHand::eLeftHand ? std::cout <<"left hand\n" : std::cout<<"right hand\n";
		std::cout << "\t----------------------------------------------------------\n";
		aSourceContainer.at(anItemIndex) = nullptr;
		aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);

		}

	}
	void PlayerManager::UnEquipArmor(std::vector<std::shared_ptr<Item>>& aRoomItemContainer, eArmourTag anArmor)
	{
		for(int i = 0; i < myPlayer.GetPlayerEquipedArmor().size(); i++)
		{

			if(myPlayer.GetPlayerEquipedArmor().at(i) != nullptr)
			{
				if(myPlayer.GetPlayerEquipedArmor().at(i)->GetStats().GetArmourTag() == anArmor && !(myPlayer.GetPlayerInventoryCurrentCapacity() + myPlayer.GetPlayerEquipedArmor().at(i)->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) > myPlayer.GetStat(Stats::eStatIndex::eMaxWeight)))
				{
					myPlayer.GetPlayerInventory().push_back(myPlayer.GetPlayerEquipedArmor().at(i));
					myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eDefence, -1 * myPlayer.GetPlayerEquipedArmor().at(i)->GetStats().GetStat(Stats::eStatIndex::eDefence));
					myPlayer.GetPlayerEquipedArmor().at(i) = nullptr;
					myPlayer.GetPlayerEquipedArmor().erase(myPlayer.GetPlayerEquipedArmor().begin() + i);
					std::cout << "\n\t----------------------------------------------------------";
					std::cout << "\n\tThe armor has been moved to inventory\n";
					std::cout << "\t----------------------------------------------------------\n";
				}
				else if(myPlayer.GetPlayerEquipedArmor().at(i)->GetStats().GetArmourTag() == anArmor && myPlayer.GetPlayerInventoryCurrentCapacity() + myPlayer.GetPlayerEquipedArmor().at(i)->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) > myPlayer.GetStat(Stats::eStatIndex::eMaxWeight))
				{
					aRoomItemContainer.push_back(myPlayer.GetPlayerEquipedArmor().at(i));
					myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eDefence, -1 * myPlayer.GetPlayerEquipedArmor().at(i)->GetStats().GetStat(Stats::eStatIndex::eDefence));
					myPlayer.GetPlayerEquipedArmor().at(i) = nullptr;
					myPlayer.GetPlayerEquipedArmor().erase(myPlayer.GetPlayerEquipedArmor().begin() + i);
					std::cout << "\n\t----------------------------------------------------------";
					std::cout << "\n\tThe armor has been droped in the current room due to lack of storage in the inventory\n";
					std::cout << "\t----------------------------------------------------------\n";
				}
			}

		}
	}
	void PlayerManager::UnEquipWeapon(std::vector<std::shared_ptr<Item>>& aRoomItemContainer, const eHand aHand)
	{
		if( myPlayer.GetPlayerWeapon(aHand) != nullptr)
		{
			if(!(myPlayer.GetPlayerInventoryCurrentCapacity() + myPlayer.GetPlayerWeapon(aHand)->GetStats().GetStat(Stats::eStatIndex::eMaxWeight) > myPlayer.GetStat(Stats::eStatIndex::eMaxWeight)))
			{
				myPlayer.GetPlayerInventory().push_back(myPlayer.GetPlayerWeapon(aHand));
				myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eAttack, -1 * myPlayer.GetPlayerWeapon(aHand)->GetStats().GetStat(Stats::eStatIndex::eAttack));
				myPlayer.SetPlayerWeapon(aHand, nullptr);
				std::cout << "\n\t----------------------------------------------------------";
				std::cout << "\n\tThe weapon has been moved to inventory\n";
				std::cout << "\t----------------------------------------------------------\n";
			}
			else
			{
				aRoomItemContainer.push_back(myPlayer.GetPlayerWeapon(aHand));
				myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eAttack, -1 * myPlayer.GetPlayerWeapon(aHand)->GetStats().GetStat(Stats::eStatIndex::eAttack));
				myPlayer.SetPlayerWeapon(aHand, nullptr);
				std::cout << "\n\t----------------------------------------------------------";
				std::cout << "\n\tThe armor has been droped in the current room due to lack of storage in the inventory\n";
				std::cout << "\t----------------------------------------------------------\n";
			}

		}
	}

	void PlayerManager::ConsumePortion(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex)
	{

		if(aSourceContainer.at(anItemIndex)->GetStats().GetPortionTag() == ePortionTag::eHealth)
		{
			if(myPlayer.GetStat(Stats::eStatIndex::eHealth) + aSourceContainer.at(anItemIndex)->GetStats().GetStat(Stats::eStatIndex::eHealth) >
				myPlayer.GetStat(Stats::eStatIndex::eMaxHealth))
			{

				myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eHealth, myPlayer.GetStat(Stats::eStatIndex::eMaxHealth));
				std::cout << "\n\t----------------------------------------------------------";
				std::cout << "\n\tYou have consumed a portion : " << aSourceContainer.at(anItemIndex)->GetStats().GetName() << '\n';
				std::cout << "\t----------------------------------------------------------\n";
				aSourceContainer.at(anItemIndex) = nullptr;
				aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);
			}
			else
			{
				myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eHealth, aSourceContainer.at(anItemIndex)->GetStats().GetStat(Stats::eStatIndex::eHealth) );
				std::cout << "\n\t----------------------------------------------------------";
				std::cout << "\n\tYou have consumed a new portion : " << aSourceContainer.at(anItemIndex)->GetStats().GetName() << '\n';
				std::cout << "\t----------------------------------------------------------\n";
				aSourceContainer.at(anItemIndex) = nullptr;
				aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);
			}
		}
		else if(aSourceContainer.at(anItemIndex)->GetStats().GetPortionTag() == ePortionTag::eStrength)
		{
			myPlayer.GetStats().ChangeStat(Stats::eStatIndex::eStrength, aSourceContainer.at(anItemIndex)->GetStats().GetStat(Stats::eStatIndex::eStrength) );

			std::cout << "\n\t----------------------------------------------------------";
			std::cout << "\n\tYou have consumed a new portion : " << aSourceContainer.at(anItemIndex)->GetStats().GetName() << '\n';
			std::cout << "\t----------------------------------------------------------\n";
			aSourceContainer.at(anItemIndex) = nullptr;
			aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);
		}

	}

	void PlayerManager::ActivatePlayerSpell(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex)
	{
		myPlayer.GetPlayerSpelState() = true;
		myPlayer.GetPlayerSpelTimer() = 4;
		aSourceContainer.erase(aSourceContainer.begin() + anItemIndex);
	}

	void PlayerManager::CountSpelTimer()
	{
		if(myPlayer.GetPlayerSpelTimer() > 0)
		{
			myPlayer.GetPlayerSpelTimer()--;
		}

		if(myPlayer.GetPlayerSpelTimer() <= 0)
		{
			myPlayer.GetPlayerSpelState() = false;
		}
	}
}