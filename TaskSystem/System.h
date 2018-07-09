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
	///�I�u�W�F�N�g�̃A�h���X�l���V�X�e���ɓo�^���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Add(TaskObject::SP);

	///<summary>
	///�I�u�W�F�N�g�̃O���[�v���E�^�X�N�����V�X�e���ɓo�^���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Add(std::pair<std::string, std::string>&);


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
	///�O���[�v���E�^�X�N���œo�^���Ă���I�u�W�F�N�g���폜���܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void TaskNameDelete(std::string&,std::string&);
private:
	std::vector<std::pair<std::string, std::string>, TaskObject::SP> taskobjects;
	std::vector<std::pair<std::string, std::string>, TaskObject::SP> addobjects;

	///<summary>
	///�o�^�\��̃I�u�W�F�N�g�𓝊��p�̃I�u�W�F�N�g�ɒǉ����܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void toTaskObjects();
};
extern System* Tasksystem;