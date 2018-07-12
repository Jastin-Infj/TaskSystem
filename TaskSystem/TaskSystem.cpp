#include "TaskSystem.h"
#include <iostream>
#include <string>

/*�R���X�g���N�^*/
TaskSystem::TaskSystem()
{
	std::cout << "TaskSystem" << std::endl;
}
/*�f�X�g���N�^*/
TaskSystem::~TaskSystem()
{
	this->TaskObjectDelete();
	std::cout << "~TaskSystem" << std::endl;
}
/*�^�X�N�V�X�e���̍X�V����*/
void TaskSystem::UpDate()
{
	this->T_UpDate();
	this->T_Render();
	if (this->AddObjectCheck() || this->CheckKillTask())
	{
		/*�o�^�\��̃^�X�N��o�^����*/
		this->TaskApplication();
		/*�폜�\��̃^�X�N���폜����*/
		this->T_Destory();
	}
}
/*�I�u�W�F�N�g���V�X�e���ɉ��o�^���܂�*/
void TaskSystem::Add(const TaskObject::SP& addobject)
{
	std::pair<std::pair<std::string, std::string>, TaskObject::SP> object;
	object.first = addobject->getTaskname();
	object.second = addobject;
	this->addobjects.push_back(object);
}
/*�o�^�\��̃I�u�W�F�N�g��o�^���܂�*/
void TaskSystem::TaskApplication()
{
	for (auto it = this->addobjects.begin(); it != this->addobjects.end(); ++it)
	{
		std::pair<std::pair<std::string, std::string>, TaskObject::SP> addobject;
		addobject = (*it);

		/*����͂������珈��*/
		if (addobject.second->getNextTask())
		{
			this->taskobjects.push_back(addobject);
		}
	}
	/*�o�^�\�肵���I�u�W�F�N�g�f�[�^��S�ď�������*/
	addobjects.clear();
}
/*�o�^����Ă���I�u�W�F�N�g�����邩�𔻒肵�܂�*/
bool TaskSystem::AddObjectCheck()const
{
	return this->addobjects.size() > 0;
}
/*�o�^�I�u�W�F�N�g�ɏ�������I�u�W�F�N�g���Ȃ����𔻒肵�܂�*/
bool TaskSystem::CheckKillTask()const
{
	for (int i = 0; i < this->addobjects.size(); ++i)
	{
		if (this->taskobjects[i].second->getKillCounter() > 0)
		{
			return true;
		}
	}
	return false;
}
/*�o�^���Ă���I�u�W�F�N�g�̃^�X�N����Ԃ��܂�*/
void TaskSystem::TasknameOutput()const
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it).second->getKillCounter() == 0 && !(*it).second->getisPause())
		{
			std::cout << (*it).second->getTaskname().second << std::endl;
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̍X�V�������s���܂�*/
void TaskSystem::T_UpDate()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it).second->getKillCounter() == 0 && !(*it).second->getisPause())
		{
			(*it).second->UpDate();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̕`�揈�����s���܂�*/
void TaskSystem::T_Render()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it).second->getKillCounter() == 0 && !(*it).second->getisPause())
		{
			(*it).second->Render();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̏����ł��邩���`�F�b�N���܂�*/
void TaskSystem::T_Destory()
{
	auto it = this->taskobjects.begin();
	while(it != this->taskobjects.end())
	{
		if ((*it).second)
		{
			if ((*it).second->getKillCounter() > 0)
			{
				this->taskobjects.erase(it);
				/*����\��̃^�X�N��ǉ����܂�*/
				this->TaskApplication();			
				it = this->taskobjects.begin();
			}
			else
			{
				++it;
			}
		}
		else
		{
			++it;
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̑S�������s���܂�*/
void TaskSystem::TaskObjectDelete()
{
	{
		auto it = this->taskobjects.begin();
		while (it != this->taskobjects.end())
		{
			this->taskobjects.erase(it);
			it = this->taskobjects.begin();
		}
	}
	
	{
		auto it = this->addobjects.begin();
		while (it != this->addobjects.end())
		{
			this->addobjects.erase(it);
			it = this->taskobjects.begin();
		}
	}
}