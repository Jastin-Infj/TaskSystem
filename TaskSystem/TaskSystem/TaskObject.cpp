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
/*�X�V�������s���܂�*/
void TaskObject::Update()
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
void TaskObject::setTaskName(const std::pair<std::string, std::string>& taskname_)
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
/*�`��D�揇�ʂ�ݒ肵�܂�*/
void TaskObject::setDrawOrder(float order_)
{
	this->order = order_;
}
/*�`��D�揇�ʂ�Ԃ��܂�*/
const float TaskObject::getDrawOrder()const
{
	return this->order;
}
/*�I�u�W�F�N�g�������Ƀ^�X�N����ݒ肵�܂�*/
bool TaskObject::CreatedObjectInit(const std::pair<std::string, std::string>& taskname_)
{
	//�󔒂̖��O������ꍇ
	if (taskname_.first == "" || taskname_.second == "")
	{
		return false;
	}
	this->setTaskName(taskname_);
	this->setDrawOrder(1.0f);
	return true;
}
/*�^�X�N�����������[�h�ƈ�v���Ă��邩��Ԃ��܂�*/
bool TaskObject::isTasknameSecond(const std::string& taskname_)const
{
	return this->taskname.second == taskname_ ? true : false;
}