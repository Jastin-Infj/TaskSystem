#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "TaskObject.h"

///<summary>
///
///</summary>
///<returns>
///
///</returns>

class System
{
public:
	typedef std::shared_ptr<System> SP;


	///<summary>
	///�R���X�g���N�^
	///</summary>
	System();

	
	///<summary>
	///�f�X�g���N�^
	///</summary>
	~System();

	
	///<summary>
	///�^�X�N�V�X�e���̍X�V����
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void UpDate();


	///<summary>
	///�I�u�W�F�N�g���V�X�e���ɉ��o�^���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Add(std::pair<std::pair<std::string, std::string>, TaskObject::SP>*);


	///<summary>
	///�o�^���Ă���I�u�W�F�N�g�̃^�X�N����\�����܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void TasknameOutput()const;


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g��S���������s���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void TaskObjectDelete();
	

	///<summary>
	///�^�X�N���E�O���[�v�����������āA�I�u�W�F�N�g�P�̂��擾���܂�
	///</summary>
	template <class T>
	std::shared_ptr<T> GetTask(std::pair<std::string, std::string>& taskname_)
	{
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
		{
			if ((*it).second != nullptr)
			{
				if ((*it).second->getTaskname() == taskname_)
				{
					return std::static_pointer_cast<T>((*it).second);
				}
			}
		}
		return nullptr;
	}


	///<summary>
	///�^�X�N���E�O���[�v�����������āA�I�u�W�F�N�g�������擾���܂�
	///</summary>
	template<class T>
	std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(std::pair<std::string, std::string> taskname_)
	{
		std::shared_ptr<std::vector<std::shared_ptr<T>>> searchObjects = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
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

private:
	std::vector<std::pair<std::pair<std::string,std::string>,TaskObject::SP>> taskobjects;			//�o�^���Ă���I�u�W�F�N�g
	std::vector<std::pair<std::pair<std::string, std::string>, TaskObject::SP>> addobjects;			//�o�^�\��̃I�u�W�F�N�g


	///<summary>
	///�o�^�\��̃I�u�W�F�N�g��o�^���܂�
	///<summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void TaskApplication();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̍X�V�������s���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void T_UpDate();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̕`�揈�����s���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void T_Render();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̏������s���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void T_Destory();


	///<summary>
	///�o�^�\��̃I�u�W�F�N�g�����݂��邩�𔻒肵�܂�
	///</summary>
	///<returns>
	///���݂��� true ���݂��Ȃ� false
	///</returns>
	bool AddObjectCheck()const;


	///<summary>
	///�o�^�I�u�W�F�N�g��������\��̃I�u�W�F�N�g���Ȃ����𔻒肵�܂�
	///</summary>
	///<returns>
	///���݂��� true ���݂��Ȃ� false
	///</returns>
	bool CheckKillTask()const;

};
extern System* Tasksystem;