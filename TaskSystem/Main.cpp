#include <iostream>

#include "System.h"
#include "TaskObject.h"
#include "Sample1.h"

System* Tasksystem;



void Test()
{
	Tasksystem = new System();
	{
		std::pair<std::string, std::string> taskname1 = { "FF�V���[�Y","FF5" };
		auto obj = Sample1::Create(&taskname1);
	}
		std::pair<std::string, std::string> taskname2 = { "FF�V���[�Y","FF6" };
		auto obj1 = TaskObject::Create(&taskname2);
		
}

int main()
{
	Test();

	for (int i = 0; i < 3; ++i)
	{
		Tasksystem->UpDate();
		Tasksystem->Render();
		Tasksystem->Destory();
		if (i == 1)
		{
			{
				std::pair<std::string, std::string> taskname = {"FF�V���[�Y","FF5"};
				auto objs = Tasksystem->GetTask<Sample1>(&taskname);
				objs->Kill();
			}
		}
	}

	//delete  Tasksystem;
	Tasksystem = nullptr;
	system("pause");
}