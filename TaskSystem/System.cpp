#include "System.h"
#include <string>
/*�R���X�g���N�^*/
KillSystem::KillSystem()
{
	this->killcount = 0;
}
KillSystem::~KillSystem() {}
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
System::System()
{
	std::cout << "System" << std::endl;
}
/*�f�X�g���N�^*/
System::~System()
{
	std::cout << "~System" << std::endl;
}
/*�I�u�W�F�N�g���V�X�e���ɓo�^���܂�*/
void System::Add(TaskObject::SP object)
{
	this->taskobjects.push_back(object);
}
/*�o�^���Ă���I�u�W�F�N�gVector��Ԃ��܂�*/
std::vector<TaskObject::SP> System::getTaskObjects()const
{
	return this->taskobjects;
}
/*�o�^���Ă���I�u�W�F�N�g�̃^�X�N����Ԃ��܂�*/
void System::TasknameOutput()const
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->getKillcount() == 0)
		{
			std::cout << (*it)->getTaskname() << std::endl;
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̍X�V�������s���܂�*/
void System::UpDate()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->getKillcount() == 0)
		{
			(*it)->UpDate();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̕`�揈�����s���܂�*/
void System::Render()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->getKillcount() == 0)
		{
			(*it)->Render();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̏����ł��邩���`�F�b�N���܂�*/
void System::Destory()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->KillCheck())
		{
			std::cout << &it << std::endl;
			delete &it;
			
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̑S�������s���܂�*/
void System::TaskObjectDelete()
{
	auto it = this->taskobjects.begin();
	while (it != this->taskobjects.end())
	{
		this->taskobjects.erase(it);
		it = this->taskobjects.begin();
	}
}