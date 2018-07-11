#include "System.h"
#include <string>

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
void System::Add(std::pair<std::pair<std::string,std::string>,TaskObject::SP>* addobject)
{
	this->taskobjects.push_back(*addobject);
}
/* �o�^���Ă���I�u�W�F�N�g�^�X�N��S�ĕԂ��܂� */

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
void System::UpDate()
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
void System::Render()
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
void System::Destory()
{
	auto it = this->taskobjects.begin();
	while(it != this->taskobjects.end())
	{
		if ((*it).second)
		{
			if ((*it).second->getKillCounter() > 0)
			{
				this->taskobjects.erase(it);
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
	auto it = this->taskobjects.begin();
	while (it != this->taskobjects.end())
	{
		this->taskobjects.erase(it);
		it = this->taskobjects.begin();
	}
}
/*�O���[�v���E�^�X�N������I�u�W�F�N�g�̎擾�����܂�*/
template <typename T>
std::shared_ptr<T> System::GetTask(std::pair<std::string, std::string>* taskname_)
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it).second != nullptr)
		{
			//TaskObject::SP
			if ((*it).second->getTaskname() == taskname_)
			{
				return (*it).second;
			}
			++it;
		}
		else
		{
			++it;
		}
	}
	return nullptr;
}
template<class T>
std::shared_ptr<std::vector<std::shared_ptr<T>>> System::GetTasks(std::pair<std::string, std::string> taskname_)  
{
	std::shared_ptr<std::vector<std::shared_ptr<T>>> searchObjects = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
	if (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it).second != nullptr)
		{
			if ((*it).second->getTaskname() == taskname_)
			{
				searchObjects->push_back(std::static_pointer_cast<T>((*it).second));
			}
		}
	}
	return searchObjects;
}