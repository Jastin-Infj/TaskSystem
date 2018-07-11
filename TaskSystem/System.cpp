#include "System.h"
#include <iostream>
#include <string>

/*�R���X�g���N�^*/
System::System()
{
	std::cout << "System" << std::endl;
}
/*�f�X�g���N�^*/
System::~System()
{
	this->TaskObjectDelete();
	std::cout << "~System" << std::endl;
}
/*�^�X�N�V�X�e���̍X�V����*/
void System::UpDate()
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
void System::Add(std::pair<std::pair<std::string,std::string>,TaskObject::SP>* addobject)
{
	this->addobjects.push_back(*addobject);
}
/*�o�^�\��̃I�u�W�F�N�g��o�^���܂�*/
void System::TaskApplication()
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
bool System::AddObjectCheck()const
{
	return this->addobjects.size() > 0;
}
/*�o�^�I�u�W�F�N�g�ɏ�������I�u�W�F�N�g���Ȃ����𔻒肵�܂�*/
bool System::CheckKillTask()const
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
void System::TasknameOutput()const
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it).second->getKillCounter() == 0)
		{
			std::cout << (*it).second->getTaskname().second << std::endl;
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̍X�V�������s���܂�*/
void System::T_UpDate()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it).second->getKillCounter() == 0)
		{
			(*it).second->UpDate();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̕`�揈�����s���܂�*/
void System::T_Render()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it).second->getKillCounter() == 0)
		{
			(*it).second->Render();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̏����ł��邩���`�F�b�N���܂�*/
void System::T_Destory()
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
void System::TaskObjectDelete()
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