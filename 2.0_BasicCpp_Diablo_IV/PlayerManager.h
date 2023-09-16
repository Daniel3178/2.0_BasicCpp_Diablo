#pragma once


namespace diablo_IV
{
	class				Player;
	class				Item;
	enum class			Item_Tag : uint8_t;
	enum class eArmourTag;
	enum class eWeaponTag;
	enum class eHand;
	class shared_ptr;

	class PlayerManager
	{
	private:
		Player& myPlayer;

	public:
		PlayerManager(Player& aPlayer) : myPlayer(aPlayer)
		{};
		void			DisplayPlayerStates() const;
		void			PlayerGetDamage(const uint16_t& someDamage);
		void			DisplayInventory()const;
		void			DropItemsFromInventory(std::vector<std::shared_ptr<Item>>& someItemInTheRoom, const uint8_t anItemIndex);
		void			LootItem(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex);
		void			EquipArmor(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex);
		void			UnEquipArmor(std::vector<std::shared_ptr<Item>>& aRoomItemContainer, eArmourTag anArmor);
		void			EquipWeapon(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex, eHand aHand);
		void			UnEquipWeapon(std::vector<std::shared_ptr<Item>>& aRoomItemContainer, const eHand aHand );
		void			ConsumePortion(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex);
		void			ActivatePlayerSpell(std::vector<std::shared_ptr<Item>>& aSourceContainer, const uint8_t anItemIndex);
		void			CountSpelTimer();
	};
}