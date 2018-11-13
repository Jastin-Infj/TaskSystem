/*���������[�N���m������*/
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include <iostream>
#include <string>
#include "../TaskSystem/TaskSystem/TaskSystem.h"
#include "../TaskSystem/TaskSystem/TaskSystem_GameObject.h"
#include "ResourceManager\ResourceManager.h"

TaskSystem* taskSystem;
ResourceManager* resourceManagager;
typedef std::pair<std::string, std::string> PSTRING;


void Test()
{
	{
		std::string sceceName = "�e�X�g";
		std::string sceceTag = "�^�O";
		PSTRING taskname = {sceceName,sceceTag };
		TaskSystemGameObject::Create(taskname);
	}
	int i = 0;
	while (i < 2)
	{
		taskSystem->Update();
		++i;
	}
}
int main()
{
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	taskSystem = new TaskSystem();
	resourceManagager = new ResourceManager();

	Test();

	delete taskSystem;
	delete resourceManagager;
	taskSystem = nullptr;
	resourceManagager = nullptr;
	system("pause");
}