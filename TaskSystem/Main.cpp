#include <iostream>
#include <string>

#include "System.h"
#include "TaskObject.h"
#include "Sample1.h"



/*メモリリーク検知をする*/
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

System* Tasksystem;



void Test()
{
	Tasksystem = new System();
	std::pair<std::string, std::string> taskname1 = { "FFシリーズ","FF5" };
	auto obj = Sample1::Create(&taskname1);
}

int main()
{
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif


	Test();

	int i = 0;
	while (i < 3)
	{
		Tasksystem->UpDate();
		++i;
	}
	

	delete Tasksystem;
	Tasksystem = nullptr;
	system("pause");
}