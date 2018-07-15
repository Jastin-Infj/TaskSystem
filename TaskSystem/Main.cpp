/*メモリリーク検知をする*/
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include <iostream>
#include <string>
#include "../TaskSystem/TaskSystem/Task_Example.h"
#include "../TaskSystem/TaskSystem/TaskSystem.h"

TaskSystem* taskSystem;
typedef std::pair<std::string, std::string> PSTRING;


void Test()
{
	{
		PSTRING taskname = { "テスト","Sample1" };
		auto Sample = TaskObjectExample::Create(taskname);
		Sample->setDrawOrder(0.3f);
	}
	{
		PSTRING taskname = { "テスト","Sample2" };
		auto Sample = TaskObjectExample::Create(taskname);
		Sample->setDrawOrder(0.2f);
	}


	int i = 0;
	while (i < 3)
	{
		i++;
		taskSystem->UpDate();
	}
}
int main()
{
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	taskSystem = new TaskSystem();

	Test();

	delete taskSystem;
	taskSystem = nullptr;
	system("pause");
}