#include <iostream>
#include <string>
#include "TaskObject.h"

/*�R���X�g���N�^*/
KillTaskSystem::KillTaskSystem()
{
	this->killcount = 0;
}
KillTaskSystem::~KillTaskSystem(){}
/*���ł������邱�Ƃ��˗����܂�*/
void KillTaskSystem::KillCount()
{
	this->killcount++;
}
/*���ł����邩�ǂ����𔻒肵�܂�*/
bool KillTaskSystem::KillCheck()
{
	return this->killcount > 0 ? true : false;
}
/*�L���J�E���^�[��Ԃ��܂�*/
int  KillTaskSystem::getKillcount()const
{
	return this->killcount;
}

/*�R���X�g���N�^*/
TaskObject::TaskObject()
{
	this->setNextTask(true);
	this->setPause(false);

	std::cout << "TaskObject()" << std::endl;
}
/*�f�X�g���N�^*/
TaskObject::~TaskObject()
{
	std::cout << this->getTaskname().second <<"~TaskObject()" << std::endl;
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
void TaskObject::Kill()
{
	this->KillCount();
}
/*kill�̃J�E���^��Ԃ��܂�*/
int  TaskObject::getKillCounter()const
{
	return this->getKillcount();
}
/*����̃^�X�N�������ł��邩��Ԃ��܂�*/
bool TaskObject::getNextTask()const
{
	return this->NextTask;
}
/*�O���[�v���E�^�X�N�����Z�b�g���܂� */
void TaskObject::setTaskName(std::pair<std::string, std::string>& taskname_)
{
	this->taskname = taskname_;
}
/*���񐶐��o����t���O��ݒ肵�܂�*/
void TaskObject::setNextTask(const bool flag)
{
	this->NextTask = flag;
}
/*�|�[�Y�ݒ���s���܂�*/
void TaskObject::setPause(const bool flag)
{
	this->isPause = flag;
}
/*�|�[�Y�t���O��Ԃ��܂�*/
bool TaskObject::getisPause()const
{
	return this->isPause;
}
/* �������g�̃I�u�W�F�N�g��Ԃ��܂� */
std::pair<std::pair<std::string, std::string>, TaskObject::SP> TaskObject::getObjectMe(const TaskObject::SP& obj)const
{
	std::pair<std::pair<std::string,std::string>,TaskObject::SP> object;
	object.first = this->taskname;
	object.second = obj;
	return object;
}
