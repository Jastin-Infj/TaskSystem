/*メモリリーク検知をする*/
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include <iostream>
#include <string>
#include "TaskObject.h"
#include "Sample1.h"
#include "TaskSystem.h"

TaskSystem* taskSystem;
typedef std::pair<std::string, std::string> PSTRING;


void Test()
{
	{
		PSTRING taskname = { "FF","FF5" };
		auto s = Sample1::Create(&taskname);
	}
}
void Test1()
{
	int i = 0;
	while (i < 3)
	{
		taskSystem->UpDate();
		++i;
	}
	std::pair<std::string, std::string> taskname = { "FFシリーズ","FF5" };
	auto sample1 = taskSystem->GetTasks<Sample1>(taskname);

	for (auto s = sample1->begin(); s != sample1->end(); ++s)
	{
		std::cout << (*s)->getTaskname().second << std::endl;
	}

	
}

int main()
{
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	taskSystem = new TaskSystem();

	Test();
	Test1();

	delete taskSystem;
	taskSystem = nullptr;
	system("pause");
}