#include "TaskSystem.h"
#include "../ResourceManager/ResourceManager.h"
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
void TaskSystem::Update()
{
	if (this->AddObjectCheck() || this->CheckKillTask())
	{
		/*�o�^�\��̃^�X�N��o�^����*/
		this->TaskApplication();
		/*�폜�\��̃^�X�N���폜����*/
		this->T_Destory();
		/*�`�揇�����ւ��ĕ`�悷��*/
		this->setOrder();
	}
	this->T_UpDate();
	this->T_Render();
}
/*�I�u�W�F�N�g���V�X�e���ɉ��o�^���܂�*/
void TaskSystem::Add(const TaskObject::SP& addobject)
{
	std::pair<std::pair<std::string, std::string>, TaskObject::SP> object;
	object.first = addobject->getTaskname();
	object.second = addobject;
	this->addobjects.push_back(object);
}
/*�`��D�揇�ʂ��V�X�e���ɓo�^���܂�*/
void TaskSystem::setOrder()
{
	/*�`�揇�ʂ�ݒ肵�܂�*/
	this->orders.resize(this->taskobjects.size());
	/*�e�I�u�W�F�N�g�ɐݒ肳��Ă���D�揇�ʂ�system�ɓo�^���܂�*/
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		/*�o�^�^�X�N�ɕ`��ID��ݒ肵�܂�*/
		this->orders[i].setDrawOrderID(i);
		this->orders[i].setDrawOrder(this->taskobjects[i].second->getDrawOrder());
	}
	/*�`�揇�ɍ��킹��id��order����ёւ���*/
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		for (int j = i; j < this->taskobjects.size(); ++j)
		{
			/*�`��D�揇�ʂ̒l���r����*/
			if (this->taskobjects[i].second->getDrawOrder() > this->taskobjects[j].second->getDrawOrder())
			{
				DrawOrder temp = this->orders[i];
				this->orders[i] = this->orders[j];
				this->orders[j] = temp;
			}
		}
	}
}
/*�o�^�\��̃I�u�W�F�N�g��o�^���܂�*/
void TaskSystem::TaskApplication()
{
	for (auto it = this->addobjects.begin(); it != this->addobjects.end(); ++it)
	{
		std::pair<std::pair<std::string, std::string>, TaskObject::SP> addobject;
		addobject = (*it);

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
	for (int i = 0; i < this->taskobjects.size(); ++i)
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
			(*it).second->Update();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̕`�揈�����s���܂�*/
void TaskSystem::T_Render()
{
	for (int i = 0; i < this->taskobjects.size(); ++i)
	{
		/*�`��D�揇�ʂ���ёւ����ĕ`�悷�鏇�Ԃ�ύX����*/
		if (this->taskobjects[this->orders[i].getDrawOrderID()].second->getKillCounter() == 0 && !this->taskobjects[this->orders[i].getDrawOrderID()].second->getisPause())
		{
			this->taskobjects[this->orders[i].getDrawOrderID()].second->Render();
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
/*�A�v���P�[�V�����𗎂Ƃ��܂�*/
void TaskSystem::Application_Exit()const
{
	//System::Exit();
}