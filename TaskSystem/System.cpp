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
void System::Add(TaskObject::SP object)
{
	
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
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it)->getKillCounter() == 0)
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
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it)->getKillCounter() == 0)
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
		/*��������Ă��Ȃ��ꍇ*/
		if ((*it)->getKillCounter() == 0)
		{
			(*it)->Render();
		}
	}
}
/*�o�^���Ă���I�u�W�F�N�g�̏����ł��邩���`�F�b�N���܂�*/
void System::Destory()
{
	auto it = this->taskobjects.begin();
	while(it != this->taskobjects.end())
	{
		if ((*it))
		{
			if ((*it)->getKillCounter() > 0)
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
}
template<typename T>
std::vector<std::pair<std::pair<std::string, std::string>, std::shared_ptr<T>>> System::GetTasks(std::pair<std::string, std::string> taskname_)  
{
	std::vector<std::pair<std::pair<std::string, std::string>, std::shared_ptr<T>>> searchObjects;
	if (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it).second != nullptr)
		{
			if ((*it).second->getTaskname() == taskname_)
			{
				searchObjects.push_back((*it).second);
			}
			++it;
		}
		else
		{
			++it;
		}
	}
	return searchObjects;
}