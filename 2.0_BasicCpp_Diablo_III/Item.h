#pragma once
#include <iostream>
namespace diablo_III 
{
	class ItemType;
	class Stats;

	class Item
	{
	private:
		const ItemType* myItemType;

	public:
		Item(const ItemType& anItemType);
		const Stats& GetStats() const;

	};
}