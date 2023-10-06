#pragma once
#include "PlayerManager.h"
#include <iostream>
#include "Player.h"

namespace diablo_II 
{
	void PlayerManager::DisplayPlayerStates() const 
	{
		std::cout << "\n----------------------------------------------------------\n";
		std::cout << "\n\tPlayer's Name : " << myPlayer.GetPlayerName() << '\n';
		std::cout << "\tPlayer's Health : " << myPlayer.GetPlayerHp() << '\n';
		std::cout << "\tPlayer's Strength : " << (int)myPlayer.GetPlayerStrength() << '\n';
		std::cout << "\tPlayer's Flexibility : " << (int)myPlayer.GetPlayerFlexibility() << '\n';
		std::cout << "\tPlayer's Physic : " << (int)myPlayer.GetPlayerPhysic() << '\n';
		std::cout << "\tPlayer's Carry Capacity : " << (int)myPlayer.GetPlayerCarryingCapacity() << '\n';
		std::cout << "\tPlayer's Defence : " << (int)myPlayer.GetPlayerDefence() << '\n';
		std::cout << "\tPlayer's Attack Damage : " << (int)myPlayer.GetPlayerAttackDamageValue() << '\n';
		std::cout << "\tPlayer's Current Weapon : " << myPlayer.GetPlayerCurrentWeapon() << "\n\n";
		for (auto* eachArmorPiece : { myPlayer.GetPlayerEquipedArmor().chest, myPlayer.GetPlayerEquipedArmor().shoulder, 
			myPlayer.GetPlayerEquipedArmor().arms, myPlayer.GetPlayerEquipedArmor().helmet, myPlayer.GetPlayerEquipedArmor().legs}) 
		{
			if (eachArmorPiece != nullptr) 
			{
				std::cout << "\tPlayer's Armor type : " << eachArmorPiece->GetItemName() << '\n';
			}
		}
		std::cout << "----------------------------------------------------------\n";
		system("pause");
	}

	void PlayerManager::PlayerGetDamage(const uint16_t& someDamage) 
	{
		myPlayer.GetPlayerHp() = myPlayer.GetPlayerHp() - (int)(80 * someDamage / (1 + myPlayer.GetPlayerDefence()));
		if (myPlayer.GetPlayerHp() <= 0) 
		{
			myPlayer.GetPlayerLifeState() = false;
		}
	}

	void PlayerManager::DisplayInventory() const  
	{
		for (auto& eachItem : *myPlayer.GetPlayerInventory()) 
		{
			eachItem->DisplayItem();
		}
	}

	void PlayerManager::DropItemsFromInventory(std::vector<Item*>* someItemInTheRoom, const uint8_t anItemIndex) 
	{
		someItemInTheRoom->push_back(myPlayer.GetPlayerInventory()->at(anItemIndex));
		myPlayer.GetPlayerInventory()->at(anItemIndex) = nullptr;
		myPlayer.GetPlayerInventory()->erase(myPlayer.GetPlayerInventory()->begin() + anItemIndex);
		std::cout << "\n----------------------------------------------------------";
		std::cout << "\n\tYou have dropped an item in this room \n";
		std::cout << "----------------------------------------------------------\n";
	}

	void PlayerManager::LootItem(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex) 
	{
		if (!(aSourceContainer->at(anItemIndex)->GetItemWeight() +  myPlayer.GetPlayerInventoryCurrentCapacity() > myPlayer.GetPlayerCarryingCapacity())) 
		{
			myPlayer.GetPlayerInventory()->push_back(aSourceContainer->at(anItemIndex));
			aSourceContainer->at(anItemIndex) = nullptr;
			aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tA new item has been added to the inventory!\n";
			std::cout << "----------------------------------------------------------\n";
		}
		else 
		{
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tYou don't have enough capacity in your inventory\n";
			std::cout << "----------------------------------------------------------\n";
		}
	}

	void PlayerManager::EquipArmor(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex) 
	{
		switch (aSourceContainer->at(anItemIndex)->GetItemTag()) 
		{
		case Item_Tag::ARMOR_ARMS:
		{
			if (myPlayer.GetPlayerEquipedArmor().arms != nullptr) 
			{
				UnEquipArmor(aSourceContainer, myPlayer.GetPlayerEquipedArmor().arms->GetItemTag());
			}
			myPlayer.GetPlayerEquipedArmor().arms = aSourceContainer->at(anItemIndex);
			myPlayer.GetPlayerDefence() += 30;
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tYou have equiped a new piece of armor : Arm \n";
			std::cout << "----------------------------------------------------------\n";
			aSourceContainer->at(anItemIndex) = nullptr;
			aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			break;
		}
		case Item_Tag::ARMOR_LEGS:
		{
			if (myPlayer.GetPlayerEquipedArmor().legs != nullptr) 
			{
				UnEquipArmor(aSourceContainer, myPlayer.GetPlayerEquipedArmor().legs->GetItemTag());
			}
			myPlayer.GetPlayerEquipedArmor().legs = aSourceContainer->at(anItemIndex);
			myPlayer.GetPlayerDefence() += 30;
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tYou have equiped a new piece of armor : Legs \n";
			std::cout << "----------------------------------------------------------\n";
			aSourceContainer->at(anItemIndex) = nullptr;
			aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			break;
		}
		case Item_Tag::ARMOR_HELMET:
		{
			if (myPlayer.GetPlayerEquipedArmor().helmet != nullptr) 
			{
				UnEquipArmor(aSourceContainer, myPlayer.GetPlayerEquipedArmor().helmet->GetItemTag());
			}
			myPlayer.GetPlayerEquipedArmor().helmet = aSourceContainer->at(anItemIndex);
			myPlayer.GetPlayerDefence() += 30;
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tYou have equiped a new piece of armor : Helmet \n";
			std::cout << "----------------------------------------------------------\n";
			aSourceContainer->at(anItemIndex) = nullptr;
			aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			break;
		}
		case Item_Tag::ARMOR_SHOULDER:
		{
			if (myPlayer.GetPlayerEquipedArmor().shoulder != nullptr) 
			{
				UnEquipArmor(aSourceContainer, myPlayer.GetPlayerEquipedArmor().shoulder->GetItemTag());
			}
			myPlayer.GetPlayerEquipedArmor().shoulder = aSourceContainer->at(anItemIndex);
			myPlayer.GetPlayerDefence() += 30;
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tYou have equiped a new piece of armor : Shoulder \n";
			std::cout << "----------------------------------------------------------\n";
			aSourceContainer->at(anItemIndex) = nullptr;
			aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			break;
		}
		case Item_Tag::ARMOR_CHEST:
		{
			if (myPlayer.GetPlayerEquipedArmor().chest != nullptr) 
			{
				UnEquipArmor(aSourceContainer, myPlayer.GetPlayerEquipedArmor().chest->GetItemTag());
			}
			myPlayer.GetPlayerEquipedArmor().chest = aSourceContainer->at(anItemIndex);
			myPlayer.GetPlayerDefence() += 30;
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tYou have equiped a new piece of armor : Chest \n";
			std::cout << "----------------------------------------------------------\n";
			aSourceContainer->at(anItemIndex) = nullptr;
			aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			break;
		}
		default:
			break;
		}
	}

	void PlayerManager::UnEquipArmor(std::vector<Item*>* aRoomItemContainer, Item_Tag anArmor) 
	{
		for (auto* eachArmorPiece : { myPlayer.GetPlayerEquipedArmor().chest, myPlayer.GetPlayerEquipedArmor().shoulder, 
			myPlayer.GetPlayerEquipedArmor().arms, myPlayer.GetPlayerEquipedArmor().helmet, myPlayer.GetPlayerEquipedArmor().legs }) 
		{
			if (eachArmorPiece != nullptr) 
			{
				if (eachArmorPiece->GetItemTag() == anArmor && !(myPlayer.GetPlayerInventoryCurrentCapacity() + eachArmorPiece->GetItemWeight() > myPlayer.GetPlayerCarryingCapacity())) 
				{
					myPlayer.GetPlayerInventory()->push_back(eachArmorPiece);
					myPlayer.GetPlayerDefence() -= 30;
					eachArmorPiece = nullptr;
					std::cout << "\n----------------------------------------------------------";
					std::cout << "\n\tThe armor has been move to inventory\n";
					std::cout << "----------------------------------------------------------\n";
				}
				else if (eachArmorPiece->GetItemTag() == anArmor && myPlayer.GetPlayerInventoryCurrentCapacity() + eachArmorPiece->GetItemWeight() > myPlayer.GetPlayerCarryingCapacity()) 
				{
					aRoomItemContainer->push_back(eachArmorPiece);
					myPlayer.GetPlayerDefence() -= 30;
					eachArmorPiece = nullptr;
					std::cout << "\n----------------------------------------------------------";
					std::cout << "\n\tThe armor has been droped in the current room due to lack of storage in the inventory\n";
					std::cout << "----------------------------------------------------------\n";
				}
			}
		}
	}

	void PlayerManager::ConsumePortion(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex) 
	{
		switch (aSourceContainer->at(anItemIndex)->GetItemTag())
		{
		case Item_Tag::PORTION_HP:
		{
			if (!(myPlayer.GetPlayerHp() + 50 > myPlayer.GetPlayerMaxHp())) 
			{
				myPlayer.GetPlayerHp() += 50;
				std::cout << "\n----------------------------------------------------------";
				std::cout << "\n\tYour helath has increased by 50\n";
				std::cout << "----------------------------------------------------------\n";
				delete aSourceContainer->at(anItemIndex);
				aSourceContainer->at(anItemIndex) = nullptr;
				aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			}
			else 
			{
				myPlayer.GetPlayerHp() = myPlayer.GetPlayerMaxHp();
				std::cout << "\n----------------------------------------------------------";
				std::cout << "\n\tYour helath has increased to full\n";
				std::cout << "----------------------------------------------------------\n";
				delete aSourceContainer->at(anItemIndex);
				aSourceContainer->at(anItemIndex) = nullptr;
				aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			}
			break;
		}
		case Item_Tag::PORTION_STRENGTH:
		{
			myPlayer.GetPlayerStrength() += 10;
			std::cout << "\n----------------------------------------------------------";
			std::cout << "\n\tYour strength has increased by 10\n";
			std::cout << "----------------------------------------------------------\n";
			delete aSourceContainer->at(anItemIndex);
			aSourceContainer->at(anItemIndex) = nullptr;
			aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
			break;
		}
		default:
			break;
		}
	}

	void PlayerManager::ActivatePlayerSpel(std::vector<Item*>* aSourceContainer, const uint8_t anItemIndex) 
	{
		myPlayer.GetPlayerSpelState() = true;
		myPlayer.GetPlayerSpelTimer() = 4;
		delete aSourceContainer->at(anItemIndex);
		aSourceContainer->at(anItemIndex) = nullptr;
		aSourceContainer->erase(aSourceContainer->begin() + anItemIndex);
	}

	void PlayerManager::CountSpelTimer() 
	{
		if (myPlayer.GetPlayerSpelTimer() > 0) 
		{
			myPlayer.GetPlayerSpelTimer()--;
		}

		if (myPlayer.GetPlayerSpelTimer() <= 0) {
			myPlayer.GetPlayerSpelState() = false;
		}
	}
}