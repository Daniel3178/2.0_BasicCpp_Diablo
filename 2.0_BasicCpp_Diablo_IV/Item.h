#pragma once
namespace diablo_IV 
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