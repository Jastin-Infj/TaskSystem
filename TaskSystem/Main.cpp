#include <iostream>

#include "System.h"
#include "TaskObject.h"

System* Tasksystem;

void Test()
{
	Tasksystem = new System();
	{
		std::pair<std::string, std::string> taskname = { "FF�V���[�Y","FF5" };
		auto obj = TaskObject::Create(&taskname);
	}
		std::pair<std::string, std::string> taskname = { "FF�V���[�Y","FF6" };
		auto obj1 = TaskObject::Create(&taskname);
		obj1->TaskKill();
		Tasksystem->Destory();			//�f�X�g���N�^���Ă΂�ė~����
		Tasksystem->TasknameOutput();
		Tasksystem->UpDate();
}

int main()
{
	Test();

	Tasksystem->TaskObjectDelete();
	Tasksystem = nullptr;
	system("pause");
}