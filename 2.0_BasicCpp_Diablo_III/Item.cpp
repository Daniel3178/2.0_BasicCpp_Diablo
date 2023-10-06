#pragma once
#include "Item.h"
#include "ItemType.h"
#include "Stats.h"

namespace diablo_III
{

	Item::Item(const ItemType& anItemType) : myItemType(&anItemType)
	{}

	const Stats& Item::GetStats() const
	{
		return myItemType->GetStats();
	}

}