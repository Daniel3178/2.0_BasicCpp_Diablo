#pragma once
#include<vector>
#include<memory>
namespace diablo_IV
{



		int	GetPlayerIntFormat();
		void ForceToReturn();
		
		template <typename T, typename T2> bool IsQuitPressed(std::vector<std::shared_ptr<T>>& aContainer, T2 aPlrOpt)
		{
			return aContainer.size() - aPlrOpt == -1;
		}

		template <typename T> bool IsQuitPressed(int aSizeOfContainer, T aPlrOpt)
		{
			return aSizeOfContainer - aPlrOpt == -1;
		}

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