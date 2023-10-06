#include "ctr_mem_leak.h"
#include <iostream>
#include "GameManager.h"

int main()
{

#ifdef _DEBUG



	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	_CrtMemState ms_old, ms_new, ms_diff;

	_CrtMemCheckpoint(&ms_old);
	{
#endif // _DEBUG


		diablo_I::GameManager myGameManager;
		myGameManager.Run();


#ifdef _DEBUG
	}
	_CrtMemCheckpoint(&ms_new);

	if (_CrtMemDifference(&ms_diff, &ms_old, &ms_new))
	{
		std::cout << "Memory leaked: " << ms_diff.lTotalCount << " bytes." << std::endl;
		std::cout << "Press any key..." << std::endl;
		std::cin.get();
	}
	else
	{
		std::cout << "No Memory leaked found." << std::endl;
		std::cout << "Press any key..." << std::endl;
		std::cin.get();
	}
#endif // _DEBUG
	return 0;
}