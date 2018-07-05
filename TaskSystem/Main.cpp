#include <iostream>

#include "System.h"
#include "TaskObject.h"

System* Tasksystem;

void Test()
{
	Tasksystem = new System();
	{
		std::pair<std::string, std::string> taskname = { "FFシリーズ","FF5" };
		auto obj = TaskObject::Create(&taskname);
	}
	{
		std::pair<std::string, std::string> taskname = { "FFシリーズ","FF6" };
		auto obj = TaskObject::Create(&taskname);
		Tasksystem->TasknameOutput();
		Tasksystem->UpDate();
	}
	Tasksystem->Render();
}

int main()
{
	Test();

	delete Tasksystem;
	Tasksystem = nullptr;
	system("pause");
}