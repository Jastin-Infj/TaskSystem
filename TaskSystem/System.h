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

///<summary>
///�^�X�N�����ł�����\����
///</summary>
struct KillSystem
{
	///�����o�ϐ�

	int killcount;

	///�����o�֐�

	///<summary>
	///�R���X�g���N�^
	///</summary>
	KillSystem();


	///<summary>
	///�f�X�g���N�^
	///</summary>
	~KillSystem();


	///<summary>
	///�I�u�W�F�N�g�̏����˗������܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Kill();


	///<summary>
	///���ł����邩�ǂ����𔻒肵�܂�
	///</summary>
	///<returns>
	///���ł�����@true : ���ł��Ȃ� false
	///</returns>
	bool KillCheck();


	///<summary>
	///killcount��Ԃ��܂�
	///</summary>
	int getKillcount()const;
};


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

private:
	std::vector<TaskObject::SP> taskobjects;	//�o�^���Ă���I�u�W�F�N�g
};
extern System* Tasksystem;