#include <iostream>
#include <string>
#include "TaskObject.h"
#include "System.h"		//taskobjects���g�p�ł���悤�ɂ���

/*�R���X�g���N�^*/
KillSystem::KillSystem()
{
	this->killcount = 0;
}
KillSystem::~KillSystem() {}
/*���ł������邱�Ƃ��˗����܂�*/
void KillSystem::KillCount()
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
TaskObject::TaskObject()
{
	std::cout << "TaskObject()" << std::endl;
}
/*�f�X�g���N�^*/
TaskObject::~TaskObject()
{
	std::cout << "~TaskObject()" << std::endl;
}
/*�I�u�W�F�N�g�𐶐����܂�*/
TaskObject::SP TaskObject::Create(std::pair<std::string,std::string> *taskname_,bool createflag)
{
	TaskObject::SP to = TaskObject::SP(new TaskObject());
	if (to)
	{
		if (createflag)
		{
			/* �^�X�N����o�^���� */
			to->Init(taskname_);
			/* �V�X�e���ɓo�^������ */
			Tasksystem->Add(to);
			return to;
		}
	}
	return nullptr;
}
/*�^�X�N���Ԃ��܂�*/
std::pair<std::string,std::string> TaskObject::getTaskname()const
{
	return this->taskname;
}
/*�������������s���܂�*/
bool TaskObject::Init(std::pair<std::string, std::string>* taskname_)
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
/*�I�u�W�F�N�g���������܂�*/
bool TaskObject::Kill()
{
	this->KillCount();
	if (this->getKillcount() > 0)
	{
		return true;
	}
	return false;
}
/*kill�̃J�E���^��Ԃ��܂�*/
int  TaskObject::getKillCounter()
{
	return this->getKillcount();
}
/*�O���[�v���E�^�X�N�����Z�b�g���܂� */
void TaskObject::setTaskName(std::pair<std::string, std::string>& taskname_)
{
	this->taskname = taskname_;
}
