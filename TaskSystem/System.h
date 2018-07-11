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
	///�I�u�W�F�N�g���V�X�e���ɓo�^���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Add(TaskObject::SP);


	///<summary>
	///�o�^���Ă���I�u�W�F�N�gVector��Ԃ��܂�
	///</summary>
	///<returns>
	///���ݓo�^���Ă���I�u�W�F�N�gVector
	///</returns>
	std::vector<TaskObject::SP> getTaskObjects()const;


	///<summary>
	///�o�^���Ă���I�u�W�F�N�g�̃^�X�N����\�����܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void TasknameOutput()const;


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̍X�V�������s���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void UpDate();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̕`�揈�����s���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Render();


	///<summary>
	///�o�^����Ă���I�u�W�F�N�g�̏������s���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Destory();


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
	template <typename T>
	std::shared_ptr<T> GetTask(std::pair<std::string, std::string>*);


	///<summary>
	///�^�X�N���E�O���[�v�����������āA�I�u�W�F�N�g�������擾���܂�
	///</summary>
	template<typename T>
	std::vector<std::pair<std::pair<std::string, std::string>, std::shared_ptr<T>>> GetTasks(std::pair<std::string,std::string>);


private:
	std::vector<std::pair<std::pair<std::string,std::string>,TaskObject::SP>> taskobjects;	//�o�^���Ă���I�u�W�F�N�g
};
extern System* Tasksystem;