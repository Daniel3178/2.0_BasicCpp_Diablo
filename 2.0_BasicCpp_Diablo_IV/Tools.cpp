#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include "Tools.h"

namespace diablo_IV
{
	int GetPlayerIntFormat()
	{
		unsigned int usrInput { 0 };
		std::cin >> usrInput;
		while(std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			std::cout << "Please answer with only digits : " << '\n';
			std::cin >> usrInput;
		}
		return usrInput;
	}
	void ForceToReturn()
	{
		int plrOpt { 0 };
		std::cout << "\t[Press " << 1 << " ] :: Quit \n";
		std::cout << "\n\tYour choice : ";

		do
		{
			plrOpt = GetPlayerIntFormat();
		}
		while(plrOpt != 1);
	}
}