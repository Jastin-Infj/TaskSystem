#include <iostream>
#include <string>

#include "System.h"
#include "TaskObject.h"

/*���������[�N���m������*/
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
	std::pair<std::string, std::string> taskname = { "FF�V���[�Y","FF5" };
	auto obj = TaskObject::Create(&taskname);
	std::pair<std::string, std::string> taskname1 = { "FF�V���[�Y","FF6" };
	auto obj1 = TaskObject::Create(&taskname1);
}

int main()
{
	Test();


	system("pause");
}