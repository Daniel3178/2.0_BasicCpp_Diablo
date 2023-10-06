#pragma once
#include <vector>
namespace diablo_II 
{
	struct		Item;
	enum class Box_State : uint8_t 
	{
		LOCKED,
		UNLOCKED,
		NO_LOCK,
		EMPTY
	};

	struct Box 
	{
	private: 
		std::vector<Item*>*		itemsInTheBox;
		Box_State				boxState;
		uint8_t					boxLockStrength;

	public :
								Box();
		std::vector<Item*>*		GetItemsInTheBox();
		void					SetItemsInTheBoxToNull();
		Box_State&				GetBoxState();
		uint8_t&				GetBoxLockStrength();
	};
}