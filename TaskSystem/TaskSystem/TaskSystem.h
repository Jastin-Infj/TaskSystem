#pragma once

/// <summary>
/// @file  TaskSystem.h
/// @brief �I�u�W�F�N�g�̐����폜���Ȍ��ɍs����V�X�e��
/// </summary>


#include <iostream>
#include <vector>
#include <memory>

#include "TaskObject.h"


/// <summary>
/// 
/// </summary>
class TaskSystem
{
public:
	typedef std::shared_ptr<TaskSystem> SP;


	///<summary>
	///�R���X�g���N�^
	///</summary>
	TaskSystem();


	///<summary>
	///�f�X�g���N�^
	///</summary>
	~TaskSystem();


	///<summary>
	///�^�X�N�V�X�e���̍X�V����
	///</summary>
	void Update();


	/// <summary>
	/// �I�u�W�F�N�g���^�X�N�V�X�e���ɓo�^���܂�
	/// </summary>
	/// <param name="createobject">
	/// @param [name] �o�^�������I�u�W�F�N�g
	/// </param>
	void Add(const TaskObject::SP& createobject);


	///<summary>
	///�`�揇�ʂ�ݒ肵�܂�
	///</summary>
	void setOrder();


	///<summary>
	///�o�^���Ă���I�u�W�F�N�g�̃^�X�N����\�����܂�
	///</summary>
	void TasknameOutput()const;


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g��S���������s���܂�
	///</summary>
	void TaskObjectDelete();


	/// <summary>
	/// �^�X�N���E�O���[�v�����������āA�I�u�W�F�N�g�P�̂��擾���܂�
	/// </summary>
	/// <param name="taskname_">
	/// @param[name]�������[�h
	/// </param>
	/// <returns>
	/// �������[�h�ƈ�v�����X�}�[�g�|�C���^
	/// </returns>
	template <class T>
	std::shared_ptr<T> GetTask(const std::pair<std::string, std::string>& taskname_)
	{
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
		{
			if ((*it).second != nullptr)
			{
				if ((*it).second->getTaskname() == taskname_)
				{
					std::weak_ptr<T> temp = std::static_pointer_cast<T>((*it).second);
					return temp.lock();
				}
			}
		}
		return nullptr;
	}


	/// <summary>
	/// �O���[�v�����������āA�I�u�W�F�N�g�P�̂��擾���܂�
	/// </summary>
	/// <param name="groupname_">
	/// ��������O���[�v��
	/// </param>
	/// <returns>
	/// �O���[�v������v�����X�}�[�g�|�C���^
	/// </returns>
	template <class T>
	std::shared_ptr<T> GetTask_GroupName(const std::string& groupname_)
	{
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
		{
			if ((*it).second != nullptr)
			{
				if ((*it).second->getTaskname().first == groupname_)
				{
					std::weak_ptr<T> temp = std::static_pointer_cast<T>((*it).second);
					return temp.lock();
				}
			}
		}
		return nullptr;
	}


	/// <summary>
	/// �^�X�N�����������āA�I�u�W�F�N�g�P�̂��擾���܂�
	/// </summary>
	/// <param name="taskname_">
	/// ��������^�X�N��
	/// </param>
	/// <returns>
	/// ��v�����I�u�W�F�N�g�̃X�}�[�g�|�C���^
	/// </returns>
	template <class T>
	std::shared_ptr<T> GetTask_TaskName(const std::string& taskname_)
	{
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
		{
			if ((*it).second != nullptr)
			{
				if ((*it).second->getTaskname().second == taskname_)
				{
					std::weak_ptr<T> temp = std::static_pointer_cast<T>((*it).second);
					return temp.lock();
				}
			}
		}
		return nullptr;
	}


	/// <summary>
	///�^�X�N���E�O���[�v�����������āA�I�u�W�F�N�g�������擾���܂�
	/// </summary>
	/// <param name="taskname_">
	/// �����������i�O���[�v���E�^�X�N���j
	/// </param>
	/// <returns>
	/// ��v�����I�u�W�F�N�g�S��
	/// </returns>
	template<class T>
	std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(const std::pair<std::string, std::string>& taskname_)
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
		std::weak_ptr<std::vector<std::shared_ptr<T>>> temp = searchObjects;
		return temp.lock();
	}


	/// <summary>
	/// �O���[�v�����������āA�I�u�W�F�N�g�������擾���܂�
	/// </summary>
	/// <param name="groupname_">
	/// �����������O���[�v��
	/// </param>
	/// <returns>
	/// ��v�����I�u�W�F�N�g�S��
	/// </returns>
	template<class T>
	std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks_GroupName(const std::string& groupname_)
	{
		std::shared_ptr<std::vector<std::shared_ptr<T>>> searchObjects = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
		{
			if ((*it).second != nullptr)
			{
				if ((*it).second->getTaskname().first == groupname_)
				{
					searchObjects->push_back(std::static_pointer_cast<T>((*it).second));
				}
			}
		}
		std::weak_ptr<std::vector<std::shared_ptr<T>>> temp = searchObjects;
		return temp.lock();
	}


	/// <summary>
	/// �^�X�N�����������āA�I�u�W�F�N�g�������擾���܂�
	/// </summary>
	/// <param name="taskname_">
	/// �����������^�X�N��
	/// </param>
	/// <returns>
	/// ��v�����I�u�W�F�N�g�S��
	/// </returns>
	template<class T>
	std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks_TaskName(const std::string& taskname_)
	{
		std::shared_ptr<std::vector<std::shared_ptr<T>>> searchObjects = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
		{
			if ((*it).second != nullptr)
			{
				if ((*it).second->getTaskname().second == taskname_)
				{
					searchObjects->push_back(std::static_pointer_cast<T>((*it).second));
				}
			}
		}
		std::weak_ptr<std::vector<std::shared_ptr<T>>> temp = searchObjects;
		return temp.lock();
	}

	/// <summary>
	/// �A�v���P�[�V��������܂�
	/// </summary>
	void Application_Exit()const;

private:
	///<summary>
	///�o�^���Ă���I�u�W�F�N�g
	///</summary>
	std::vector<std::pair<std::pair<std::string, std::string>, TaskObject::SP>> taskobjects;


	///<summary>
	///�o�^�\��̃I�u�W�F�N�g
	///</summary>
	std::vector<std::pair<std::pair<std::string, std::string>, TaskObject::SP>> addobjects;


	///<summary>
	///�`�揇�D�揇��
	///</summary>
	std::vector<DrawOrder> orders;


	///<summary>
	///�o�^�\��̃I�u�W�F�N�g��o�^���܂�
	///<summary>
	void TaskApplication();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̍X�V�������s���܂�
	///</summary>
	void T_UpDate();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̕`�揈�����s���܂�
	///</summary>
	void T_Render();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̏������s���܂�
	///</summary>
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
extern TaskSystem* taskSystem;		//�^�X�N�V�X�e���ɃA�N�Z�X�p�ϐ�