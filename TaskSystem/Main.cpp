#include <iostream>

#include "System.h"
#include "TaskObject.h"
#include "Sample1.h"



System* Tasksystem;



void Test()
{
	Tasksystem = new System();
	std::pair<std::string, std::string> taskname1 = { "FFÉVÉäÅ[ÉY","FF5" };
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