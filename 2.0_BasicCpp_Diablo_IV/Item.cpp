#pragma once
#include<iostream>
#include "Item.h"
#include "ItemType.h"
#include "Stats.h"

namespace diablo_IV
{

	Item::Item(const ItemType& anItemType) : myItemType(&anItemType)
	{}

	const Stats& Item::GetStats() const
	{
		return myItemType->GetStats();
	}

}