#pragma once
#include<vector>
#include<memory>
namespace diablo_IV
{



		int	GetPlayerIntFormat();

		template <typename T> void NullEliminator(std::vector<std::shared_ptr<T>>& aContainer)
		{
			auto& inventoryIterator = aContainer;

			for(auto iterator = inventoryIterator.begin(); iterator != inventoryIterator.end();)
			{
				if(*iterator == nullptr)
				{
					iterator = aContainer.erase(iterator);
				}
				else
				{
					iterator++;
				}
			}
		}

}