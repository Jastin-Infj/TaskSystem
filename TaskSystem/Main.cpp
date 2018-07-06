#include <iostream>
#include <string>

#include "System.h"
#include "TaskObject.h"
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
	std::pair<std::string, std::string> taskname = { "FFシリーズ","FF5" };
	auto obj = TaskObject::Create(&taskname);
	std::pair<std::string, std::string> taskname1 = { "FFシリーズ","FF6" };
	auto obj1 = TaskObject::Create(&taskname1);

	int i = 0;

	while (i < 3)
	{
		std::cout << i + 1 << "回目" << std::endl;
		++i;
		if (obj1 != nullptr)
		{
			std::cout  << obj1->getTaskname() << "存在中" << std::endl;
		}
		else
		{
			std::cout <<  obj1->getTaskname() << "死んだ" << std::endl;
		}
		Tasksystem->TasknameOutput();
		Tasksystem->UpDate();
		obj1->TaskKill();
	}
	std::cout << "解放します" << std::endl;
}

int main()
{
	Test();

	delete Tasksystem;

	system("pause");
}