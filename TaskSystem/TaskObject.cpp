#include <iostream>
#include <string>
#include "TaskObject.h"
#include "System.h"		//taskobjects���g�p�ł���悤�ɂ���

/*�R���X�g���N�^*/
KillSystem::KillSystem()
{
	this->killcount = 0;
}
KillSystem::~KillSystem(){}
/*���ł������邱�Ƃ��˗����܂�*/
void KillSystem::Kill()
{
	this->killcount++;
}
/*���ł����邩�ǂ����𔻒肵�܂�*/
bool KillSystem::KillCheck()
{
	return this->killcount > 0 ? true : false;
}
/*�L���J�E���^�[��Ԃ��܂�*/
int  KillSystem::getKillcount()const
{
	return this->killcount;
}

/*�R���X�g���N�^*/
TaskObject::TaskObject(std::pair<std::string, std::string> *taskname_)
{
	this->taskname = *taskname_;
	std::cout << "TaskObject" << std::endl;
}
/*�f�X�g���N�^*/
TaskObject::~TaskObject()
{
	this->Finalize();
	std::cout << this->getTaskname() << "~TaskObject()" << std::endl;
}
/*�I�u�W�F�N�g�𐶐����܂�*/
TaskObject::SP TaskObject::Create(std::pair<std::string,std::string> *taskname_,bool createflag)
{
	TaskObject::SP to = TaskObject::SP(new TaskObject(taskname_));
	if (to)
	{
		if (createflag)
		{
			to->Init();
			Tasksystem->Add(to);
			return to;
		}
	}
	return nullptr;
}
/*�^�X�N���Ԃ��܂�*/
std::string TaskObject::getTaskname()const
{
	return this->taskname.second;
}
/*�������������s���܂�*/
bool TaskObject::Init()
{
	std::cout << this->taskname.second << "init()" << std::endl;
	return true;
}
/*�X�V�������s���܂�*/
void TaskObject::UpDate()
{
	std::cout << this->taskname.second << "update()" << std::endl;
}
/*�`�揈�����s���܂�*/
void TaskObject::Render()
{
	std::cout << this->taskname.second << "render()" << std::endl;
}
/*����������s���܂�*/
bool TaskObject::Finalize()
{
	std::cout << this->taskname.second << "finalize()" << std::endl;
	return true;
}
/*�L���J�E���^�𑝉������܂�*/
void TaskObject::TaskKill()
{
	this->Kill();
}
/*kill�̃J�E���^��Ԃ��܂�*/
int  TaskObject::getKillCounter()const
{
	return this->getKillcount();
}